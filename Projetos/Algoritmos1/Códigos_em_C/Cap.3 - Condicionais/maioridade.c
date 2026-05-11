#include <stdio.h>
#include <stdbool.h>            /* habilita bool/true/false em C99+ */

#define LIMITE 18               /* equivalente à 'constante LIMITE = 18;' */

int main(void) {
    int idade;
    bool maior;

    printf("Digite com a idade: ");
    scanf("%d", &idade);

    if (idade >= LIMITE)
        maior = true;
    else
        maior = false;

    if (maior)                 /* idêntico em C: bool em contexto condicional */
        printf("É maior de idade.\n");
    else
        printf("É menor de idade.\n");

    return 0;
}