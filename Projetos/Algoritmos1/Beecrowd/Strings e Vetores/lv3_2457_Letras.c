/* 
Considere as definições abaixo:

    Uma palavra é uma sequência de letras consecutivas.
    Um texto é um conjunto de palavras separadas pelo caractere espaço em branco.

Você foi contratado pela empresa Booble para escrever um programa que, dados uma 
letra e um texto, determina a porcentagem de palavras do texto que contém a letra dada.

Entrada

A primeira linha da entrada contém um único caractere, a letra de interesse na pesquisa. 
A segunda linha contém um texto, como definido acima. O texto é composto apenas por letras 
minúsculas e o caractere espaço em branco, o texto é formado por no mínimo um caractere, e 
no máximo 1000 caracteres, o texto não contém dois espaços em branco consecutivos.

Saída

Seu programa deve produzir uma única linha, contendo um único número real, a porcentagem 
de palavras do texto que contêm a letra dada, com precisão de uma casa decimal.

Exemplos de Entrada: 	

p 
papagaio 
	
o 
no meio do caminho tinha uma pedra tinha uma pedra no meio do caminho

b 
nunca me esquecerei que no meio do caminho tinha uma pedra

Exemplos de Saída: 

100.0
	
57.1

0.0
*/

#include <stdio.h>
int main() {
    char letra, texto[1001];

    int achou, palavras, palavra_letra, i;
    
    scanf("%c", &letra); // char usa &
    getchar(); // consome o \n depois da letra
    fgets(texto, 1001, stdin); // lê o texto inteiro com espaços

    palavra_letra = 0; // acumuladora de palavras com a letra
    palavras = 1; // conta a primeira 
    achou = 0; // flag de encontro da letra

    for (i=0; texto[i] != '\0'; i++) { 
        if (letra == texto[i]) {
            achou = 1;
        }
        if (texto[i] == ' ') { // for um espaço: palavra terminou
            if (achou == 1) {
                palavra_letra++;
            }
            achou = 0; // reset
            palavras++;
        }
    }
    // a última palavra não termina me espaço
    if (achou == 1) {
        palavra_letra++;
    }

    float porcentagem = (palavra_letra * 100.0) / palavras; // regra de três
    printf("%.1f\n", porcentagem);
    
    return 0;
}