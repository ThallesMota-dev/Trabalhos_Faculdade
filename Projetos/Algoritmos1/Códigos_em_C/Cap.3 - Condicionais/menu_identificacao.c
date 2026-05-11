#include <stdio.h>

int main(void) {
    int n1, opcao;

    printf("Entre com o valor a ser testado: ");
    scanf("%d", &n1);
    printf("Você pretende identificar se o número é:\n");
    printf("  Opção 1: Par ou ímpar\n");
    printf("  Opção 2: Positivo, negativo ou 0\n");
    printf("  Opção 3: Bissexto\n");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            if (n1 % 2 == 0)
                printf("Número par.\n");
            else
                printf("Número ímpar.\n");
            break;
        case 2:
            if (n1 > 0)
                printf("Número positivo.\n");
            else if (n1 < 0)
                printf("Número negativo.\n");
            else
                printf("Número 0.\n");
            break;
        case 3:
            if ((n1 % 4 == 0 && n1 % 100 != 0) || (n1 % 400 == 0))
                printf("Ano bissexto.\n");
            else
                printf("Ano não é bissexto.\n");
            break;
        default:
            printf("Opção inválida.\n");
    }

    return 0;
}