#include <stdio.h>
typedef struct {
    char nome[51];
    float salario;
} Tabela;
int main() {
    Tabela cargos[10];
    int i, codigo;
    for (i=0; i<10; i++) {
        printf("Nome[%d]: ", i+1);
        scanf("%s", cargos[i].nome);
        printf("Salário[%d]: ", i+1);
        scanf("%f", &cargos[i].salario);
    }
    do {
        printf("Código do cargo (0 para sair): ");
        scanf("%d", &codigo);
        if (codigo == 0) {
            printf("Saindo...\n");
        } else if (codigo >= 1 && codigo <= 10) {
            printf("Nome: %s | Salário: %.2f\n", 
                cargos[codigo-1].nome, cargos[codigo-1].salario);
        } else {
            printf("Código Inválido!\n");
        }
    }
    while (codigo != 0); 
    return 0;
}