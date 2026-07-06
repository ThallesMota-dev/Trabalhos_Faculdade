/*Júlio César usava um sistema de criptografia, agora conhecido como Cifra de 
César, que trocava cada letra pelo equivalente em duas posições adiante no 
alfabeto (por exemplo, 'A' vira 'C', 'R' vira 'T', etc.). Ao final do alfabeto 
nós voltamos para o começo, isto é 'Y' vira 'A'. Nós podemos, é claro, tentar 
trocar as letras com quaisquer número de posições.

Entrada
A entrada contém vários casos de teste. A primeira linha de entrada contém um 
inteiro N que indica a quantidade de casos de teste. Cada caso de teste é composto 
por duas linhas. A primeira linha contém uma string com até 50 caracteres maiúsculos 
('A'-'Z'), que é a sentença após ela ter sido codificada através desta Cifra de 
César modificada. A segunda linha contém um número que varia de 0 a 25 e que 
representa quantas posições cada letra foi deslocada para a direita.

Saída
Para cada caso de teste de entrada, imprima uma linha de saída com o texto 
decodificado (transformado novamente para o texto original) conforme as regras 
acima e o exemplo abaixo.

Exemplo de Entrada	
6
VQREQFGT
2
ABCDEFGHIJKLMNOPQRSTUVWXYZ
10
TOPCODER
0
ZWBGLZ
25
DBNPCBQ
1
LIPPSASVPH
4

Exemplo de Saída

TOPCODER
QRSTUVWXYZABCDEFGHIJKLMNOP
TOPCODER
AXCHMA
CAMOBAP
HELLOWORLD*/

#include <stdio.h>
int main() {
    int i, j, N, cifra, nova_letra, num_letra;
    char palavra[51];
    scanf("%d", &N); // lê o número de casos-teste
    for (i=0; i<N; i++) { // loop para realizar o processo o número de casos-teste indicados 
        scanf("%s", palavra); // lê a string com todas as char juntas para aplicar a criptografia
        scanf("%d", &cifra); // lê o número de posições à direita que serão aplicadas na criptografia
        for (j = 0; palavra[j] != '\0'; j++) { // loop da primeira char até a última na str. palavra
            num_letra = palavra[j] - 'A'; // subtrai 65 de ASCII e obtem a ordem de 0 a 25 das letras maiusc.
            nova_letra = (num_letra - cifra + 26) % 26; // operação para achar a posição em ASCII da cifra de cezar
            char resultado = nova_letra + 'A'; // operação para transformar posição em ASCII em char
            printf("%c", resultado); // printf sem espaço nem pulo de linha da char aplicada na cifra de cezar
        }
        printf("\n"); // printf para pular linha para a proxima string a ser lida
    }
    return 0;
}

/*Alternativa em python:

N = int(input())
for i in range(N):
    palavra = input()
    cifra = int(input())
    for c in palavra: # loop para caractere dentro da string palavra
        num_letra = ord(c) - ord('A') # ord() é achar o respectivo em ASCII do char descrito
        nova_letra = (num_letra - cifra + 26) % 26 
        resultado = chr(nova_letra + ord('A')) # chr() é transformar ASCII em char 
        print(resultado, end="") # imprime o resultado da criptorafia e no fim não pula linha 
    print() # pula linha ao fim da letra aplicada à criptografia
*/