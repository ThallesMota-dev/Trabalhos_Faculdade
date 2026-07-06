#include <stdio.h>
int main() {
    int m1[3][3], quad[3][3], i, j, k;
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            printf("Entrada[%d][%d]: ", i+1, j+1);
            scanf("%d", &m1[i][j]);
        }
    }
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            quad[i][j] = 0;
            for (k=0; k<3; k++) { /* percorre as linhas e colunas 
                de m1 */
                quad[i][j] += m1[i][k] * m1[k][j];
            }
            printf("%d ", quad[i][j]);
        }
        printf("\n");
    }
    return 0;
}