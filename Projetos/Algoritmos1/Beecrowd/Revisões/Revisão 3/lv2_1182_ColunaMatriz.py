# Neste problema você deve ler um número que indica uma coluna de 
# uma matriz na qual uma operação deve ser realizada, um caractere 
# maiúsculo, indicando a operação que será realizada, e todos os 
# elementos de uma matriz M[12][12]. Em seguida, calcule e mostre 
# a soma ou a média dos elementos que estão na área verde da matriz,
# conforme for o caso. A imagem abaixo ilustra o caso da entrada 
# do valor 5 para a coluna da matriz, demonstrando os elementos 
# que deverão ser considerados na operação.

# Entrada
# A primeira linha de entrada contem um número C (0 ≤ C ≤ 11) 
# indicando a coluna que será considerada para operação. A segunda 
# linha de entrada contém um único caractere Maiúsculo T ('S' ou 'M'),
# indicando a operação (Soma ou Média) que deverá ser realizada com 
# os elementos da matriz. Seguem os 144 valores de ponto flutuante 
## que compõem a matriz.

# Saída
# Imprima o resultado solicitado (a soma ou média), com 1 casa após 
# o ponto decimal.

# Exemplo de Entrada	
# 5
# S
# 0.0
# -3.5
# 2.5
# 4.1
# ...

# Exemplo de Saída
# 12.6*/

M = [[None for i in range(12)] for j in range(12)] # Inicializando Matriz 12x12
C = int(input()) # ler número da coluna das operações (0 ≤ C ≤ 11)
T = input() # ler caractere da operação (Soma ou Média)
for i in range (12): # loop para leitura das linhas da matriz
    for j in range (12): # loop para leitura das colunas da matriz
        M[i][j] = float(input()) # ler os elementos(float) da matriz

if (T == 'S'): # Se a operação for Soma 
    soma = 0 # inicializando variável soma
    for i in range (12): # loop para percorrer as linhas da matriz
        soma += M[i][C] # somando os elementos da coluna C
    print(f"{soma:.1f}") # imprimindo o resultado da soma com 1 casa decimal à direita do ponto
elif (T == 'M'): # Se a operação for Média
    soma = 0 # inicializando a variável soma
    for i in range (12): # loop para percorrer as linhas da matriz
        soma += M[i][C] # somando os elementos da coluna C
    media = soma / 12 # média = soma dos elem. dividido pelo núm. de elem.
    print(f"{media:.1f}") # imprimindo o resultado da média com 1 casa decimal à direita do ponto

# código alternativo em C:
# #include <stdio.h>
# int main() {
#    int C, i, j;
#    char T;
#    float M[12][12], soma = 0.0;
#    scanf("%d", &C);
#    scanf("%c", &T);
#    for (i=0; i<12; i++) {
#       for (j=0; j<12; j++) {
#          scanf("%f", &M[i][j]);
#       }
#    }
#    if (T == 'S') {
#       soma = 0;
#       for (i=0; i<12; i++) {
#          soma += M[i][C];
#          printf("%.1f\n", soma);
#    } else if (T == 'M') {
#       soma = 0;
#       for (i=0; i<12; i++) {
#          soma += M[i][C];
#          printf("%.1f\n", soma / 12);
#       }
#    }
#    return 0;
# }       