# Leia um caractere maiúsculo, que indica uma operação que deve 
# ser realizada e uma matriz M[12][12]. Em seguida, calcule e 
# mostre a soma ou a média considerando somente aqueles elementos 
# que estão abaixo da diagonal principal da matriz, conforme 
# ilustrado abaixo (área verde).

# Entrada
# A primeira linha de entrada contem um único caractere 
# Maiúsculo O ('S' ou 'M'), indicando a operação (Soma ou Média) 
# que deverá ser realizada com os elementos da matriz. Seguem os 
# 144 valores de ponto flutuante que compõem a matriz.

# Saída
# Imprima o resultado solicitado (a soma ou média), com 1 casa 
# após o ponto decimal.

# Exemplo de Entrada	
# S
#  1.0
# 0.0
# -3.5
# 2.5
# 4.1
# ...

# Exemplo de Saída
# 12.6

M = [[None for i in range(12)] for j in range(12)] # Inicializando Matriz 12x12
O = input() # ler caractere da operação (Soma ou Média)
for i in range (12): # loop para leitura das linhas da matriz
    for j in range (12): # loop para leitura das colunas da matriz
        M[i][j] = float(input()) # ler os elementos(float) da matriz

if (O == 'S'): # Se a operação for Soma
    soma = 0 # inicializando variável soma
    for i in range (12): # loop para percorrer as linhas da matriz
        for j in range (12): # loop para percorrer as colunas da matriz
            if (i > j): # apenas elem. abaixo da diagonal principal
                soma += M[i][j] # operação de soma dos elementos abaixo d. p.
    print(f"{soma:.1f}") # imprimindo o resultado da soma com 1 casa decimal à direita do ponto
elif (O == 'M'): # Se a operação for Média
    soma = 0 # inicializando a variável soma
    acum = 0 # inicializando a variável acumuladora de elementos
    for i in range (12): # loop para percorrer as linhas da matriz
        for j in range (12): # loop para percorrer as colunas da matriz
            if (i > j): # apenas elem. abaixo da diagonal principal
                soma += M[i][j] # operação de soma dos elementos abaixo d. p.
                acum += 1 # incrementando a variável acumuladora
    if (acum > 0): # verificando se há elementos abaixo da diagonal principal
        media = soma / acum # calculando a média
    print(f"{media:.1f}") # imprimindo o resultado da média com 1 casa decimal à direita do ponto

# alternativa em C:
# #include <stdio.h>
# int main () {
#   char O;
#   float M[12][12], soma, media;
#   int i, j, acum;
#   scanf("%c", &O);
#   for (i=0; i<12; i++) {
#       for (j=0; j<12; j++) {
#           scanf("%f", &M[i][j]);
#       }
#   if (O == 'S') {
#       soma = 0.0;
#       for (i=0; i<12; i++) {
#           for (j=0; j<12; j++) {
#               if (i > j) {
#                   soma += M[i][j];
#       printf("%.1f\n", soma);
#   } else if (O == 'M') {
#       soma = 0.0;
#       acum = 0;
#       for (i=0; i<12; i++) {
#           for (j=0; j<12; j++) {
#               if (i > j) {
#                   soma += M[i][j];
#                   acum += 1;
#       if (acum > 0) {
#           media = soma / acum;
#           printf("%.1f\n", media);
#       }
#   }
#   return 0;
# }   