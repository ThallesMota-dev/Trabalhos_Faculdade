#include <stdio.h>
#include <math.h>
int main() {
    int vetor[100], i, n;
    double  dp, media, somaQuad = 0, soma = 0;
    printf("Número de inteiros: ");
    scanf("%d", &n);
    
    if (n <= 100) {
        for (i=0; i<n; i++) {
            printf("Qual o valor do vetor: ");
            scanf("%d", &vetor[i]);
            soma += vetor[i]; 
            somaQuad += vetor[i] * vetor[i];
        }
    }
    
    media = soma / n;
    dp = sqrt((somaQuad - n * media * media) / (n - 1));

    printf("Média: %.2lf", media);
    printf("Desvio Padrão: %.2lf", dp);
    
    return 0;
}