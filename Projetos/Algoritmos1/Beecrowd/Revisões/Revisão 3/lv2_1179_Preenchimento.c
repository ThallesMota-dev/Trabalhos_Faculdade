/* Neste problema você deverá ler 15 valores colocá-los em 2 vetores conforme 
estes valores forem pares ou ímpares. Só que o tamanho de cada um dos dois vetores 
é de 5 posições. Então, cada vez que um dos dois vetores encher, você deverá 
imprimir todo o vetor e utilizá-lo novamente para os próximos números que forem 
lidos. Terminada a leitura, deve-se imprimir o conteúdo que restou em cada um dos 
dois vetores, imprimindo primeiro os valores do vetor impar. Cada vetor pode ser 
preenchido tantas vezes quantas for necessário.

Entrada
A entrada contém 15 números inteiros.

Saída
Imprima a saída conforme o exemplo abaixo.

Exemplo de Entrada	
1
3
4
-4
2
3
8
2
5
-7
54
76
789
23
98

Exemplo de Saída
par[0] = 4
par[1] = -4
par[2] = 2
par[3] = 8
par[4] = 2
impar[0] = 1
impar[1] = 3
impar[2] = 3
impar[3] = 5
impar[4] = -7
impar[0] = 789
impar[1] = 23
par[0] = 54
par[1] = 76
par[2] = 98*/

#include <stdio.h>
int main() {
    int i, j, acumpar, acumimpar, num, par[5], impar[5];
    acumpar = 0; // Contador para o vetor par
    acumimpar = 0; // Contador para o vetor impar
    for (i=0; i<15; i++) { // Loop para ler os 15 valores
        scanf("%d", &num); // Lê o valor
        if (num % 2 == 0) { // Se o valor for par
            par[acumpar] = num; // Armazena no vetor par
            acumpar++; // Incrementa o contador do vetor par
            if (acumpar == 5) { // Se o vetor par estiver cheio
                for (j=0; j<5; j++) { // Imprime o vetor par
                    printf("par[%d] = %d\n", j, par[j]);
                }
                acumpar = 0; // Reseta o contador do vetor par
            }
        } else { // Se o valor for ímpar
            impar[acumimpar] = num; // Armazena no vetor impar
            acumimpar++; // Incrementa o contador do vetor impar
            if (acumimpar == 5) { // Se o vetor impar estiver cheio
                for (j=0; j<5; j++) { // Imprime o vetor impar
                    printf("impar[%d] = %d\n", j, impar[j]);
                }
                acumimpar = 0; // Reseta o contador do vetor impar
            }
        }
    }
    for (j=0; j<acumimpar; j++) { // Imprime os valores restantes do vetor impar
        printf("impar[%d] = %d\n", j, impar[j]);
    }
    for (j=0; j<acumpar; j++) { // Imprime os valores restantes do vetor par
        printf("par[%d] = %d\n", j, par[j]);
    }
    return 0;
}

/*
Código equivalente em Python:
par = [None] * 5 # Cria um vetor de tamanho 5 para os números pares
impar = [None] * 5 # Cria um vetor de tamanho 5 para os números ímpares
acumpar = 0 # Contador para o vetor par
acumimpar = 0 # Contador para o vetor impar
for i in range(15): # Loop para ler os 15 valores
    num = int(input()) # Lê o value
    if (num % 2 == 0): # Se o value for par
        par[acumpar] = num # Armazena no vetor par
        acumpar += 1 # Incrementa o contador do vetor par
        if acumpar == 5: # Se o vetor par estiver cheio
            for j in range(5): # Imprime o vetor par
                print(f"par[{j}] = {par[j]}")
            acumpar = 0 # Reseta o contador do vetor par
    else: # Se o valor for ímpar
        impar[acumimpar] = num # Armazena no vetor impar
        acumimpar += 1 # Incrementa o contador do vetor impar
        if acumimpar == 5: # Se o vetor impar estiver cheio
            for j in range(5): # Imprime o vetor impar
                print(f"impar[{j}] = {impar[j]}")
            acumimpar = 0 # Reseta o contador do vetor impar
for j in range(acumimpar): # Imprime os valores restantes do vetor impar
    print(f"impar[{j}] = {impar[j]}")
for j in range(acumpar): # Imprime os valores restantes do vetor par
    print(f"par[{j}] = {par[j]}")
*/