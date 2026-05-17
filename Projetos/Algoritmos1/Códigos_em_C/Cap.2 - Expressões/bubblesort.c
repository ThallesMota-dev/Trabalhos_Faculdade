#include <stdio.h>
int main () {
    int a, b, aux;
    printf("Digite 2 números: ");
    scanf("%d %d", &a, &b);
    aux = a;
    a = b;
    b = aux;
    printf("valores invertidos de a e b: %d %d", a, b);
    return 0;
}
