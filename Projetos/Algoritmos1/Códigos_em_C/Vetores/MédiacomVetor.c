#include <stdio.h>
int main() {
    float num[7], media = 0;
    for (int i=0; i<7; i++) {
        printf("Número: ");
        scanf("%f", &num[i]);
        media += num[i];
    }
    media /= 7.00;
    printf("Média: %.2f\n", media);
    return 0;
}