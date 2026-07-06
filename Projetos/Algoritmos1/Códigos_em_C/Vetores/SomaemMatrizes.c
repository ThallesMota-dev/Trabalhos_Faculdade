#include <stdio.h>
int main() {
    int matriz[3][3], i, j, soma = 0;
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            printf("Entrada[%d][%d]: \n", i+1, j+1);
            scanf("%d", &matriz[i][j]);
            soma += matriz[i][j];
        }
    }
    printf("Soma: %d\n", soma);
    return 0;
}