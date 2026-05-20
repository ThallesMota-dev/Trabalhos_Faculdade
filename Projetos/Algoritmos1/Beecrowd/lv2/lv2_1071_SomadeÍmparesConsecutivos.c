/*Leia 2 valores inteiros X e Y. A seguir, calcule e mostre a soma dos números 
impares entre eles.

Entrada
O arquivo de entrada contém dois valores inteiros.

Saída
O programa deve imprimir um valor inteiro. Este valor é a soma dos valores
ímpares que estão entre os valores fornecidos na entrada que deverá caber em um inteiro.*/

#include <stdio.h>
int main() {
	int i, x, y, aux, soma_impar = 0; /* Declaração das variáveis */
	scanf("%d", &x); /* Leitura do valor de X */
	scanf("%d", &y); /* Leitura do valor de Y */
	if (x > y) { /* Verifica se X é maior que Y */
		aux = x; /* Armazena o valor de X em uma variável auxiliar */
		x = y; /* Atribui o valor de Y a X */
		y = aux; /* Atribui o valor armazenado em aux a Y */
	}
	for (i=x+1; i<y; i++){ /* Loop para verificar os números entre X e Y */
		if (i % 2 != 0) { /* Verifica se o número é ímpar */
			soma_impar += i; /* Adiciona o número ímpar à soma de ímpares*/
		}
	}
	printf("%d\n", soma_impar); /* Imprime a soma dos números ímpares entre X e Y */
	return 0;
}