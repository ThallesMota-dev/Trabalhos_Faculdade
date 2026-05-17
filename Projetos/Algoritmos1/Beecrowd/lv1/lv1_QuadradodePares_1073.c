/* Leia um valor inteiro N. Apresente o quadrado de cada um dos valores pares, 
de 1 até N, inclusive N, se for o caso.

Entrada
A entrada contém um valor inteiro N (5 < N < 2000).

Saída
Imprima o quadrado de cada um dos valores pares, de 1 até N, conforme o exemplo 
abaixo.

Tome cuidado! Algumas linguagens tem por padrão apresentarem como saída 1e+006 
ao invés de 1000000 o que ocasionará resposta errada. Neste caso, configure a 
precisão adequadamente para que isso não ocorra. */

#include <stdio.h>
int main() {
	int i, n, quadrado; /* variáveis para armazenar o índice, o valor de N e o quadrado */
	scanf("%d", &n); /* leitura do valor de n */
	for (i=2; i<=n; i+=2) { /* loop para percorrer os números pares de 2 até n com passo i + 2*/
		quadrado = i * i; /* cálculo do quadrado */
		printf("%d^2 = %d\n", i, quadrado); /* impressão do resultado no formato "i^2 = quadrado" */
	}
}