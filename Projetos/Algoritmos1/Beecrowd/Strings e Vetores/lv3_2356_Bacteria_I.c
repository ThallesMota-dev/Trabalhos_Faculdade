/* Dr. Henrique realmente adora suas pesquisas com bactérias. Na tentativa de 
criar bactérias mais resistentes a antibióticos, avaliou o DNA de algumas delas
 e percebeu uma semelhança nas bactérias que eram mais resistentes do que as 
 demais. Todas elas possuiam uma parte do código genético igual (composto pelas 
 proteínas A, C, G, T). Logo constatou que aquele trecho de código genético é o 
 que define se uma bactéria é resistente ou não. Assim, Dr. Henrique pediu para 
 que você fizesse um programa que avalie se uma bactéria é resistente dado seu 
 DNA e o código genético que leva a resistência.

Entrada
Cada caso teste contém duas strings, D e S, cada qual em uma linha, e representam 
o DNA da bactéria e a sequência de código genético que leva a resistência. 
1 ≤ |D|, |S| ≤ 100. As strings são compostas apenas pelos caracteres: A, C, G, T.

Saída
Imprima uma linha por cada caso teste, contendo a string "Resistente" (sem aspas) 
caso a bactéria possua o código genético requerido em seu DNA, ou a string 
"Nao resistente" (sem aspas) caso contrário.

Exemplo de Entrada	
ACGTC
CGT
CCCT
AG

Exemplo de Saída

Resistente
Nao resistente
*/

#include <stdio.h>
#include <string.h>
int main() {
    char D[101], S[101]; // tamanho máximo de 100 caracteres + 1 para o terminador nulo
    while (scanf("%s", D) == 1) { // lê o DNA da bactéria, continua enquanto houver entrada
        scanf("%s", S); // lê a sequência de código genético que leva a resistência
        if (strstr(D, S) != NULL) { // verifica se S é uma substring de D
            printf("Resistente\n");
        } else {
            printf("Nao resistente\n");
        }
    }
    return 0;
}