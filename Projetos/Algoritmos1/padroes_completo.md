# 🧩 Padrões Fundamentais em C

---

## 1️⃣ Achar o Menor (ou Maior) Elemento de um Vetor

**Ideia:** inicializar com o primeiro elemento, depois comparar com os demais.

```c
#include <stdio.h>
int main() {
    int num[10], i, maior, menor;

    // Leitura do vetor
    for (i = 0; i < 10; i++) {
        printf("Numero: ");
        scanf("%d", &num[i]);
    }

    // Inicializa com o primeiro elemento
    maior = num[0];
    menor = num[0];

    // Compara a partir do segundo
    for (i = 1; i < 10; i++) {
        if (num[i] > maior) {
            maior = num[i];
        }
        if (num[i] < menor) {
            menor = num[i];
        }
    }

    printf("Maior: %d\n", maior);
    printf("Menor: %d\n", menor);
    return 0;
}
```

> [!tip] Padrão-chave
> - Inicializar `maior` e `menor` com `vetor[0]` (nunca com 0!)
> - Loop começa em `i = 1` (o 0 já foi usado)
> - Usar `>` para maior, `<` para menor (estritamente)

---

## 2️⃣ Bubble Sort (Ordenação por Bolha)

**Ideia:** comparar vizinhos e trocar se estiverem fora de ordem. Repetir até ordenar.

```c
#include <stdio.h>
int main() {
    int num[6], i, j, aux;

    // Leitura do vetor
    for (i = 0; i < 6; i++) {
        printf("Numero: ");
        scanf("%d", &num[i]);
    }

    // Bubble Sort
    for (i = 0; i < 5; i++) {           // rodadas (n-1)
        for (j = 0; j < 5; j++) {       // compara vizinhos
            if (num[j] > num[j + 1]) {  // fora de ordem?
                aux = num[j];           // troca com auxiliar
                num[j] = num[j + 1];
                num[j + 1] = aux;
            }
        }
    }

    // Impressão do vetor ordenado
    for (i = 0; i < 6; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");
    return 0;
}
```

> [!tip] Padrão-chave
> - Dois `for` aninhados: externo = rodadas, interno = comparações
> - `j < n-1` no interno (evita acessar `num[j+1]` fora do vetor)
> - Troca com variável auxiliar: `aux = a; a = b; b = aux;`
> - Para ordem decrescente: trocar `>` por `<` no `if`

---

## 3️⃣ MDC com Algoritmo de Euclides

**Ideia:** dividir o maior pelo menor, pegar o resto, repetir até resto ser zero.

```c
#include <stdio.h>
int main() {
    int x, y, a, b, mdc;

    printf("Digite dois numeros: ");
    scanf("%d %d", &x, &y);

    // Copia para não perder os valores originais
    a = x;
    b = y;

    // Algoritmo de Euclides
    while (b != 0) {
        int resto = a % b;
        a = b;
        b = resto;
    }
    mdc = a;

    printf("MDC(%d, %d) = %d\n", x, y, mdc);
    return 0;
}
```

> [!tip] Padrão-chave
> - Copiar os valores para `a` e `b` (preserva os originais)
> - `while (b != 0)`: repete enquanto o resto não for zero
> - A cada passo: `a` recebe `b`, `b` recebe `a % b`
> - Quando `b == 0`, o MDC está em `a`

### Exemplo passo a passo: MDC(76, 50)

| Passo | a  | b  | a % b |
|-------|----|----|-------|
| 1     | 76 | 50 | 26    |
| 2     | 50 | 26 | 24    |
| 3     | 26 | 24 | 2     |
| 4     | 24 | 2  | 0     |

→ `b == 0`, logo **MDC = 2**

---

## 4️⃣ Leitura com EOF (Final de Arquivo)

**Quando usar:** o enunciado diz "a entrada termina com EOF" ou "diversos casos de teste" sem dizer quantos.

