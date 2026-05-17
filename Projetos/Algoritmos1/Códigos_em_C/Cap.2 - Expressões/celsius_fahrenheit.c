#include <stdio.h>
int main () {
    float celsius, fahrenheit;
    printf("Digite a temperatura em C: ");
    scanf("%f", &celsius);
    fahrenheit = (1.8 * celsius) + 32;
    printf("A temperatura em F é: %.2f", fahrenheit);
    return 0;
}