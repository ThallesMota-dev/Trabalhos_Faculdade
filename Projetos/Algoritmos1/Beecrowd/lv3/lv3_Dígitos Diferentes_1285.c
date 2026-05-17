#include <stdio.h>
int main() {
    int n, m, i, repetidos, copia, digito, resto, repetiu; /* variáveis para armazenar os valores de entrada e os contadores */
    while (scanf("%d %d", &n, &m) == 2) { /* enquanto houver entrada, leia os valores de n e m */
        repetidos = 0; /* inicialização do contador de números com dígitos diferentes */
        for (i = n; i <= m; i++) { /* para cada número no intervalo [n, m] */
            copia = i; /* faça uma cópia do número para manipulação, igualando a iteração */
            repetiu = 0; /* inicialização do indicador de repetição de dígitos */
            while (copia > 0) { /* enquanto houver dígitos para processar e a cópia for maior que 0 */
                digito = copia % 10; /* extraia o dígito mais à direita */
                copia = copia / 10; /* remova o dígito mais à direita da cópia */
                resto = copia; /* faça uma cópia da cópia para verificar repetição */
                while (resto > 0) { /* enquanto houver dígitos para verificar e o resto for maior que 0 */
                    if (digito == resto % 10) { /* se o dígito atual for igual ao próximo dígito do resto */
                        repetiu = 1; /* marque que houve repetição de dígitos */
                    }
                    resto = resto / 10; /* remova o dígito mais à direita do resto para continuar a verificação */
                }
            }
            if (repetiu == 0) { /* se não houve repetição de dígitos, adicione ao contador de números com dígitos diferentes */
                repetidos++; 
            }
        }
        printf("%d\n", repetidos); /* imprima o contador de números com dígitos diferentes */
    }
    return 0;
}