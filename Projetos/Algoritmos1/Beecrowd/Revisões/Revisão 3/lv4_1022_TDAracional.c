/*A tarefa aqui neste problema é ler uma expressão matemática na forma de dois 
números Racionais (numerador / denominador) e apresentar o resultado da operação.
 Cada operando ou operador é separado por um espaço em branco. A sequência de 
 cada linha que contém a expressão a ser lida é: número, caractere, número, 
 caractere, número, caractere, número. A resposta deverá ser apresentada e 
 posteriormente simplificada. Deverá então ser apresentado o sinal de igualdade 
 e em seguida a resposta simplificada. No caso de não ser possível uma simplificação,
  deve ser apresentada a mesma resposta após o sinal de igualdade.

Considerando N1 e D1 como numerador e denominador da primeira fração, segue a 
orientação de como deverá ser realizada cada uma das operações:
Soma: (N1*D2 + N2*D1) / (D1*D2)
Subtração: (N1*D2 - N2*D1) / (D1*D2)
Multiplicação: (N1*N2) / (D1*D2)
Divisão: (N1/D1) / (N2/D2), ou seja (N1*D2)/(N2*D1)

Entrada
A entrada contem vários casos de teste. A primeira linha de cada caso de teste 
contem um inteiro N (1 ≤ N ≤ 1*104), indicando a quantidade de casos de teste 
que devem ser lidos logo a seguir. Cada caso de teste contém um valor racional X 
(1 ≤ X ≤ 1000), uma operação (-, +, * ou /) e outro valor racional Y (1 ≤ Y ≤ 1000).

Saída
A saída consiste em um valor racional, seguido de um sinal de igualdade e outro 
valor racional, que é a simplificação do primeiro valor. No caso do primeiro valor 
não poder ser simplificado, o mesmo deve ser repetido após o sinal de igualdade.

Exemplo de Entrada	
4
1 / 2 + 3 / 4
1 / 2 - 3 / 4
2 / 3 * 6 / 6
1 / 2 / 3 / 4

Exemplo de Saída
10/8 = 5/4
-2/8 = -1/4
12/18 = 2/3
4/6 = 2/3*/

#include <stdio.h>
int main () {
    int i, casos;
    char op;
    int N1, N2, D1, D2, num, den, elcnum, elcden, mdc, resto, simpnum, simpden;
    while (scanf("%d", &casos) == 1) { // eof enquanto for somente uma entrada de casos
        for (i=0; i<casos; i++) { // loop para fazer todos os casos
            scanf("%d / %d %c %d / %d", &N1, &D1, &op, &N2, &D2); 
            if (op == '+') { // Se operador é soma
                num = N1*D2 + N2*D1;
                den = D1*D2;
            } else if (op == '-') { // Se operador é subtração
                num = N1*D2 - N2*D1;
                den = D1*D2; 
            } else if (op == '*') { // Se operador é multiplicacao
                num = N1*N2; // mult. entre numeradores
                den = D1*D2; // mult. entre denominadores
            } else if (op == '/') { // Se operador é divisao
                num = N1*D2; // Regra de 3
                den = N2*D1; // Regra de 3
            }
            elcnum = num; // variavel para o algoritmo de elclides do numerador
            if (elcnum < 0) { // Se num negativo, então:
                elcnum = elcnum * (-1); // multiplica por -1 para aplicar o módulo
            }
            elcden = den; // variavel para o algoritmo de elclides do denominador
            while (elcden != 0) { // Algoritmo de Euclides: repete até resto ser zero
                resto = elcnum % elcden; // resto da divisão entre os dois valores
                elcnum = elcden; // divisor vira novo dividendo
                elcden = resto; // resto vira novo divisor
            }
            mdc = elcnum; // quando resto = 0, o MDC está em elcnum
            simpnum = num / mdc; // simplifica numerador dividindo pelo MDC
            simpden = den / mdc; // simplifica denominador dividindo pelo MDC
            printf("%d/%d = %d/%d\n", num, den, simpnum, simpden);
        }
    }
    return 0;
}

/* Alternativa em Python:




*/