/* Faça um programa que leia um vetor X[10]. Substitua a seguir, todos os valores nulos e negativos do vetor X por 1. Em seguida mostre o vetor X.

Entrada
A entrada contém 10 valores inteiros, podendo ser positivos ou negativos.

Saída
Para cada posição do vetor, escreva "X[i] = x", onde i é a posição do vetor e x é o valor armazenado naquela posição.

Exemplo de Entrada	Exemplo de Saída
0
-5
63
0
...

X[0] = 1
X[1] = 1
X[2] = 63
X[3] = 1
...
*/

#include <stdio.h>
int main() {
	int X[10], i;
	for (i=0; i<10; i++) { // Loop para ler os valores do vetor
		scanf("%d", &X[i]); // Lê os valores do vetor
		if (X[i] <= 0) { // Se o valor for nulo ou negativo, substitui por 1
			X[i] = 1; // Substitui o valor por 1
		}
		printf("X[%d] = %d\n", i, X[i]); // Imprime o valor do vetor na posição i
	}
	return 0;
}

/* 
Em python, o código equivalente seria:
X = [None] * 10 // Cria um vetor de tamanho 10
for i in range(10): // Loop para ler os valores do vetor
	X[i] = int(input()) // Lê os valores do vetor
	if (X[i] <= 0): // Se o valor for nulo ou negativo, substitui por 1
		X[i] = 1 // Substitui o valor por 1
	print(f"X[{i}] = {X[i]}") // Imprime o valor do vetor na posição i
*/