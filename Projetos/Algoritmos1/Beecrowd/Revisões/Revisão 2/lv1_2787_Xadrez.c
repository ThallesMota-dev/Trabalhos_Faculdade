/* Etapa 1 — Análise do Enunciado
Tabuleiro de xadrez com L linhas e C colunas. A casa (1,1) — canto superior esquerdo — é sempre branca. As cores se alternam. Queremos saber a cor do canto inferior direito (L, C).
Saída: 1 se branca, 0 se preta.
Etapa 2 — Descobrindo o padrão
Olha a imagem do tabuleiro e pensa: num tabuleiro de xadrez, o que determina se uma casa é branca ou preta? Tem a ver com a posição (linha e coluna) dela.
Tenta preencher mentalmente:

(1,1) = branca, (1,2) = preta, (1,3) = branca...
(2,1) = preta, (2,2) = branca...

Agora soma linha + coluna de cada casa:

(1,1) → 1+1 = 2 (par) → branca
(1,2) → 1+2 = 3 (ímpar) → preta
(2,1) → 2+1 = 3 (ímpar) → preta
(2,2) → 2+2 = 4 (par) → branca

Percebe o padrão? Quando L + C é par ou ímpar, o que acontece com a cor?
Confere com os exemplos:

L=6, C=9 → 6+9 = ?  → saída 0 (preta)
L=8, C=8 → 8+8 = ?  → saída 1 (branca)
L=5, C=91 → 5+91 = ? → saída 1 (branca)*/

#include <stdio.h>
int main() {
	int L, C, soma; /* L: linhas, C: colunas, soma: L + C */
	scanf("%d", &L); /* leitura da quantidade de linhas */
	scanf("%d", &C); /* leitura da quantidade de colunas */
	soma = L + C; /* cálculo da soma */
	if (soma % 2 == 0) { /* se a soma for par, a casa é branca */
		printf("1");
	} else { /* se a soma for ímpar, a casa é preta */
		printf("0");
	}	
	return 0;
}