#include <stdio.h>
int main() {
    int num[8], x,  i, igual = 0;
    for (i=0; i<8; i++) {
        printf("Número: \n");
        scanf("%d", &num[i]);
    }
    printf("Número x: ");
    scanf("%d", &x);
    for (i=0; i<8; i++) {
        if (x == num[i]) {
            igual += 1;
            printf("Posição de x: vetor[%d]\n", i);
        }
    }
    if (igual == 0) {
        printf("x não está entre os números.\n");
    }
    return 0;
}