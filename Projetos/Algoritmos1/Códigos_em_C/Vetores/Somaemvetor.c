#include <stdio.h>
int main() {
    int num[5], soma = 0;
    for (int i=0; i<5; i++) {
        printf("Número: ");
        scanf("%d", &num[i]);
        soma += num[i];
    }
    printf("Soma: %d", soma);
    return 0;
}