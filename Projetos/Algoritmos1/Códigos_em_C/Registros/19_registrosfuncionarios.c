#include <stdio.h>
typedef struct {
    char nome[51];
    int matricula;
    float salario;
} Trabalho;
int main() {
    Trabalho dados[20], aux;
    int busca;
    int i, j, opcao, encontrou;
    do {
        printf("1 - Cadastrar os 20 funcionários.\n");
        printf("2 - Classificar os registros por matrícula.\n");
        printf("3 - Pesquisar um funcionário por número de matrícula\n");
        printf("4 - Apresentar ordenadamente os funcionários com salários acima de R$ 1.000\n");
        printf("5 - Apresentar ordenadamente os funcionários com salários abaixo de R$ 1.000\n");
        printf("6 - Apresentar ordenadamente os funcionários com salários de R$ 1.000\n");
        printf("7 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                for (i=0; i<20; i++) {
                    printf("Matrícula[%d]: ", i+1);
                    scanf("%d", &dados[i].matricula);
                    printf("Nome[%d]: ", i+1);
                    scanf("%s", dados[i].nome);
                    printf("Salário[%d]: ", i+1);
                    scanf("%f", &dados[i].salario);
                }
                break;
            case 2:
                for (i=0; i<20; i++) {
                    for (j=0; j<19; j++) {
                        if (dados[j].matricula > dados[j+1].matricula) {
                            aux = dados[j];
                            dados[j].matricula = dados[j];
                            dados[j+1] = aux;
                        }
                    }
                }
                break;
            case 3:
                printf("Matrícula buscada: ");
                scanf("%d", &busca);
                encontrou = 0;
                for (i=0; i<20; i++) {
                    if (dados[i].matricula == busca) {
                        printf("Matrícula[%d]: %d", i+1, dados[i].matricula);
                        encontrou = 1;
                        break;
                    }
                }
                if (encontrou == 0) {
                    printf("Matrícula não encontrada!");
                }
                break;
            case 4:
                for (i=0; i<20; i++) {
                    for (j=0; j<19; j++) {
                        if (dados[j].salario > dados[j+1].salario) {
                            aux = dados[j];
                            dados[j].matricula = dados[j];
                            dados[j+1] = aux;
                        }
                    }
                }
                encontrou = 0;
                for (i=0; i<20; i++) {
                    if (dados[i].salario > 1000.00) {
                        printf("Salário[%d]: %.2f", i+1, dados[i].salario);
                        encontrou = 1;
                    }
                }
                if (encontrou == 0) {
                    printf("Nenhum salário é maior que R$1.000");
                }
                break;
            case 5:
                for (i=0; i<20; i++) {
                    for (j=0; j<19; j++) {
                        if (dados[j].salario > dados[j+1].salario) {
                            aux = dados[j];
                            dados[j].matricula = dados[j];
                            dados[j+1] = aux;
                        }
                    }
                }
                encontrou = 0;
                for (i=0; i<20; i++) {
                    if (dados[i].salario < 1000.00) {
                        printf("Salário[%d]: %.2f", i+1, dados[i].salario);
                        encontrou = 1;
                    }
                }
                if (encontrou == 0) {
                    printf("Nenhum salário é menor que R$1.000");
                }
                break;
            case 6:
                for (i=0; i<20; i++) {
                    for (j=0; j<19; j++) {
                        if (dados[j].salario > dados[j+1].salario) {
                            aux = dados[j];
                            dados[j].matricula = dados[j];
                            dados[j+1] = aux;
                        }
                    }
                }
                encontrou = 0;
                for (i=0; i<20; i++) {
                    if (dados[i].salario >= 999.99 && dados[i].salario <= 1000.01) {
                        printf("Salário[%d]: %.2f", i+1, dados[i].salario);
                        encontrou = 1;
                    }
                }
                if (encontrou == 0) {
                    printf("Nenhum salário é igual a R$1.000");
                }
                break;
            case 7:
                printf("Saindo...");
                break;
            default:
                printf("Opção Inválida!\n");
                break;
        }
    }
    while (opcao != 7); 
    return 0;
}