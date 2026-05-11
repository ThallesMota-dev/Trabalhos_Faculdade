#include <stdio.h>

int main(void) {
    int n1, n2;

    printf("Entre com o primeiro valor: ");
    scanf("%d", &n1);
    printf("Entre com o segundo valor: ");
    scanf("%d", &n2);

    if (n1 > n2)
        printf("O valor maior é: %d\n", n1);
    else
        printf("O valor maior é: %d\n", n2);

    return 0;
}