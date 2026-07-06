# Neste problema você deve ler um número, indicando uma linha da matriz na qual 
# uma operação deve ser realizada, um caractere maiúsculo, indicando a operação 
# que será realizada, e todos os elementos de uma matriz M[12][12]. Em seguida, 
# calcule e mostre a soma ou a média dos elementos que estão na área verde da 
# matriz, conforme for o caso. A imagem abaixo ilustra o caso da entrada do valor
#  2 para a linha da matriz, demonstrando os elementos que deverão ser considerados
#  na operação.




# Entrada
# A primeira linha de entrada contem um número L (0 ≤ L ≤ 11) indicando a linha 
# que será considerada para operação. A segunda linha de entrada contém um único 
# caractere Maiúsculo T ('S' ou 'M'), indicando a operação (Soma ou Média) que 
# deverá ser realizada com os elementos da matriz. Seguem os 144 valores de ponto 
# flutuante que compõem a matriz, sendo que a mesma é preenchida linha por linha, 
# da linha 0 até a linha 11, sempre da esquerda para a direita.

# Saída
# Imprima o resultado solicitado (a soma ou média), com 1 casa após o ponto decimal.

# Exemplo de Entrada	
# 2
# S
# 0.0
# -3.5
# 2.5
# 4.1
# ...

# Exemplo de Saída
# 12.6

M = [[None for i in range(12)] for j in range(12)] # matriz 12x12
L = int(input()) # indica a linha da operação
T = input() # (S ou M) soma ou media
for i in range(12):
    for j in range(12):
        M[i][j] = float(input())

if (T == 'S'):
    soma = 0 # inicialização da var. soma
    for i in range(12):
        soma += M[L][i]
    print(f"{soma:.1f}")
elif (T == 'M'):
    soma = 0 
    for i in range(12):
        soma += M[L][i]
    media = soma / 12
    print(f"{media:.1f}")