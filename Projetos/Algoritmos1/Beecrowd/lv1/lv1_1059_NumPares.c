/*Faça um programa que mostre os números pares entre 1 e 100, inclusive.

Entrada
Neste problema extremamente simples de repetição não há entrada.

Saída
Imprima todos os números pares entre 1 e 100, inclusive se for o caso, um em cada linha.*/

#include <stdio.h>
int main() {
    for (int i = 2; i <= 100; i += 2) { /* loop para imprimir números pares entre 1 e 100 */
        printf("%d\n", i); /* imprime o número par atual seguido de uma nova linha */
    }
    return 0;
}

/* Fiz um código acumulando quantos pares possuem entre 1 e 100 */

#include <stdio.h>
int main() {
    int i, pares; /* variáveis para armazenar o número de pares */
    pares = 0;
    for (i=2; i<=100; i+=2) {
        printf("%d\n", i); /* imprime o número par atual seguido de uma nova linha */
        pares = pares + 1; /* adiciona uma variável acumuladora do número de pares */
    }
    printf("%d\n", pares);
}    