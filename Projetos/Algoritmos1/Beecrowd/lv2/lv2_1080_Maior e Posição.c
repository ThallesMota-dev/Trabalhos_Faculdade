/* Leia 100 valores inteiros. Apresente então o maior valor lido e a posição 
dentre os 100 valores lidos.

Entrada
O arquivo de entrada contém 100 números inteiros, positivos e distintos.

Saída
Apresente o maior valor lido e a posição de entrada, conforme exemplo abaixo. */

#include <stdio.h>
int main(){
	int n, i, maior, posicao; /* Declaração das variáveis */
	maior = 0; /* Inicialização da variável maior */
	posicao = 0; /* Inicialização da variável posicao */
	for (i=1; i<=100; i++) { /* Loop para ler os 100 valores inteiros */
		scanf("%d", &n); /* Leitura do valor inteiro */
		if (n > maior) { /* Verifica se o valor lido é maior que o atual */
			maior = n; /* Atualiza o maior valor */
			posicao = i; /* Atualiza a posição do maior valor */
		}
	}
	printf("%d\n", maior); /* Imprime o maior valor lido */
	printf("%d\n", posicao); /* Imprime a posição do maior valor lido */
}