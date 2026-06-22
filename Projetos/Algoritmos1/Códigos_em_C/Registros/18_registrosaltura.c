#include <stdio.h>
typedef struct {
    char nome[51];
    float altura;
} Registros;
int main() {
    Registros dados[15];
    int i, opcao, encontrou;
    float media;
    do {
        printf("1 - Cadastrar os 15 registros\n");
        printf("2 - Apresentar pessoas com 1,5m ou menores\n");
        printf("3 - Apresentar pessoas com mais de 1,5m\n");
        printf("4 - Apresentar pessoas entre 1,5m e 2,0m\n");
        printf("5 - Apresentar todos os registros e média das alturas\n");
        printf("6 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                for (i=0; i<15; i++) {
                    printf("Nome[%d]: ", i+1);
                    scanf("%s", dados[i].nome);
                    printf("Altura[%d]: ", i+1);
                    scanf("%f", &dados[i].altura);
                }
                break;
            case 2:
                encontrou = 0;
                for (i=0; i<15; i++) {
                    if (dados[i].altura <= 1.50) {
                        printf("Nome[%d]: %s | Altura[%d]: %.2f\n", i+1, dados[i].nome, i+1, dados[i].altura);   
                        encontrou = 1;
                    }
                }
                if (encontrou == 0) {
                    printf("Nenhuma altura cumpre o intervalo.");
                }
                break;
            case 3:
                encontrou = 0;
                for (i=0; i<15; i++) {
                    if (dados[i].altura > 1.50) {
                        printf("Nome[%d]: %s | Altura[%d]: %.2f\n", i+1, dados[i].nome, i+1, dados[i].altura);    
                        encontrou = 1;
                    }
                }
                if (encontrou == 0) {
                    printf("Nenhuma altura cumpre o intervalo.");
                }
                break;
            case 4:
                encontrou = 0;
                for (i=0; i<15; i++) {
                    if (dados[i].altura > 1.50 && dados[i].altura < 2.00) {
                        printf("Nome[%d]: %s | Altura[%d]: %.2f\n", i+1, dados[i].nome, i+1, dados[i].altura);    
                        encontrou = 1;
                    }
                }
                if (encontrou == 0) {
                    printf("Nenhuma altura cumpre o intervalo.");
                }
                break;
            case 5:
                media = 0;
                for (i=0; i<15; i++) {
                    printf("Nome[%d]: %s | Altura[%d]: %.2f\n", i+1, dados[i].nome, i+1, dados[i].altura);
                    media += dados[i].altura;
                }
                media /= 15.00;
                printf("Média das alturas: %.2f", media);
                break;
            case 6:
                printf("Saindo...");
                break;
            default:
                printf("Opção Inválida!\n");
                break;
        }
    }
    while (opcao != 6); 
    return 0;
}