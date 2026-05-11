#include <stdio.h>

int main(void) {
    int a;

    printf("Entre com um valor: ");
    scanf("%d", &a);

    if (a == 5) {                 /* '==' em C é comparação; '=' é atribuição */
        printf("Condição Verdadeira\n");
        printf("O valor é %d\n", a);
    }
    printf("Fim do algoritmo.\n");

    return 0;
}