```c
#include <stdio.h>
int main() {
    int x, y;
    while (scanf("%d %d", &x, &y) == 2) {
        // processa x e y
        printf("%d\n", x + y);
    }
    return 0;
}
```

> [!tip] Padrão-chave
> - `scanf` retorna quantos valores leu com sucesso
> - 1 variável → `== 1`, 2 variáveis → `== 2`, etc.
> - Quando a entrada acaba, `scanf` retorna `EOF` e o `while` para
> - Em Python: `while True:` com `try/except EOFError: break`

---

## 5️⃣ Leitura com N Casos de Teste

**Quando usar:** a primeira linha diz quantos casos existem.

```c
#include <stdio.h>
int main() {
    int n, i, H, M, O;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &H, &M, &O);
        // processa cada caso
    }
    return 0;
}
```

> [!tip] Padrão-chave
> - Ler `n` primeiro, depois `for (i = 0; i < n; i++)`
> - Cada iteração lê e processa UM caso
> - Em Python: `for i in range(n):`

---

## 6️⃣ Formatação com Zeros à Esquerda

**Quando usar:** saída exige formato fixo como `00:05` ou `007`.

```c
// Em C: %02d = mínimo 2 dígitos, preenche com zero
printf("%02d:%02d\n", hora, minuto);
// hora=0, minuto=5 → "00:05"
// hora=15, minuto=30 → "15:30"
```

```python
# Em Python: f-string com :02d
print(f"{hora:02d}:{minuto:02d}")
```

> [!tip] Padrão-chave
> - `%02d` → 2 dígitos com zero à esquerda
> - `%03d` → 3 dígitos com zero à esquerda
> - O número depois do `0` é a largura mínima

---

## 7️⃣ Impressão de Padrões (Asteriscos Centralizados)

**Quando usar:** exercícios que pedem "desenhar" formas com caracteres.

```c
// Triângulo centralizado de largura N (N ímpar)
// k = quantidade de asteriscos na linha
for (k = 1; k <= N; k += 2) {
    // espaços antes
    for (j = 0; j < (N - k) / 2; j++) {
        printf(" ");
    }
    // asteriscos
    for (j = 0; j < k; j++) {
        printf("*");
    }
    printf("\n");
}
```

> [!tip] Padrão-chave
> - Fórmula de centralização: `espaços = (largura_total - largura_linha) / 2`
> - Triângulo crescente: `k` vai de 1 até N pulando de 2
> - Triângulo decrescente: `k` vai de N até 1 pulando de 2
> - Cada tipo de caractere precisa de um `for` interno separado

---

## 8️⃣ Acumulador (Soma de Elementos)

**Quando usar:** somar, contar ou acumular valores dentro de um loop.

```c
int soma = 0;    // SEMPRE inicializar com 0
int contador = 0;

for (i = 0; i < n; i++) {
    soma += vetor[i];        // soma acumula
    if (vetor[i] > 0) {
        contador++;          // conta quantos positivos
    }
}
```

> [!tip] Padrão-chave
> - Soma: inicializar com `0`, usar `+=`
> - Contador: inicializar com `0`, usar `++`
> - Produto: inicializar com `1`, usar `*=`
> - Declarar e inicializar ANTES do loop

---

## 9️⃣ Flag de Controle

**Quando usar:** precisa verificar se uma condição aconteceu em algum momento do loop.

```c
int existe = 0;  // começa "falso"

for (i = 0; i < total; i++) {
    if (contas[i].numero == num_novo) {
        existe = 1;  // encontrou!
        break;       // pode parar de procurar
    }
}

if (existe == 0) {
    printf("Nao encontrado\n");
} else {
    printf("Ja existe\n");
}
```

> [!tip] Padrão-chave
> - Inicializar com `0` (falso) ANTES do loop
> - Mudar para `1` (verdadeiro) quando a condição é satisfeita
> - **Resetar** para `0` se a verificação for repetida (dentro de um menu, por exemplo)
> - `break` após encontrar é opcional mas eficiente

