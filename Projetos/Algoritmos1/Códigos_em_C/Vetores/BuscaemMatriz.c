#include <stdio.h>
int main() {
    int matriz[4][4], i, j, n, existe = 0;
    for (i=0; i<4; i++) {
        for (j=0; j<4; j++) {
            printf("Entrada[%d][%d]: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("Número n: ");
    scanf("%d", &n);
    for (i=0; i<4; i++) {
        for (j=0; j<4; j++) {
            if (n == matriz[i][j]) {
                    existe = 1;
                    printf("Posição: [%d][%d]\n", i+1, j+1);
            }
        }  
    }
    if (existe == 0) {
        printf("n não está presente na matriz.\n");
    }
    return 0;
}