#!/usr/bin/env python3
"""Convert Obsidian .md notes to styled PDFs via pandoc + xelatex."""

import re
import subprocess
import sys

CALLOUT_STYLES = {
    "info": ("📘", "Demonstração"),
    "tip": ("💡", "Dica"),
    "warning": ("⚠️", "Atenção"),
    "important": ("❗", "Importante"),
    "abstract": ("📋", "Resumo"),
    "summary": ("📝", "Resumo"),
    "note": ("📌", "Nota"),
    "quote": ("📖", "Definição"),
    "success": ("✅", "Procedimento"),
    "example": ("📂", "Exemplo"),
}


def process_obsidian_md(text: str) -> str:
    """Convert Obsidian-flavoured markdown to pandoc-compatible markdown."""
    # Remove YAML frontmatter
    text = re.sub(r'^---\n.*?\n---\n', '', text, flags=re.DOTALL)

    # Process callout blocks: > [!type] Title or > [!type]- Title (collapsible)
    lines = text.split('\n')
    result = []
    i = 0
    while i < len(lines):
        line = lines[i]
        # Detect callout start
        m = re.match(r'^>\s*\[!(\w+)\]-?\s*(.*)', line)
        if m:
            ctype = m.group(1).lower()
            custom_title = m.group(2).strip()
            _icon, default_title = CALLOUT_STYLES.get(ctype, ("", ctype.capitalize()))
            title = custom_title if custom_title else default_title

            # Collect all continuation lines (lines starting with >)
            body_lines = []
            i += 1
            while i < len(lines) and lines[i].startswith('>'):
                content = lines[i][1:].strip()  # strip the '>' prefix
                if content == '':
                    content = ''  # blank line inside callout
                body_lines.append(content)
                i += 1

            # Remove leading/trailing empty lines from body
            while body_lines and body_lines[0] == '':
                body_lines.pop(0)
            while body_lines and body_lines[-1] == '':
                body_lines.pop()

            # Build a LaTeX tcolorbox
            body_text = '\n'.join(body_lines)

            # Map callout type to color
            color_map = {
                "info": "blue!10",
                "tip": "green!10",
                "warning": "orange!10",
                "important": "red!10",
                "abstract": "cyan!10",
                "summary": "cyan!10",
                "note": "gray!10",
                "quote": "violet!10",
                "success": "green!10",
                "example": "teal!10",
            }
            frame_color_map = {
                "info": "blue!60",
                "tip": "green!60",
                "warning": "orange!60",
                "important": "red!60",
                "abstract": "cyan!60",
                "summary": "cyan!60",
                "note": "gray!60",
                "quote": "violet!60",
                "success": "green!60",
                "example": "teal!60",
            }
            bg = color_map.get(ctype, "gray!10")
            frame = frame_color_map.get(ctype, "gray!60")

            result.append('')
            result.append(f'\\begin{{tcolorbox}}[colback={bg}, colframe={frame}, title={{{title}}}, fonttitle=\\bfseries, breakable]')
            result.append('')
            result.append(body_text)
            result.append('')
            result.append('\\end{tcolorbox}')
            result.append('')
        else:
            result.append(line)
            i += 1

    text = '\n'.join(result)

    # Fix `$;` artifacts (from OCR/copy issues in the original)
    text = text.replace('$;', '$\\;')

    # Fix `\sim!\sim` -> `\sim\sim` (double negation)
    text = text.replace(r'\sim!\sim', r'\sim\!\sim')

    # Ensure \boxed works
    # Already works in LaTeX math mode

    return text


LATEX_TEMPLATE = r"""\documentclass[11pt, a4paper]{article}

% Encoding & fonts
\usepackage[utf8]{inputenc}
\usepackage[T1]{fontenc}
\usepackage{lmodern}

% Language
\usepackage[brazilian]{babel}

% Math
\usepackage{amsmath, amssymb, amsthm}

% Layout
\usepackage[margin=2.2cm]{geometry}
\usepackage{parskip}

% Colors & boxes
\usepackage[dvipsnames]{xcolor}
\usepackage[breakable, skins]{tcolorbox}

% Tables
\usepackage{booktabs}
\usepackage{longtable}
\usepackage{array}

% Links
\usepackage[colorlinks=true, linkcolor=blue!70!black, urlcolor=blue!70!black]{hyperref}

% Headers
\usepackage{fancyhdr}
\pagestyle{fancy}
\fancyhf{}
\fancyhead[L]{\small\leftmark}
\fancyhead[R]{\small\thepage}
\renewcommand{\headrulewidth}{0.4pt}

% Section styling
\usepackage{titlesec}
\titleformat{\section}{\Large\bfseries\color{blue!70!black}}{\thesection}{1em}{}[\vspace{-0.5em}\rule{\textwidth}{0.5pt}]
\titleformat{\subsection}{\large\bfseries\color{blue!50!black}}{\thesubsection}{1em}{}
\titleformat{\subsubsection}{\normalsize\bfseries\color{blue!40!black}}{\thesubsubsection}{1em}{}

% Tight list
\providecommand{\tightlist}{\setlength{\itemsep}{0pt}\setlength{\parskip}{0pt}}

% Emoji fallbacks (text mode)
\newcommand{\emojicheckmark}{$$\checkmark$$}

\begin{document}

$body$

\end{document}
"""


def convert_to_pdf(md_path: str, pdf_path: str, template_path: str):
    """Pre-process markdown and convert to PDF."""
    with open(md_path, 'r', encoding='utf-8') as f:
        raw = f.read()

    processed = process_obsidian_md(raw)

    # Write processed markdown
    proc_path = md_path.replace('.md', '_processed.md')
    with open(proc_path, 'w', encoding='utf-8') as f:
        f.write(processed)

    # Run pandoc
    cmd = [
        'pandoc', proc_path,
        '-o', pdf_path,
        '--pdf-engine=xelatex',
        f'--template={template_path}',
        '--highlight-style=tango',
        '-V', 'documentclass=article',
    ]

    result = subprocess.run(cmd, capture_output=True, text=True)
    if result.returncode != 0:
        print(f"PANDOC ERROR for {md_path}:")
        print(result.stderr)
        return False
    else:
        print(f"✅ Created: {pdf_path}")
        return True


def main():
    # Write template
    template_path = '/home/claude/template.latex'
    with open(template_path, 'w', encoding='utf-8') as f:
        f.write(LATEX_TEMPLATE)

    files = [
        ('/home/claude/cap7.md', '/home/claude/Cap_7_Algebra_das_Proposicoes.pdf'),
        ('/home/claude/cap8.md', '/home/claude/Cap_8_Metodo_Dedutivo.pdf'),
    ]

    for md, pdf in files:
        print(f"Processing {md}...")
        ok = convert_to_pdf(md, pdf, template_path)
        if not ok:
            print(f"⚠️  Failed: {md}")

if __name__ == '__main__':
    main()