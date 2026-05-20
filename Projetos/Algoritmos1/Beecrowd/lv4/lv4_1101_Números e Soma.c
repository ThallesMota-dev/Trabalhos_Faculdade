/* Leia um conjunto não determinado de pares de valores M e N (parar quando algum 
dos valores for menor ou igual a zero). Para cada par lido, mostre a sequência do 
menor até o maior e a soma dos inteiros consecutivos entre eles (incluindo o N e M).

Entrada
O arquivo de entrada contém um número não determinado de valores M e N. 
A última linha de entrada vai conter um número nulo ou negativo.

Saída
Para cada dupla de valores, imprima a sequência do menor até o maior e a soma 
eles, conforme exemplo abaixo.*/

#include <stdio.h>
int main() {
    int n, m, i, soma, aux; /* declaração das variáveis */
    while (scanf("%d %d", &n, &m) == 2 && n > 0 && m > 0) { /* enquanto houver entrada e os valores forem positivos */
    if (n > m) {  /* se n for maior que m */
		aux = n; /* armazena o valor de n em aux */
		n = m; /* atribui o valor de m a n */
		m = aux; /* atribui o valor de aux a m */
	} /* fizemos o swap para que, com um condicional ele cubra o caso em que n > m apenas invertendo os valores das variáveis */
    soma = 0; /* inicializa a variável soma */
    for (i = n; i <= m; i++) { /* percorre os valores do menor ao maior */
        printf("%d ", i); /* imprime o valor atual com um espaço para atender o formato de saída */
        soma += i; /* acumula a soma dos valores */
    } /* ao final do loop, será escrito cada valor de n a m e a soma terá o valor da soma dos inteiros consecutivos entre n e m */
    printf("Sum=%d\n", soma); /* imprime a soma no formato solicitado */
    }
}