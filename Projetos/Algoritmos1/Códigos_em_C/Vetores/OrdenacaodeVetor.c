#include <stdio.h>
int main() {
    int num[6], i, j, aux;
    for (i=0; i<6; i++) {
        printf("Número: ");
        scanf("%d", &num[i]);
    }
    for (i=0; i<6; i++) {
        for (j=0; j<5; j++) {
            if (num[j] > num[j+1]) {
                aux = num[j];
                num[j] = num[j+1];
                num[j+1] = aux;
            }
        }
    }
    for (i=0; i<6; i++) {
        printf("%d \n", num[i]);
    }
    return 0;
}