#include <stdio.h>
int main () {
    int n, u, d, c, m, invertido;
    printf("Digite um número de 4 dígitos: ");
    scanf("%d", &n);
    u = n % 10; /*resto da divisão por 10 = unidade*/
    d = (n % 100) / 10; /*resto de 100 = du, dividido por 10 = dezena*/
    c = (n % 1000) / 100; /*resto de 1000 = cdu, dividido por 100 = centena*/
    m = n / 1000; /*divisão inteira por 1000 = milhar*/
    invertido = (u * 1000) + (d * 100) + (c * 10) + m;
    printf("Número invertido: %d", invertido);
    return 0;
}