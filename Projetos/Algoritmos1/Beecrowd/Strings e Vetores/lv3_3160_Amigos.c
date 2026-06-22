/* Luiggy gosta de fazer amizades e sempre está expandindo sua lista de amigos 
na rede social ListBook. O ListBook permite que você inclua seus novos amigos 
em sua lista de amizade e os indique também para outros amigos da sua rede, 
tudo isso dinamicamente, sem limites de amigos na sua rede. Como Luiggy é seu 
amigo, ele pediu que você criasse um programa para facilitar a vida dele com 
esta tarefa. Para isso, Luiggy teve a seguinte ideia:

O programa deverá ler a lista atual de amigos de Luiggy;
O programa deverá ler a nova lista de amigos de Luiggy;
O programa deverá ler o nome do amigo atual que receberá a nova lista como indicação de amigos.

Entrada
Você deve ler em uma única linha a lista de amigos de Luiggy L, contendo somente
 o primeiro nome e separados por um espaço em branco. Na segunda linha deve ser
  informada a nova lista de amigos N. Na última linha, o nome do amigo S da rede 
  que deseja indicar também essa nova lista de amigos N. Caso não queira indicar 
  para ninguém a nova lista de amigos, basta digitar na última linha a palavra “nao”.

Saída
Seu programa deverá exibir a nova lista de amigos de Luiggy atualizada. Se houver 
indicação de um amigo da lista, os novos amigos deverão ser inseridos antes do nome 
do amigo indicado. Caso não haja indicação, os novos nomes deverão ser inseridos 
no fim da lista de amigos de Luiggy.

Exemplos de Entrada	
Jones Pedro Carlos Lucas

Juca Valdineia Jovander

Carlos

Jones Pedro Carlos Lucas

Juca Valdineia Jovander

nao

Exemplos de Saída

Jones Pedro Juca Valdineia Jovander Carlos Lucas

Jones Pedro Carlos Lucas Juca Valdineia Jovander*/

#include <stdio.h>
#include <string.h>
int main() {
    char L[200][51], N[200][51], S[51], linha[10001], resultado[400][51];
    int totalL = 0, totalN = 0, totalR = 0, i, j;

    // Leitura da lista L
    fgets(linha, 10001, stdin);
    char *token = strtok(linha, " \n");
    while (token != NULL) {
        strcpy(L[totalL], token);
        totalL++;
        token = strtok(NULL, " \n");
    }

    // Leitura da lista N
    fgets(linha, 10001, stdin);
    token = strtok(linha, " \n");
    while (token != NULL) {
        strcpy(N[totalN], token);
        totalN++;
        token = strtok(NULL, " \n");
    }

    scanf("%s", S);

    // Monta o resultado
    if (strcmp(S, "nao") == 0) {
        for (i = 0; i < totalL; i++) {
            strcpy(resultado[totalR], L[i]);
            totalR++;
        }
        for (i = 0; i < totalN; i++) {
            strcpy(resultado[totalR], N[i]);
            totalR++;
        }
    } else {
        for (i = 0; i < totalL; i++) {
            if (strcmp(L[i], S) == 0) {
                for (j = 0; j < totalN; j++) {
                    strcpy(resultado[totalR], N[j]);
                    totalR++;
                }
            }
            strcpy(resultado[totalR], L[i]);
            totalR++;
        }
    }

    // Impressão sem espaço extra no final
    for (i = 0; i < totalR; i++) {
        if (i == 0) {
            printf("%s", resultado[i]);
        } else {
            printf(" %s", resultado[i]);
        }
    }
    printf("\n");

    return 0;
}