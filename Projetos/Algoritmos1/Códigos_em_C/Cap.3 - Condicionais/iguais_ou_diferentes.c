#include <stdio.h>

int main(void) {
    int n1, n2, n3;

    printf("Entre com o primeiro valor: ");
    scanf("%d", &n1);
    printf("Entre com o segundo valor: ");
    scanf("%d", &n2);
    printf("Entre com o terceiro valor: ");
    scanf("%d", &n3);

    if (n1 == n2) {
        if (n2 == n3)
            printf("Os três valores são iguais\n");
        else
            printf("Há dois valores iguais e um diferente\n");
    } else {                               /* n1 != n2 */
        if (n1 == n3)
            printf("Há dois valores iguais e um diferente\n");
        else if (n2 == n3)                 /* n1 != n3 */
            printf("Há dois valores iguais e um diferente\n");
        else                               /* n2 != n3 */
            printf("Todos os valores são diferentes\n");
    }
    printf("Fim do programa.\n");

    return 0;
}