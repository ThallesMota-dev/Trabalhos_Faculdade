/* Leia 3 valores de ponto flutuante e efetue o cálculo das raízes da equação de 
Bhaskara. Se não for possível calcular as raízes, mostre a mensagem correspondente
“Impossivel calcular”, caso haja uma divisão por 0 ou raiz de numero negativo.

Entrada
Leia três valores de ponto flutuante (double) A, B e C.

Saída
Se não houver possibilidade de calcular as raízes, apresente a mensagem 
"Impossivel calcular". Caso contrário, imprima o resultado das raízes com 5 dígitos 
após o ponto, com uma mensagem correspondente conforme exemplo abaixo. Imprima 
sempre o final de linha após cada mensagem. */

# include <stdio.h>
# include <math.h>
int main() {
    double a, b, c, delta, r1, r2; /* variáveis para armazenar os valores de entrada e os resultados */
    scanf("%lf %lf %lf", &a, &b, &c); /* leia os valores de a, b e c */
    delta = b * b - 4 * a * c; /* calcule o valor de delta */
    if (delta < 0 || a == 0) { /* verifique se delta é negativo ou se a é zero para determinar se as raízes podem ser calculadas */
        printf("Impossivel calcular\n"); /* se não for possível calcular as raízes, imprima a mensagem correspondente */
    } else { /* caso contrário, calcule as raízes usando a fórmula de Bhaskara */
        r1 = (-b + sqrt(delta)) / (2 * a); /* calcule a primeira raiz */
        r2 = (-b - sqrt(delta)) / (2 * a); /* calcule a segunda raiz */
        printf("R1 = %.5lf\n", r1); /* imprima a primeira raiz com 5 casas decimais */
        printf("R2 = %.5lf\n", r2); /* imprima a segunda raiz com 5 casas decimais */
    }
    return 0;
}