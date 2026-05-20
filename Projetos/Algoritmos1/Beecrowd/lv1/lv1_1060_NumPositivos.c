/* Faça um programa que leia 6 valores. Estes valores serão somente negativos ou
positivos (desconsidere os valores nulos). A seguir, mostre a quantidade de 
valores positivos digitados.

Entrada
Seis valores, negativos e/ou positivos.

Saída
Imprima uma mensagem dizendo quantos valores positivos foram lidos.*/

#include <stdio.h>
int main(){ 
	float n; /* variável para armazenar cada valor lido */
	int positivos = 0; /* contador de valores positivos */
	for (int i=0; i<6; i++) { /* loop para ler os 6 valores */
		scanf("%f", &n); /* leitura do próximo valor */
		if (n > 0) { /* se o valor for positivo */
			positivos += 1; /* incrementa o contador de positivos */
		}
	}	
	printf("%d valores positivos\n", positivos);
	return 0;
}