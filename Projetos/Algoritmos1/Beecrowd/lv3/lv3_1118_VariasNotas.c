/*Escreva um programa para ler as notas da primeira e a segunda avaliação de um aluno.
Calcule e imprima a média semestral. O programa só deverá aceitar notas válidas 
(uma nota válida deve pertencer ao intervalo [0,10]). Cada nota deve ser validada separadamente.

No final deve ser impressa a mensagem “novo calculo (1-sim 2-nao)”, solicitando 
ao usuário que informe um código (1 ou 2) indicando se ele deseja ou não executar 
o algoritmo novamente, (aceitar apenas os código 1 ou 2). Se for informado o 
código 1 deve ser repetida a execução de todo o programa para permitir um novo 
cálculo, caso contrário o programa deve ser encerrado.

Entrada
O arquivo de entrada contém vários valores reais, positivos ou negativos. 
Quando forem lidas duas notas válidas, deve ser lido um valor inteiro X. 
O programa deve parar quando o valor lido para este X for igual a 2.

Saída
Se uma nota inválida for lida, deve ser impressa a mensagem “nota invalida”. 
Quando duas notas válidas forem lidas, deve ser impressa a mensagem “media = ” 
seguido do valor do cálculo.

Antes da leitura de X deve ser impressa a mensagem "novo calculo (1-sim 2-nao)" 
e esta mensagem deve ser apresentada novamente se o valor da entrada padrão para
X for menor do que 1 ou maior do que 2, conforme o exemplo abaixo.

A média deve ser impressa com dois dígitos após o ponto decimal. */

#include <stdio.h>

int main() {
    float nota1, nota2; /* Variáveis para armazenar as notas */
    int x; /* Variável para armazenar a opção do usuário */
    while (1) { /* Loop principal */
        do { /* Leitura da primeira nota */
            scanf("%f", &nota1); /* Leitura da primeira nota */
            if (nota1 < 0 || nota1 > 10) { /* Verificação da validade da primeira nota */
                printf("nota invalida\n"); /* Impressão da mensagem de nota inválida */
            }
        } while (nota1 < 0 || nota1 > 10); /* Verificação da validade da primeira nota */
        do { /* Leitura da segunda nota */
            scanf("%f", &nota2); /* Leitura da segunda nota */
            if (nota2 < 0 || nota2 > 10) { /* Verificação da validade da segunda nota */
                printf("nota invalida\n"); /* Impressão da mensagem de nota inválida */
            }
        } while (nota2 < 0 || nota2 > 10); /* Verificação da validade da segunda nota */
        float media = (nota1 + nota2) / 2; /* Cálculo da média */
        printf("media = %.2f\n", media); /* Impressão da média */
        do { /* Leitura da opção do usuário */
            printf("novo calculo (1-sim 2-nao)\n"); /* Impressão da mensagem de nova operação */
            scanf("%d", &x); /* Leitura da opção do usuário */
        } while (x < 1 || x > 2); /* Verificação da validade da opção do usuário */
        if (x == 2) { /* Verificação da opção do usuário */
            break; /* Encerra o loop principal */
        }
    }
    return 0;
}