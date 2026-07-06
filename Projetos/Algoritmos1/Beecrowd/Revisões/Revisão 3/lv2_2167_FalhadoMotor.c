/*Ao observar a curva de velocidade de um motor, o engenheiro Zé percebeu que 
sempre ocorria uma queda quando as medidas eram feitas em intervalos de 10 ms. 
Mas esta queda acontecia em medidas diferentes a cada novo teste do motor.

Zé ficou curioso com essa falta de padrão e quer saber, para cada teste do motor,
 qual a primeira medida em que ocorre uma queda de velocidade.

Entrada
A entrada é um teste do motor e é dada em duas linhas. A primeira tem o número N
 de medidas de velocidade do motor (1 < N ≤ 100). A segunda linha tem N inteiros:
  o número de RPM (rotações por minuto) Ri de cada medida (0 ≤ Ri ≤ 10000, para 
  todo Ri, tal que 1 ≤ i ≤ N). Uma medida é considerada uma queda se é menor que 
  a medida anterior.

Saída
A saída é o índice da medida em que houve a primeira queda de velocidade no teste.
 Caso não aconteça uma queda de velocidade a saída deve ser o número zero.

Exemplos de Entrada	
3
1 4 2

5
100 199 199 198 0

4
1 2 2 2

Exemplos de Saída
3

4

0*/

#include <stdio.h>
int main() {
    int i, N, indice;
    scanf("%d", &N); // leitura do numero de testes
    int RPM[N]; // vetor RPM em função de N
    indice = 0; // inicialização da var. indice
    for (i=0; i<N; i++) { // loop para leitura dos RPM
        scanf("%d", &RPM[i]);
    }
    for (i=1; i<N; i++) { // loop para comparação do entre RPMs e se há queda
        if (RPM[i-1] > RPM[i]) { // Se RPM anterior é maior que o posterior
            indice = i + 1;  // +1 porque o enunciado conta a partir de 1
            break; // achou queda, para         
        }
    }
    printf("%d\n", indice); // imprimir o indice da primeira queda
    return 0;
}

/*Alternativa em python:

N = int(input())
RPM = list(map(int, input().split()))
indice = 0
for i in range(1, N):
    if (RPM[i-1] > RPM[i]):
        indice = i + 1
        break
print(f"{indice}")
*/