#include <stdio.h>
#include <string.h>
typedef struct {
    char nome[51];
    float notas[4];
} Escola;
int main() {
    Escola alunos[20], aux;
    char busca[51];
    int i, j, opcao, total_alunos = 0, encontrou, aprovado;
    float media;
    do {
        printf("1 - Cadastrar os 20 alunos e classificar por nome\n");
        printf("2 - Pesquisar registro por nome\n");
        printf("3 - Ordenar os nomes cadastrados\n");
        printf("4 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                for (i=0; i<20; i++) {
                    printf("Nome[%d]: ", i+1);
                    scanf("%s", alunos[i].nome);
                    for (j=0; j<4; j++) {
                        printf("Nota[%d]: ", j+1);
                        scanf("%f", &alunos[i].notas[j]);
                    }
                }
                total_alunos = 20;
                for (i=0; i < total_alunos - 1; i++) {
                    for (j=0; j < total_alunos - 1; j++) {
                        if (strcmp(alunos[j].nome, alunos[j+1].nome) > 0) {
                            aux = alunos[j];
                            alunos[j] = alunos[j+1];
                            alunos[j+1] = aux;
                        }
                    }
                }
                break;
            case 2:
                printf("Nome buscado: ");
                scanf("%s", busca);
                encontrou = 0;
                aprovado = 0;
                media = 0;
                for (i=0; i<total_alunos; i++) {
                    if (strcmp(alunos[i].nome, busca) == 0) {
                        for (j=0; j<4; j++) {
                            media += alunos[i].notas[j];
                        }
                        media /= 4.00;
                        if (media >= 5.00) {
                            printf("Aprovado");
                            aprovado = 1;
                        } else {
                            printf("Reprovado");
                        }
                        encontrou = 1;
                        break;
                    }
                }
                if (encontrou == 0) {
                    printf("Aluno não encontrado!");
                }
                break;
            case 3:
                for (i = 0; i < total_alunos; i++) {
                    media = 0;
                    for (j = 0; j < 4; j++) {
                        media += alunos[i].notas[j];
                    }
                    media /= 4;
                    if (media >= 5.00) {
                        printf("Aluno: %s | Média: %.2f | Aprovado\n", alunos[i].nome, media);
                    } else {
                        printf("Aluno: %s | Média: %.2f | Reprovado\n", alunos[i].nome, media);
                    }
                }
                break;
            case 4:
                printf("Saindo...");
                break;
            default:
                printf("Opção Inválida!\n");
                break;
        }
    }
    while (opcao != 4); 
    return 0;
}