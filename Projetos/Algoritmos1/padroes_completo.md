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

1️⃣7️⃣ Ordenação Rápida com qsort

Quando usar: Bubble Sort estoura o tempo (N > ~10.000). qsort é O(n log n).

c#include <stdlib.h>

// Função de comparação: crescente
int crescente(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Função de comparação: decrescente
int decrescente(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

// Uso:
qsort(vetor, tamanho, sizeof(int), crescente);
qsort(vetor, tamanho, sizeof(int), decrescente);


[!tip] Padrão-chave


qsort(vetor, tamanho, sizeof(elemento), funcao)
A função de comparação recebe dois ponteiros void*
Retorna negativo (a antes), zero (iguais), positivo (b antes)
Inverter a subtração (b - a em vez de a - b) muda a ordem
Precisa de #include <stdlib.h>





1️⃣8️⃣ Separar String com strtok

Quando usar: ler uma linha com vários nomes/palavras separados por espaço e guardá-los num vetor de strings.

c#include <string.h>

char linha[10001];
char nomes[200][51];
int total = 0;

fgets(linha, 10001, stdin);  // lê a linha inteira com espaços

char *token = strtok(linha, " \n");  // corta no primeiro espaço
while (token != NULL) {
    strcpy(nomes[total], token);  // copia o pedaço pro vetor
    total++;
    token = strtok(NULL, " \n");  // próximo pedaço
}


[!tip] Padrão-chave


fgets lê a linha inteira (diferente de scanf("%s") que para no espaço)
Primeira chamada: strtok(linha, " \n") — passa a string
Chamadas seguintes: strtok(NULL, " \n") — NULL = continua cortando a mesma
Retorna NULL quando não tem mais pedaços
Precisa de strcpy pra copiar — em C não dá pra copiar strings com =





1️⃣9️⃣ Buscar Substring com strstr

Quando usar: verificar se uma sequência de caracteres consecutivos aparece dentro de outra string.

c#include <string.h>

// strstr retorna ponteiro pra onde encontrou, ou NULL se não encontrou
if (strstr(texto, busca) != NULL) {
    printf("Encontrado!\n");
} else {
    printf("Nao encontrado.\n");
}


[!tip] Padrão-chave


strstr(palheiro, agulha) — procura agulha dentro do palheiro
Retorna NULL se não encontrou
Busca caracteres consecutivos (substring), não espalhados (subsequência)
Diferente de strcmp que compara strings inteiras — strstr procura dentro





2️⃣0️⃣ Verificar Subsequência em String

Quando usar: verificar se os caracteres de S aparecem em D na mesma ordem, mas não necessariamente consecutivos.

cint j = 0;  // índice em S
for (int i = 0; D[i] != '\0' && S[j] != '\0'; i++) {
    if (D[i] == S[j]) {
        j++;  // avança em S só quando encontra match
    }
}
if (j == strlen(S)) {
    printf("É subsequência!\n");
} else {
    printf("Não é subsequência.\n");
}


[!tip] Padrão-chave


Dois índices: i percorre D livremente, j só avança quando há match
Se j chegou ao fim de S, todos os caracteres foram encontrados em ordem
Sem break — o loop precisa continuar procurando os próximos caracteres
Diferente de substring (consecutivos): subsequência permite "pulos"




Exemplo: D = "ACGTC", S = "CGT"

PassoiD[i]jS[j]Match?10A0CNão21C0CSim → j=132G1GSim → j=243T2TSim → j=3

→ j(3) == strlen("CGT")(3) → É subsequência ✓


2️⃣1️⃣ Separar Elementos por Condição

Quando usar: dividir um vetor em dois com base numa regra (par/ímpar, positivo/negativo, aprovado/reprovado).

cint pares[1000], impares[1000];
int total_par = 0, total_impar = 0;

for (i = 0; i < n; i++) {
    if (num[i] % 2 == 0) {
        pares[total_par] = num[i];
        total_par++;
    } else {
        impares[total_impar] = num[i];
        total_impar++;
    }
}


[!tip] Padrão-chave


Cada vetor tem seu próprio contador (total_par, total_impar)
O if decide pra qual vetor vai — pode ser % 2, > 0, >= 5, etc.
Depois de separar, pode ordenar e imprimir cada vetor independentemente
Funciona dentro do loop de leitura (separa enquanto lê) ou num loop separado

---


## 2️⃣2️⃣ Construir Matriz por Fórmula de Índices

**Ideia:** preencher cada posição `[i][j]` com uma expressão matemática que depende apenas de `i` e `j`, sem consultar outros elementos.

```c
// Exemplo: matriz onde m[i][j] = |i - j| + 1
// Gera a "distância diagonal" — diagonal principal = 1, afasta = cresce
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            int valor = abs(i - j) + 1;
            if (j == n - 1) {
                printf("%3d\n", valor);
            } else {
                printf("%3d ", valor);
            }
        }
    }
    return 0;
}
```

> [!tip] Padrão-chave
> - Cada `m[i][j]` é calculado por uma fórmula fechada (não depende de vizinhos)
> - Diferente do padrão 16 (que depende da linha anterior)
> - Fórmulas comuns: `abs(i - j)`, `i + j + 1`, `i * n + j`, `max(i, j)`
> - Pode construir "on-the-fly" (imprimir sem armazenar) ou preencher a matriz primeiro

### Exemplo visual: `abs(i - j) + 1` com N = 4

| i\j | 0 | 1 | 2 | 3 |
|-----|---|---|---|---|
| 0   | 1 | 2 | 3 | 4 |
| 1   | 2 | 1 | 2 | 3 |
| 2   | 3 | 2 | 1 | 2 |
| 3   | 4 | 3 | 2 | 1 |

→ Diagonal principal = 1, valor cresce conforme afasta da diagonal.

---

## 2️⃣3️⃣ Achar Menor/Maior com Posição

**Ideia:** extensão do padrão 1 — além de guardar o valor extremo, guardar o **índice** onde ele está.

```c
int menor = vetor[0];
int posicao = 0;

for (i = 1; i < n; i++) {
    if (vetor[i] < menor) {
        menor = vetor[i];
        posicao = i;        // atualiza a posição junto
    }
}

printf("Menor: %d\n", menor);
printf("Posição: %d\n", posicao);
```

> [!tip] Padrão-chave
> - Sempre atualizar `posicao` **dentro** do mesmo `if` que atualiza o valor
> - Inicializar `posicao = 0` (corresponde a `vetor[0]`)
> - Se quiser a **última** ocorrência do menor, use `<=` em vez de `<`
> - Em Python: `min(lista)` dá o valor, `lista.index(min(lista))` dá a posição

---

## 2️⃣4️⃣ Comparar Original vs. Cópia Transformada

**Ideia:** copiar o vetor antes de transformá-lo (ordenar, filtrar...), depois comparar elemento a elemento para medir o que mudou.

```c
int nota[1000], copia[1000];
int nao_mudou = 0;

// 1. Ler o vetor original
for (i = 0; i < n; i++) {
    scanf("%d", &nota[i]);
}

// 2. Copiar
for (i = 0; i < n; i++) {
    copia[i] = nota[i];
}

// 3. Transformar a cópia (ex: ordenar decrescente)
for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - 1; j++) {
        if (copia[j] < copia[j + 1]) {
            int aux = copia[j];
            copia[j] = copia[j + 1];
            copia[j + 1] = aux;
        }
    }
}

// 4. Comparar posição a posição
for (i = 0; i < n; i++) {
    if (nota[i] == copia[i]) {
        nao_mudou++;
    }
}
printf("Não mudaram de lugar: %d\n", nao_mudou);
```

> [!tip] Padrão-chave
> - Copiar **antes** de qualquer transformação (senão perde o original)
> - A comparação é sempre `original[i] == transformado[i]` (mesma posição)
> - Serve para: "quantos ficaram no lugar?", "quais mudaram?", "qual a diferença?"
> - Em Python: copiar lista com `copia = lista[:]` (nunca `copia = lista`, que é referência!)

---

## 2️⃣5️⃣ Processar Entrada Sem Armazenar (Flag com Reset)

**Ideia:** quando a entrada tem várias linhas/colunas mas você só precisa de um resumo por linha (ex: "fez gol em todas?"), não precisa guardar a matriz inteira — leia e processe no mesmo loop, resetando a flag a cada iteração externa.

```c
int acum = 0;  // conta quantas linhas satisfazem a condição

for (i = 0; i < n; i++) {
    int flag = 0;  // reset a cada linha!

    for (j = 0; j < m; j++) {
        int valor;
        scanf("%d", &valor);      // lê e descarta — não armazena
        if (valor == 0) {
            flag = 1;             // marcou: esta linha NÃO satisfaz
        }
    }

    if (flag == 0) {              // flag nunca foi ativada → satisfez tudo
        acum++;
    }
}
printf("%d\n", acum);
```

> [!tip] Padrão-chave
> - A flag é declarada/resetada **dentro** do `for` externo (nova linha = flag limpa)
> - Lê com `scanf` direto numa variável temporária — não precisa de vetor/matriz
> - Economiza memória: O(1) em vez de O(n×m)
> - Variação: flag "positiva" (começa 0, vira 1 quando acha) ou "negativa" (começa 0, vira 1 quando falha)

---

## 2️⃣6️⃣ Percorrer String Palavra a Palavra (Manual)

**Ideia:** caminhar caractere a caractere, detectando espaços como separadores de palavras. Útil quando precisa processar cada palavra com alguma lógica (ex: contar quais contêm certa letra).

```c
char texto[1001], letra;
int palavras = 1, com_letra = 0, achou = 0;

scanf("%c", &letra);
getchar();                          // consome o \n após a letra
fgets(texto, 1001, stdin);          // lê o texto inteiro com espaços

for (i = 0; texto[i] != '\0'; i++) {
    if (texto[i] == letra) {
        achou = 1;                  // flag: esta palavra contém a letra
    }
    if (texto[i] == ' ') {          // fim da palavra
        if (achou == 1) {
            com_letra++;
        }
        achou = 0;                  // reset para a próxima palavra
        palavras++;
    }
}
// Tratar a ÚLTIMA palavra (não termina com espaço)
if (achou == 1) {
    com_letra++;
}

printf("%.1f\n", (com_letra * 100.0) / palavras);
```

> [!tip] Padrão-chave
> - O loop para em `'\0'` (terminador de string em C)
> - Espaço `' '` marca o **fim** de uma palavra e o **início** da próxima
> - A flag `achou` faz reset a cada espaço (nova palavra = flag limpa)
> - **Armadilha clássica:** a última palavra não termina com espaço → tratar **depois** do loop
> - `getchar()` após `scanf("%c")` consome o `\n` residual antes do `fgets`
> - Diferente do padrão 18 (strtok): aqui você processa **durante** a varredura, sem separar antes

---

## 2️⃣7️⃣ Inserção em Posição Específica no Vetor

**Ideia:** montar um vetor resultado inserindo novos elementos **antes** de uma posição encontrada. Complemento do padrão 12 (remoção).

```c
char original[200][51], novos[200][51], resultado[400][51];
int totalO, totalN, totalR = 0;

// ... (ler original[] e novos[] com strtok — padrão 18) ...

char alvo[51];
scanf("%s", alvo);  // nome antes do qual inserir

for (i = 0; i < totalO; i++) {
    if (strcmp(original[i], alvo) == 0) {      // encontrou o ponto de inserção
        for (j = 0; j < totalN; j++) {         // insere todos os novos ANTES
            strcpy(resultado[totalR], novos[j]);
            totalR++;
        }
    }
    strcpy(resultado[totalR], original[i]);    // copia o elemento original
    totalR++;
}
```

> [!tip] Padrão-chave
> - Usar um vetor `resultado[]` separado (não tentar inserir "no meio" do original)
> - A inserção acontece **antes** de copiar o elemento que deu match
> - Se nenhum match for encontrado, os novos podem ir no final (tratar com `strcmp(alvo, "nao")`)
> - O `totalR` é o contador do resultado — cresce independente de `totalO`
> - Combina com: strtok (18) para ler, strcmp (13) para achar posição

---

## 2️⃣8️⃣ Potência de 2 com Shift de Bits

**Ideia:** usar `1 << n` em vez de `pow(2, n)` para calcular potências de 2 com resultado inteiro exato.

```c
// 1 << n  equivale a  2^n  (desloca o bit 1 para a esquerda n vezes)
int resultado = 1 << 3;   // 8  (2³)
int resultado = 1 << 0;   // 1  (2⁰)
int resultado = 1 << 10;  // 1024 (2¹⁰)

// Exemplo real: dobradura
// Após N dobraduras, cada dimensão tem (2^n + 1) partes
int base = (1 << n) + 1;
int pedacos = base * base;  // (2^n + 1)²
```

> [!tip] Padrão-chave
> - `1 << n` = 2ⁿ (inteiro exato, sem arredondamento)
> - `pow(2, n)` retorna `double` — pode dar erro ao converter para `int`
> - Funciona para n de 0 a 30 com `int` (2³⁰ = ~1 bilhão)
> - Serve também para verificar bit: `if (x & (1 << k))` → "o bit k está ligado?"
> - Precisa de `n >= 0` (shift negativo é comportamento indefinido)

---

## 2️⃣9️⃣ Transposta de Matriz

**Ideia:** imprimir ou construir a transposta trocando linhas por colunas — acessar `[j][i]` em vez de `[i][j]`.

```c
// Imprimir a transposta sem criar outra matriz
for (i = 0; i < linhas; i++) {
    for (j = 0; j < colunas; j++) {
        printf("%d ", matriz[j][i]);   // inverte os índices!
    }
    printf("\n");
}

// Criar uma nova matriz transposta
int transp[colunas][linhas];
for (i = 0; i < linhas; i++) {
    for (j = 0; j < colunas; j++) {
        transp[j][i] = matriz[i][j];
    }
}
```

```python
# Em Python (imprimir transposta diretamente)
for i in range(4):
    for j in range(4):
        print(matriz[j][i], end=' ')
    print()
```

> [!tip] Padrão-chave
> - Transpor = trocar `[i][j]` por `[j][i]` (linha vira coluna)
> - Pode imprimir direto (sem criar outra matriz) se só precisa exibir
> - Se precisa armazenar: a transposta de `M[m×n]` é `T[n×m]`
> - Em matrizes quadradas: a transposta reflete pela diagonal principal
> - Em Python com NumPy: `np.transpose(m)` ou `m.T`

---

## 3️⃣0️⃣ Verificar Palíndromo (Reversão de String)

**Ideia:** comparar a string com ela mesma invertida. Se forem iguais, é palíndromo.

```python
# Versão simples
palavra = input()
if palavra == palavra[::-1]:
    print("Palindromo")
else:
    print("Nao Palindromo")

# Versão robusta (ignora espaços e maiúsculas)
palavra = input()
limpa = palavra.replace(" ", "").lower()
if limpa == limpa[::-1]:
    print("Palindromo")
else:
    print("Nao Palindromo")
```

```c
// Em C: comparar do início com o fim
#include <string.h>
int palindromo(char s[]) {
    int i, n = strlen(s);
    for (i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) {
            return 0;  // não é
        }
    }
    return 1;  // é palíndromo
}
```

> [!tip] Padrão-chave
> - Python: `[::-1]` inverte a string em uma linha
> - C: comparar `s[i]` com `s[n-1-i]` até `i < n/2`
> - Versão robusta: remover espaços e converter para minúsculas **antes** de comparar
> - O loop só precisa ir até a metade (cada comparação verifica dois caracteres)
> - Funciona para números também: converter para string primeiro

---

## 3️⃣1️⃣ Média Ponderada com Vetor de Pesos

**Ideia:** multiplicar cada valor pelo seu peso, somar os produtos, dividir pela soma dos pesos. Diferente da média simples (padrão 8) onde todos têm peso igual.

```c
float notas[4], media;
int pesos[] = {2, 3, 2, 3};  // vetor de pesos paralelo ao vetor de notas
float soma_produtos = 0;
int soma_pesos = 0;

for (i = 0; i < 4; i++) {
    soma_produtos += notas[i] * pesos[i];  // numerador
    soma_pesos += pesos[i];                // denominador
}
media = soma_produtos / soma_pesos;
```

```python
# Em Python
pesos = [2, 3, 2, 3]
soma_produtos = 0
soma_pesos = 0
for j in range(4):
    soma_produtos += notas[j] * pesos[j]
    soma_pesos += pesos[j]
media = soma_produtos / soma_pesos
```

> [!tip] Padrão-chave
> - Dois acumuladores: `soma_produtos` (numerador) e `soma_pesos` (denominador)
> - O vetor de pesos é **paralelo** ao vetor de notas (mesmo índice `[i]`)
> - Fórmula: `Σ(nota × peso) / Σ(peso)`
> - Média simples é caso especial onde todos os pesos = 1
> - Cuidado: `soma_pesos` nunca pode ser zero (divisão por zero)

---

## 3️⃣2️⃣ Acumulador de Dois Níveis (Individual + Grupo)

**Ideia:** calcular um valor por entidade (média do aluno) e ao mesmo tempo acumular para o grupo (média da sala). Loop interno soma por entidade, loop externo acumula entre entidades.

```c
float soma_sala = 0;

for (i = 0; i < total_alunos; i++) {
    // Nível 1: acumulador INTERNO (por aluno) — reseta a cada iteração
    float soma_notas = 0;
    for (j = 0; j < 4; j++) {
        soma_notas += alunos[i].notas[j];
    }
    alunos[i].media = soma_notas / 4.0;

    // Nível 2: acumulador EXTERNO (do grupo) — não reseta
    soma_sala += alunos[i].media;
}

float media_sala = soma_sala / total_alunos;
```

> [!tip] Padrão-chave
> - Acumulador interno (`soma_notas`): declarado/resetado **dentro** do `for` externo
> - Acumulador externo (`soma_sala`): declarado **antes** do `for` externo, nunca reseta
> - O interno produz um resultado por entidade (média do aluno)
> - O externo agrega todos os resultados (média da sala)
> - Padrão aparece em: média de médias, total de subtotais, contagem de contagens

---

## 3️⃣3️⃣ Bubble Sort em Vetor de Structs

**Ideia:** ordenar um vetor de structs comparando por um campo específico e trocando a struct **inteira** com uma variável auxiliar do mesmo tipo.

```c
typedef struct {
    char nome[51];
    int matricula;
    float salario;
} Funcionario;

Funcionario dados[20], aux;  // aux é do tipo Funcionario!

// Ordenar por nome (alfabético) — usa strcmp
for (i = 0; i < total - 1; i++) {
    for (j = 0; j < total - 1; j++) {
        if (strcmp(dados[j].nome, dados[j+1].nome) > 0) {
            aux = dados[j];          // copia a struct INTEIRA
            dados[j] = dados[j+1];
            dados[j+1] = aux;
        }
    }
}

// Ordenar por salário (numérico crescente)
for (i = 0; i < total - 1; i++) {
    for (j = 0; j < total - 1; j++) {
        if (dados[j].salario > dados[j+1].salario) {
            aux = dados[j];
            dados[j] = dados[j+1];
            dados[j+1] = aux;
        }
    }
}
```

> [!tip] Padrão-chave
> - A variável `aux` deve ser **do tipo da struct**, não `int` — troca tudo de uma vez
> - Comparação por string: `strcmp(a.nome, b.nome) > 0` (não usar `>`)
> - Comparação por número: `a.campo > b.campo` (igual ao Bubble Sort normal)
> - A troca `aux = dados[j]` copia **todos os campos** automaticamente em C
> - Para trocar apenas a ordenação: inverter o sinal (`>` vira `<` ou vice-versa)

---

## 3️⃣4️⃣ Filtrar Vetor/Struct por Faixa de Valores

**Ideia:** percorrer o vetor e exibir apenas os elementos que satisfazem uma condição de faixa (intervalo). Usar flag para detectar "nenhum encontrado".

```c
int encontrou = 0;

for (i = 0; i < total; i++) {
    if (dados[i].altura > 1.50 && dados[i].altura < 2.00) {  // faixa
        printf("Nome: %s | Altura: %.2f\n", dados[i].nome, dados[i].altura);
        encontrou = 1;
    }
}

if (encontrou == 0) {
    printf("Nenhum registro nessa faixa.\n");
}
```

> [!tip] Padrão-chave
> - A condição do `if` define a faixa: `>= min && <= max`, `> x`, `< y`, etc.
> - Flag `encontrou` começa em 0 e vai para 1 na primeira impressão
> - A mensagem "nenhum encontrado" vem **depois** do loop, nunca dentro
> - Pode combinar com ordenação prévia (padrão 33) para exibir em ordem
> - Variações comuns: `<= 1.50` (até), `> 1.50` (acima), `>= 1.50 && <= 2.00` (entre)
> - Diferente do padrão 21 (separar): aqui não cria vetores novos, só filtra e exibe

---

## 3️⃣5️⃣ Menor/Maior por Campo de Struct

**Ideia:** encontrar a struct com o maior (ou menor) valor em um campo, rastreando o **índice** — depois acessar qualquer campo daquela struct pelo índice salvo.

```c
int maior = 0, menor = 0;  // índices, não valores!

for (i = 1; i < total; i++) {
    if (alunos[i].media > alunos[maior].media) {
        maior = i;
    }
    if (alunos[i].media < alunos[menor].media) {
        menor = i;
    }
}

// Acessa TODOS os campos da struct pelo índice salvo
printf("Maior: %s | Média: %.2f\n", alunos[maior].nome, alunos[maior].media);
printf("Menor: %s | Média: %.2f\n", alunos[menor].nome, alunos[menor].media);
```

> [!tip] Padrão-chave
> - Guardar o **índice** (não o valor) — permite acessar qualquer campo depois
> - Compara `alunos[i].campo` com `alunos[maior].campo` (não com um `int maior`)
> - Extensão do padrão 23: lá era `menor` e `posicao` separados, aqui o índice faz tudo
> - Inicializar `maior = 0` e `menor = 0`, loop começa em `i = 1`
> - Após o loop, `alunos[maior]` dá acesso completo (nome, RGA, média, etc.)

---

## 3️⃣6️⃣ Multiplicação de Matrizes (Triplo For)

**Ideia:** para calcular `resultado[i][j]`, somar os produtos de toda a linha `i` da primeira matriz com toda a coluna `j` da segunda. Exige um terceiro loop (`k`) como acumulador.

```c
int m1[3][3], m2[3][3], mult[3][3];

for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
        mult[i][j] = 0;                    // zerar antes de acumular!
        for (k = 0; k < 3; k++) {
            mult[i][j] += m1[i][k] * m2[k][j];
        }
    }
}
```

> [!tip] Padrão-chave
> - Três `for` aninhados: `i` = linha do resultado, `j` = coluna do resultado, `k` = acumulador
> - O `k` "caminha" pela linha de `m1` (`m1[i][k]`) e pela coluna de `m2` (`m2[k][j]`)
> - `mult[i][j] = 0` é obrigatório ANTES do `for k` (senão soma lixo)
> - Regra de dimensão: `A[m×n] × B[n×p] = C[m×p]` — colunas de A = linhas de B
> - Para M² (exponencial): basta usar `m1[i][k] * m1[k][j]` (mesma matriz nos dois lados)
> - Complexidade: O(n³) — caro para matrizes grandes

### Exemplo visual: como `mult[0][1]` é calculado

```
m1 linha 0:  [1  2  3]       m2 coluna 1:  [4]
                                            [5]
                                            [6]

mult[0][1] = 1×4 + 2×5 + 3×6 = 32
```

---

## 3️⃣7️⃣ Operação Elemento a Elemento entre Matrizes

**Ideia:** aplicar uma operação (`+`, `-`, `*`, etc.) entre matrizes de mesmo tamanho, posição por posição.

```c
int m1[2][2], m2[2][2], resultado[2][2];

for (i = 0; i < 2; i++) {
    for (j = 0; j < 2; j++) {
        resultado[i][j] = m1[i][j] + m2[i][j];   // soma
        // resultado[i][j] = m1[i][j] - m2[i][j]; // subtração
        // resultado[i][j] = m1[i][j] * m2[i][j]; // produto (Hadamard)
    }
}
```

> [!tip] Padrão-chave
> - Dois `for` aninhados (não precisa de terceiro — diferente da multiplicação de matrizes!)
> - Mesmo `[i][j]` nas três matrizes — posição a posição
> - As matrizes devem ter o **mesmo tamanho** (m×n)
> - Diferente do padrão 36: lá é multiplicação matricial (triplo for), aqui é operação direta
> - Pode fazer no mesmo loop de leitura se quiser (ler m1, ler m2, calcular, tudo em um bloco)

---

## 3️⃣8️⃣ Desvio Padrão (Múltiplos Acumuladores em um Passo)

**Ideia:** acumular `soma` e `soma dos quadrados` no mesmo loop de leitura, depois aplicar a fórmula estatística. Evita percorrer o vetor duas vezes.

```c
#include <math.h>

double soma = 0, somaQuad = 0, media, dp;

for (i = 0; i < n; i++) {
    scanf("%d", &vetor[i]);
    soma += vetor[i];                   // Σx
    somaQuad += vetor[i] * vetor[i];   // Σx²
}

media = soma / n;
dp = sqrt((somaQuad - n * media * media) / (n - 1));
// (n - 1) para desvio padrão amostral
// (n) para desvio padrão populacional
```

> [!tip] Padrão-chave
> - Dois acumuladores no mesmo loop: `soma` (Σx) e `somaQuad` (Σx²)
> - A fórmula usa: `dp = √( (Σx² − n·μ²) / (n−1) )`
> - Precisa de `#include <math.h>` para `sqrt()` e compilar com `-lm`
> - O padrão generaliza: qualquer cálculo que precise de Σx e Σx² (variância, covariância, correlação)
> - Dividir por `n - 1` = amostral (mais comum em provas), por `n` = populacional

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
| 17 | qsort | `qsort(v, n, sizeof, fn)` | Ordenação rápida (N grande) |
| 18 | strtok | `strtok(str, " ")` | Separar string em pedaços |
| 19 | strstr | `strstr(a, b)` | Buscar substring |
| 20 | Subsequência | Dois índices em strings | Buscar chars em ordem |
| 21 | Separar por condição | `if` + dois vetores | Dividir vetor em dois |
| 22 | Matriz por fórmula | `f(i, j)` | Preencher matriz sem dependência |
| 23 | Menor com posição | `menor` + `posicao` | Achar extremo e onde está |
| 24 | Cópia + comparação | `copiar → transformar → comparar` | Medir o que mudou |
| 25 | Processar sem armazenar | `flag com reset` | Resumir linha/bloco on-the-fly |
| 26 | Palavras manual | `char a char + espaço` | Processar palavras sem strtok |
| 27 | Inserção no vetor | `resultado[]` separado | Inserir antes de posição |
| 28 | Shift de bits | `1 << n` | Potência de 2 inteira |
| 29 | Transposta | `[j][i]` em vez de `[i][j]` | Trocar linhas por colunas |
| 30 | Palíndromo | `s == s[::-1]` | Verificar leitura inversa |
| 31 | Média ponderada | `Σ(v×p) / Σ(p)` | Pesos diferentes por nota |
| 32 | Acumulador 2 níveis | interno + externo | Média individual + do grupo |
| 33 | Bubble Sort structs | `aux = struct inteira` | Ordenar structs por campo |
| 34 | Filtrar por faixa | `if (>= min && <= max)` | Exibir só quem cumpre intervalo |
| 35 | Menor/Maior em struct | `indice` do extremo | Achar struct com maior/menor campo |
| 36 | Multiplicação de matrizes | triplo `for` com `k` | A[m×n] × B[n×p] |
| 37 | Operação entre matrizes | `res[i][j] = m1 OP m2` | Soma/sub/prod posição a posição |
| 38 | Desvio padrão | `Σx` e `Σx²` no mesmo loop | Estatísticas em um passo |