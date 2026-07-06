#include <stdio.h>
int main() {
    int m1[3][3], m2[3][3], mult[3][3], i, j, k;
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            printf("Entrada[%d][%d] Matriz 1: ", i+1, j+1);
            scanf("%d", &m1[i][j]);
        }
    }
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            printf("Entrada[%d][%d] Matriz 2: ", i+1, j+1);
            scanf("%d", &m2[i][j]);
        }
    }
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            mult[i][j] = 0;
            for (k=0; k<3; k++) { /* percorre as linhas de 
                m2(m2[j] fixo) e colunas de m1(m1[i] fixo) */
                mult[i][j] += m1[i][k] * m2[k][j];
            }
            printf("%d ", mult[i][j]);
        }
        printf("\n");
    }
    return 0;
}