---

## 🔟 Menu com do/while + switch

**Quando usar:** programas interativos com opções que se repetem.

```c
int opcao;
do {
    printf("1 - Opcao A\n");
    printf("2 - Opcao B\n");
    printf("3 - Sair\n");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            // ação A
            break;
        case 2:
            // ação B
            break;
        case 3:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida!\n");
            break;
    }
} while (opcao != 3);
```

> [!tip] Padrão-chave
> - `do/while` garante que o menu aparece pelo menos uma vez
> - Cada `case` termina com `break` (senão "cai" no próximo)
> - `default` trata opções inválidas
> - A condição de saída fica no `while`

---

## 1️⃣1️⃣ Struct + Vetor de Structs

**Quando usar:** armazenar entidades com múltiplos campos (aluno, conta, produto).

```c
#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[100];
    int numero;
    float saldo;
} Conta;

int main() {
    Conta contas[15];  // vetor de structs
    int total = 0;

    // Cadastrar
    contas[total].numero = 101;
    scanf("%s", contas[total].nome);  // string: sem &
    scanf("%f", &contas[total].saldo); // float: com &
    total++;

    // Acessar
    printf("Nome: %s\n", contas[0].nome);
}
```

> [!tip] Padrão-chave
> - Acesso: `vetor[indice].campo` (nunca `campo.vetor[indice]`)
> - `scanf` de string: **sem** `&` → `scanf("%s", contas[i].nome)`
> - `scanf` de int/float: **com** `&` → `scanf("%d", &contas[i].numero)`
> - `total` controla quantas posições estão preenchidas
> - Loops sempre usam `total` como limite, não o tamanho do vetor

---

## 1️⃣2️⃣ Remoção por Substituição do Último

**Quando usar:** remover um elemento de um vetor sem ordenação obrigatória.

```c
// Encontrar o índice a remover (ex: menor saldo)
int idx = 0;
for (i = 1; i < total; i++) {
    if (vetor[i] < vetor[idx]) {
        idx = i;
    }
}

// Substituir pelo último e reduzir total
vetor[idx] = vetor[total - 1];
total--;
```

> [!tip] Padrão-chave
> - Copiar o último elemento para a posição removida
> - Decrementar `total`
> - Muito mais simples que deslocar todos os elementos
> - Funciona quando a ordem do vetor não importa

---

## 1️⃣3️⃣ Comparação de Strings com strcmp

**Quando usar:** comparar nomes, palavras ou qualquer texto em C.

```c
#include <string.h>

// strcmp retorna:
//   0  → strings IGUAIS
//   <0 → primeira vem antes (alfabeticamente)
//   >0 → primeira vem depois

if (strcmp(nome1, nome2) == 0) {
    printf("Nomes iguais!\n");
}
```

> [!tip] Padrão-chave
> - Nunca comparar strings com `==` em C (isso compara endereços!)
> - `strcmp` retorna `0` quando são iguais (parece invertido, mas é assim)
> - Precisa de `#include <string.h>`
> - Em Python é simples: `if nome1 == nome2:`

---

## 1️⃣4️⃣ Checklist de scanf e printf

**Quando usar:** sempre que escrever `scanf` ou `printf` em C.

### scanf — precisa de `&`?

```c
int x;       scanf("%d", &x);      // int: com &
float f;     scanf("%f", &f);      // float: com &
double d;    scanf("%lf", &d);     // double: com &, e %lf (não %f)
char s[50];  scanf("%s", s);       // string: SEM &
```

> [!warning] Por que string não usa `&`?
> O nome de um array em C já é um endereço (ponteiro pro primeiro elemento). Então `s` já é o que o `scanf` precisa. Colocar `&s` não causa erro, mas é redundante e confuso.

### printf — qual formato usar?

```c
int x = 42;       printf("%d", x);       // int
float f = 3.14;   printf("%.2f", f);     // float com 2 casas
double d = 3.14;  printf("%.2lf", d);    // double com 2 casas
char s[] = "oi";  printf("%s", s);       // string
```

