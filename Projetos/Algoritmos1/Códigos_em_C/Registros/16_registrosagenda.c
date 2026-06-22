#include <stdio.h>
#include <string.h>
typedef struct {
    char nome[51];
    char endereco[101];
    int telefone;
} Agenda;
int main() {
    Agenda registros[10], aux_reg;
    char busca[51];
    int i, j, opcao, total_reg = 0, encontrou;
    do {
        printf("1 - Cadastrar registro\n");
        printf("2 - Pesquisar registro por nome\n");
        printf("3 - Ordenar os nomes cadastrados\n");
        printf("4 - Visualizar todos os registros\n");
        printf("5 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (total_reg == 10) {
                    printf("Limite de registros atingido!");
                    break;
                }
                
                printf("Nome: ");
                scanf("%s", registros[total_reg].nome);
                printf("Endereço: ");
                scanf("%s", registros[total_reg].endereco);
                printf("Telefone: ");
                scanf("%d", &registros[total_reg].telefone);
                total_reg++;
                break;
            case 2:
                printf("Nome buscado: ");
                scanf("%s", busca);
                encontrou = 0;
                for (i=0; i<total_reg; i++) {
                    if (strcmp(registros[i].nome, busca) == 0) {
                        printf("Endereço: %s | Telefone: %d\n", registros[i].endereco, registros[i].telefone);
                        encontrou = 1;
                        break;
                    }
                }
                if (encontrou == 0) {
                    printf("Registro não encontrado!");
                }
                break;
            case 3:
                for (i=0; i < total_reg - 1; i++) {
                    for (j=0; j < total_reg - 1; j++) {
                        if (strcmp(registros[j].nome, registros[j+1].nome) > 0) {
                            aux_reg = registros[j];
                            registros[j] = registros[j+1];
                            registros[j+1] = aux_reg;
                        }
                    }
                }
                break;
            case 4:
                for (i=0; i < total_reg; i++) {
                    printf("Nome: %s\n", registros[i].nome);
                    printf("Endereço: %s\n", registros[i].endereco);
                    printf("Telefone: %d\n", registros[i].telefone);
                }
                break;
            case 5:
                printf("Saindo...");
                break;
            default:
                printf("Opção Inválida!\n");
                break;
        }
    }
    while (opcao != 5); 
    return 0;
}