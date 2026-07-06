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
    char L[200][51], N[200][51], S[51], linha[10001], resultado[400][51]; // 200 amigos, cada um com até 50 caracteres + '\0'
    int totalL = 0, totalN = 0, totalR = 0, i, j; // Contadores para as listas L, N e resultado

    // Leitura da lista L
    fgets(linha, 10001, stdin); // Lê a linha completa da lista de amigos L
    char *token = strtok(linha, " \n"); // Tokeniza a linha usando espaço e nova linha como delimitadores
    while (token != NULL) { // Enquanto houver tokens (nomes de amigos) na linha
        strcpy(L[totalL], token); // Copia o token (nome do amigo) para a lista L
        totalL++; // Incrementa o contador de amigos na lista L
        token = strtok(NULL, " \n"); // Continua tokenizando a linha para obter o próximo nome de amigo
    }

    // Leitura da lista N
    fgets(linha, 10001, stdin); // Lê a linha completa da lista de amigos N
    token = strtok(linha, " \n"); // Tokeniza a linha usando espaço e nova linha como delimitadores
    while (token != NULL) { // Enquanto houver tokens (nomes de amigos) na linha
        strcpy(N[totalN], token); // Copia o token (nome do amigo) para a lista N
        totalN++; // Incrementa o contador de amigos na lista N
        token = strtok(NULL, " \n"); // Continua tokenizando a linha para obter o próximo nome de amigo
    }

    scanf("%s", S); // Lê o nome do amigo S que receberá a nova lista de amigos N

    // Monta o resultado
    if (strcmp(S, "nao") == 0) { // Se não houver indicação de amigo, adiciona todos os amigos de L e N na lista resultado
        for (i = 0; i < totalL; i++) { // Adiciona todos os amigos da lista L na lista resultado
            strcpy(resultado[totalR], L[i]); // Copia o amigo da lista L para a lista resultado
            totalR++; // Incrementa o contador de amigos na lista resultado
        }
        for (i = 0; i < totalN; i++) { // Adiciona todos os amigos da lista N na lista resultado
            strcpy(resultado[totalR], N[i]); // Copia o amigo da lista N para a lista resultado
            totalR++; // Incrementa o contador de amigos na lista resultado
        }
    } else { // Se houver indicação de amigo, adiciona os amigos de N antes do amigo indicado S na lista resultado
        for (i = 0; i < totalL; i++) { // Percorre a lista L para encontrar o amigo indicado S 
            if (strcmp(L[i], S) == 0) { // Se o amigo indicado S for encontrado na lista L
                for (j = 0; j < totalN; j++) { // Adiciona todos os amigos da lista N na lista resultado antes do amigo indicado S
                    strcpy(resultado[totalR], N[j]); // Copia o amigo da lista N para a lista resultado
                    totalR++; // Incrementa o contador de amigos na lista resultado
                }
            }
            strcpy(resultado[totalR], L[i]); // Adiciona o amigo da lista L na lista resultado
            totalR++; // Incrementa o contador de amigos na lista resultado
        }
    }

    // Impressão sem espaço extra no final
    for (i = 0; i < totalR; i++) { // Percorre a lista resultado para imprimir os amigos
        if (i == 0) { // Se for o primeiro amigo da lista resultado, imprime sem espaço antes
            printf("%s", resultado[i]); // Imprime o primeiro amigo da lista resultado 
        } else { // Se não for o primeiro amigo da lista resultado, imprime com espaço antes 
            printf(" %s", resultado[i]); // Imprime o amigo da lista resultado com espaço antes
        }
    }
    printf("\n"); // Imprime uma nova linha após a lista de amigos resultado

    return 0;
}