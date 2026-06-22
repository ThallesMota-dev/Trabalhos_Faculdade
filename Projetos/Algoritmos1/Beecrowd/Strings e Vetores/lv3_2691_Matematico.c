/*No Instituto Federal do Sul de Minas, na cidade de Muzambinho, há um matemático 
realizando uma pesquisa maluca. Ele está prestes a encontrar a fórmula da juventude. 
Depois de vários testes ele descobriu dados que o deixaram maluco, um deles foi que: 
quanto mais você coda mais ele rejuvenesce. Por enquanto a fórmula está em desenvolvimento 
e ele te contratou para ajudá-lo na pesquisa, pois após tanto trabalho esqueceu-se de 
alguns princípios da matemática, como metade da tabuada, e pediu para você construir a 
tabuada com os números que ele precisa. 

Entrada
O primeiro número N é um inteiro indicando quantas vezes seu programa será testado.
 Em seguida mais dois inteiros X e Y que serão os números a ser multiplicados.

Saída
Seu programa deve exibir a multiplicação dos dois números, exceto quando forem 
iguais, nesse caso sem os "&&".

Exemplo de Entrada	

1
4x5

Exemplo de Saída

4 x 5 = 20 && 5 x 5 = 25
4 x 6 = 24 && 5 x 6 = 30
4 x 7 = 28 && 5 x 7 = 35
4 x 8 = 32 && 5 x 8 = 40
4 x 9 = 36 && 5 x 9 = 45
4 x 10 = 40 && 5 x 10 = 50
*/

#include <stdio.h>
int main() {
    int n, i, j, x, y, inicio, aux;
    scanf("%d", &n); // lê o número de testes
    for (i=0; i<n; i++) {  // para cada teste
        scanf(" %dx%d", &x, &y); // lê os números X e Y no formato "XxY"
        for (j=5; j<=10; j++) { // para cada número de início até 10
            if (x == y) {
                printf("%d x %d = %d\n", x, j, x * j);
            } else {
                printf("%d x %d = %d && %d x %d = %d\n", x, j, x * j, y, j, y * j);
            }
        }
    }
    return 0;
}