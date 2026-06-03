/* Etapa 1 — Análise do Enunciado

A árvore de Natal é feita de duas partes:
Copa (de cima pra baixo): começa com 1 asterisco e vai aumentando de 2 em 2 até chegar em N.
Tronco: primeiro 1 asterisco, depois 3 asteriscos.
Depois de cada árvore, uma linha em branco.

Etapa 2 — Descobrindo o padrão

Olha a árvore de N=9. A largura máxima é 9. Cada linha precisa ser centralizada:
    *         → 4 espaços + 1 asterisco
   ***        → 3 espaços + 3 asteriscos
  *****       → 2 espaços + 5 asteriscos
 *******      → 1 espaço  + 7 asteriscos
*********     → 0 espaços + 9 asteriscos
    *         → tronco: 1 asterisco
   ***        → tronco: 3 asteriscos*/

#include <stdio.h>
int main() {
    int N, j, k; // N é a largura máxima da árvore, j é o contador de espaços e k é o contador de asteriscos
    while (scanf("%d", &N) == 1) { // enquanto houver um número para ler, o programa continua
        for (k = 1; k <= N; k += 2) { // para cada linha da copa, k começa em 1 e vai aumentando de 2 em 2 até chegar em N
            for (j = 0; j < (N - k) / 2; j++) { // para cada linha da copa, j começa em 0 e vai até (N - k) / 2, que é o número de espaços necessários para centralizar os asteriscos
                printf(" "); // imprime um espaço para centralizar os asteriscos
            }
            for (j = 0; j < k; j++) { // para cada linha da copa, j começa em 0 e vai até k, que é o número de asteriscos necessários para aquela linha
                printf("*"); // imprime um asterisco para cada linha da copa
            }
            printf("\n"); // depois de imprimir os asteriscos, imprime uma nova linha para passar para a próxima linha da copa
        }
        for (j = 0; j < (N - 1) / 2; j++) { // para a primeira linha do tronco, j começa em 0 e vai até (N - 1) / 2, que é o número de espaços necessários para centralizar o asterisco do tronco
            printf(" "); // imprime um espaço para centralizar o asterisco do tronco
        }
        printf("*\n"); // depois de imprimir os espaços, imprime um asterisco para o tronco e uma nova linha para passar para a próxima linha do tronco
        for (j = 0; j < (N - 3) / 2; j++) { // para a segunda linha do tronco, j começa em 0 e vai até (N - 3) / 2, que é o número de espaços necessários para centralizar os 3 asteriscos do tronco
            printf(" "); // imprime um espaço para centralizar os 3 asteriscos do tronco
        }
        printf("***\n"); // depois de imprimir os espaços, imprime 3 asteriscos para o tronco e uma nova linha para passar para a próxima linha do tronco
        printf("\n"); // depois de imprimir a árvore, imprime uma linha em branco para separar as árvores, caso haja mais de uma entrada
    }
    return 0;
}
