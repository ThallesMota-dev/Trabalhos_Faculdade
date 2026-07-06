/*Faça um programa que leia um valor e apresente o número de Fibonacci correspondente 
a este valor lido. Lembre que os 2 primeiros elementos da série de Fibonacci são 
0 e 1 e cada próximo termo é a soma dos 2 anteriores a ele. Todos os valores de 
Fibonacci calculados neste problema devem caber em um inteiro de 64 bits sem sinal.

Entrada
A primeira linha da entrada contém um inteiro T, indicando o número de casos de 
teste. Cada caso de teste contém um único inteiro N (0 ≤ N ≤ 60), correspondente 
ao N-esimo termo da série de Fibonacci.

Saída
Para cada caso de teste da entrada, imprima a mensagem "Fib(N) = X", onde X é o 
N-ésimo termo da série de Fibonacci.

Exemplo de Entrada	
3
0
4
2

Exemplo de Saída
Fib(0) = 0
Fib(4) = 3
Fib(2) = 1*/

#include <stdio.h> 
int main() {
    int i, j, T, N;
    unsigned long long Fib[61]; 
    scanf("%d", &T); // casos de teste
    for (i=0; i<T; i++) { // loop de repetições até o num de casos teste
        scanf("%d", &N); // leitura do n-esimo termo de fibonacci
        Fib[0] = 0;
        Fib[1] = 1;
        for (j=2; j<=N; j++) { // loop a partir de 2 até o n-esimo termo
            Fib[j] = Fib[j-1] + Fib[j-2]; // o termo da série a soma dos dois anteriores
        }
        printf("Fib(%d) = %llu\n", N, Fib[N]);
    }
    return 0;
}