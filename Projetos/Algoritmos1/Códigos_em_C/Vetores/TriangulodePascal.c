#include <stdio.h>
int main() {
    unsigned int n;
    printf("Número n de linhas: \n");
    scanf("%u", &n);
    int i, j, tri[n][n];
    for (i=0; i<n; i++) {
        for (j=0; j<=i; j++) {
            if (j == 0 || j == i) { /* O primeiro e o último elemento de cada linha são sempre 1 */
                tri[i][j] = 1;
            } else { /* Cada elemento do meio é a soma dos dois elementos acima dele na linha anterior */
                tri[i][j] = tri[i-1][j-1] + tri[i-1][j];
            }
            printf("%d ", tri[i][j]);
        } /* fim da linha i, quebra para a próxima */
        printf("\n");
    }
    return 0;
}