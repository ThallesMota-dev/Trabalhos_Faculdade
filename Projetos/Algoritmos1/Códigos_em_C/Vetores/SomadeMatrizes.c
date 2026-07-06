#include <stdio.h>
int main() {
    int m1[2][2], m2[2][2], soma[2][2], i, j;
    for (i=0; i<2; i++) {
        for (j=0; j<2; j++) {
            printf("Entrada[%d][%d] Matriz 1: ", i+1, j+1);
            scanf("%d", &m1[i][j]);
        }
    }
    for (i=0; i<2; i++) {
        for (j=0; j<2; j++) {
            printf("Entrada[%d][%d] Matriz 2: ", i+1, j+1);
            scanf("%d", &m2[i][j]);
        }
    }
    for (i=0; i<2; i++) {
        for (j=0; j<2; j++) {
            soma[i][j] = m1[i][j] + m2[i][j];
            printf("%d", soma[i][j]);
        }
        printf("\n");
    }
    return 0;
}