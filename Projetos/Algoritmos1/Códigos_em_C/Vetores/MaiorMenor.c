#include <stdio.h>
int main() {
    int num[10], maior, menor;
    printf("Primeiro Número: ");
    scanf("%d", &num[0]);
    maior = num[0];
    menor = num[0];
    for (int i=1; i<10; i++) {
        printf("Próximo número: ");
        scanf("%d", &num[i]);
        if (maior < num[i]) {
            maior = num[i];
        }
        if (menor > num[i]) {
            menor = num[i];
        }
    }
    printf("Maior: %d", maior);
    printf("Menor: %d", menor);
    return 0;
}