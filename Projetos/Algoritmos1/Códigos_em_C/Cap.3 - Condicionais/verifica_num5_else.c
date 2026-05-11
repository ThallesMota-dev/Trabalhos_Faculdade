#include <stdio.h>

int main() {
    int a;

    printf("Entre com um valor: ");
    scanf("%d", &a);

    if (a == 5) {
        printf("Condição Verdadeira\n");
        printf("O valor é %d\n", a);
    } else {
        printf("Condição Falsa\n");
        printf("O valor não é 5, é %d\n", a);
    }

    printf("Fim do algoritmo.\n");

    return 0;
}