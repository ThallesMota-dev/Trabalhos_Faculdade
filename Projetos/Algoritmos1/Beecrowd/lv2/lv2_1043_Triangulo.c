/* Leia 3 valores reais (A, B e C) e verifique se eles formam ou não um triângulo.
Em caso positivo, calcule o perímetro do triângulo e apresente a mensagem:

Perimetro = XX.X
Em caso negativo, calcule a área do trapézio que tem A e B como base e C como 
altura, mostrando a mensagem:

Area = XX.X

Entrada
A entrada contém três valores reais.

Saída
O resultado deve ser apresentado com uma casa decimal.*/

# include <stdio.h>
int main() {
    double a, b, c; /* variáveis para armazenar os valores de entrada */
    scanf("%lf %lf %lf", &a, &b, &c); /* leia os valores de a, b e c */
    if (a < b + c && b < a + c && c < a + b) { /* verifique se os valores formam um triângulo usando a desigualdade triangular */
        printf("Perimetro = %.1lf\n", a + b + c); /* se formarem um triângulo, calcule e imprima o perímetro com 1 casa decimal */
    } else { /* caso contrário, calcule a área do trapézio usando as bases A e B e a altura C */
        printf("Area = %.1lf\n", ((a + b) * c) / 2); /* imprima a área do trapézio com 1 casa decimal */
    }
    return 0;
}