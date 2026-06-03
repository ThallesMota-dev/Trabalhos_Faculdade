/* Etapa 1 — Análise do Enunciado

A Giovana manda uma carta com N números de duendes. Esses números representam 
todos os duendes com número menor que o anfitrião E coprimos ao número do anfitrião (MDC = 1). 
Precisamos descobrir o número do anfitrião.

Etapa 2 — Verificando com os exemplos

Exemplo 1: lista = {7, 1, 9, 3} → resposta = 10
Conferindo: números menores que 10 e coprimos a 10: 1, 3, 7, 9 ✓ (4 números = N)
Exemplo 2: lista = {4, 6, 1, 5, 3, 2} → resposta = 7
Como 7 é primo, todos os menores são coprimos: 1, 2, 3, 4, 5, 6 ✓
Etapa 3 — Estratégia
O anfitrião X precisa ser:

Maior que todos os números da lista
Ter MDC = 1 com cada número da lista
A quantidade de coprimos menores que X (totiente de Euler φ(X)) deve ser exatamente N

Então o algoritmo é: começar testando X = max(lista) + 1 e ir subindo até encontrar 
um X que satisfaça todas as condições.*/

#include <stdio.h>

int main() {
    int N; // quantidade de duendes
    scanf("%d", &N); // ler a quantidade de duendes

    int lista[10000]; // lista para armazenar os números dos duendes
    int maior = 0; // variável para armazenar o maior número da lista

    for (int i = 0; i < N; i++) { // ler os números dos duendes e encontrar o maior
        scanf("%d", &lista[i]); // ler o número do duende
        if (lista[i] > maior) { // atualizar o maior número se necessário
            maior = lista[i]; // atualizar o maior número
        }
    }

    int X = maior + 1; // começar a testar a partir do maior número + 1

    while (1) { // loop infinito para encontrar o anfitrião
        int todos_coprimos = 1; // flag para verificar se todos os números da lista são coprimos a X

        for (int i = 0; i < N; i++) { // verificar se lista[i] é coprimo a X
            int a = X; // calcular o MDC usando o algoritmo de Euclides
            int b = lista[i]; // número do duende
            while (b != 0) { // enquanto b não for zero
                int aux = b; // armazenar o valor de b temporariamente
                b = a % b; // atualizar b para o resto da divisão de a por b
                a = aux; // atualizar a para o valor temporário (antigo b)
            }
            if (a != 1) { // se o MDC não for 1, então X e lista[i] não são coprimos
                todos_coprimos = 0; // marcar que nem todos são coprimos
                break; // sair do loop, pois já sabemos que X não é o anfitrião
            }
        }

        if (todos_coprimos) { // se todos os números da lista são coprimos a X, verificar o totiente de Euler φ(X)
            int contador = 0; // contador para contar quantos números menores que X são coprimos a X
            for (int k = 1; k < X; k++) { // verificar cada número menor que X
                int a = X; // calcular o MDC usando o algoritmo de Euclides
                int b = k; // número a ser verificado
                while (b != 0) { // enquanto b não for zero
                    int aux = b; // armazenar o valor de b temporariamente
                    b = a % b; // atualizar b para o resto da divisão de a por b
                    a = aux; // atualizar a para o valor temporário (antigo b)
                }
                if (a == 1) { // se o MDC for 1, então k é coprimo a X
                    contador++; // incrementar o contador de coprimos
                }
            }

            if (contador == N) { // se a quantidade de coprimos for igual a N, encontramos o anfitrião
                printf("%d\n", X); // imprimir o número do anfitrião
                break; // sair do loop, pois já encontramos a resposta
            }
        }

        X++; // testar o próximo número como possível anfitrião
    }

    return 0;
}