> [!tip] Padrão-chave
> - `scanf` de `double` → `%lf` (obrigatório o `l`)
> - `printf` de `double` → `%lf` ou `%f` (ambos funcionam)
> - `%.2` controla casas decimais (`.2` = duas casas)
> - Nenhum `printf` usa `&`

---

## 1️⃣5️⃣ Busca Linear (em Vetor ou Matriz)

**Quando usar:** verificar se um valor existe num vetor ou matriz e encontrar sua posição.

### Em vetor:

```c
int existe = 0;
for (i = 0; i < n; i++) {
    if (vetor[i] == x) {
        existe = 1;
        printf("Posição: %d\n", i);
    }
}
if (existe == 0) {
    printf("Não encontrado.\n");
}
```

### Em matriz:

```c
int existe = 0;
for (i = 0; i < linhas; i++) {
    for (j = 0; j < colunas; j++) {
        if (matriz[i][j] == x) {
            existe = 1;
            printf("Posição: [%d][%d]\n", i, j);
        }
    }
}
if (existe == 0) {
    printf("Não encontrado.\n");
}
```

> [!tip] Padrão-chave
> - Usa flag (padrão 9) para saber se encontrou
> - A verificação `existe == 0` vem **depois** do loop, nunca dentro
> - Se quiser só a primeira ocorrência, adicione `break` após encontrar
> - Para matriz: mesma lógica, só com dois `for` aninhados

---

## 1️⃣6️⃣ Construção de Matriz a partir da Linha Anterior

**Quando usar:** cada elemento depende de valores da linha anterior (Triângulo de Pascal, programação dinâmica).

```c
int n, i, j, tri[n][n];
for (i = 0; i < n; i++) {
    for (j = 0; j <= i; j++) {
        if (j == 0 || j == i) {
            tri[i][j] = 1;           // bordas sempre 1
        } else {
            tri[i][j] = tri[i-1][j-1] + tri[i-1][j];  // soma dos dois acima
        }
        printf("%d ", tri[i][j]);
    }
    printf("\n");
}
```

> [!tip] Padrão-chave
> - Tratar as **bordas** separadamente (primeiro e último elemento)
> - Elementos do meio usam `[i-1][j-1]` e `[i-1][j]`
> - O `for` interno vai até `j <= i` (cada linha tem i+1 elementos)
> - Separar lógica (calcular) da apresentação (imprimir)

---


## 🔗 Resumo Geral

| # | Padrão | Estrutura | Quando Usar |
|---|--------|-----------|-------------|
| 1 | Menor/Maior | `for` + `if` | Achar extremos |
| 2 | Bubble Sort | `for` aninhado | Ordenar vetor |
| 3 | MDC Euclides | `while (b != 0)` | Divisor comum |
| 4 | EOF | `while(scanf()==N)` | Entrada sem fim definido |
| 5 | N casos | `for(i=0;i<n;i++)` | Entrada com quantidade |
| 6 | Zeros à esquerda | `%02d` | Formato fixo |
| 7 | Padrão visual | `for` aninhado | Desenhar com caracteres |
| 8 | Acumulador | `soma += x` | Somar/contar no loop |
| 9 | Flag | `existe = 0/1` | Verificar condição no loop |
| 10 | Menu | `do/while + switch` | Programa interativo |
| 11 | Struct | `typedef struct` | Entidade com campos |
| 12 | Remoção | `Substituir pelo último` | Excluir de vetor |
| 13 | strcmp | `strcmp(a,b) == 0` | Comparar strings |
| 14 | scanf/printf | `&` e `%` | Toda leitura e impressão |
| 15 | Busca Linear | `for` + flag | Procurar valor em vetor/matriz |
| 16 | Matriz dependente | `[i-1][j-1] + [i-1][j]` | Triângulo de Pascal, prog. dinâmica |