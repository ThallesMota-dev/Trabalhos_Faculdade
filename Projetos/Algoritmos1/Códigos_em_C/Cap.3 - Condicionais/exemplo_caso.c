#include <stdio.h>

int main(void) {
    int n1;

    printf("Entre com o valor a ser testado: ");
    scanf("%d", &n1);

    switch (n1) {
        case 1:
            printf("Valor introduzido é válido: 1\n");
            break;
        case 5:
            printf("Valor introduzido é válido: 5\n");
            break;
        case 10:
            printf("Valor introduzido é válido: 10\n");
            break;
        default:
            printf("Valor inválido: %d\n", n1);
    }

    return 0;
}