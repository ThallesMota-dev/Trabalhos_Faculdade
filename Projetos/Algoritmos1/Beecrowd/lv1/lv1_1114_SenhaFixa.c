/* Escreva um programa que repita a leitura de uma senha até que ela seja válida.
Para cada leitura de senha incorreta informada, escrever a mensagem "Senha Invalida".
Quando a senha for informada corretamente deve ser impressa a mensagem "Acesso Permitido"
e o algoritmo encerrado. Considere que a senha correta é o valor 2002. 

Entrada
A entrada é composta por vários casos de testes contendo valores inteiros.

Saída
Para cada valor lido mostre a mensagem correspondente à descrição do problema.*/

#include <stdio.h>
int main() {
	int senha; 
	while (scanf("%d", &senha) == 1) { /* loop para ler a senha até que seja válida */
		if (senha != 2002) { /* se a senha for incorreta */
			printf("Senha Invalida\n"); /* imprimir mensagem de senha inválida */
		} else { /* se a senha for correta */
			printf("Acesso Permitido\n"); /* imprimir mensagem de acesso permitido */
			break; /* encerrar o loop */
		}
	}
}