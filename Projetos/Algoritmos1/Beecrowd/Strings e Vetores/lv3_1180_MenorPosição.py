# Faça um programa que leia um valor N. Este N será o tamanho de um vetor X[N]. 
# A seguir, leia cada um dos valores de X, encontre o menor elemento deste vetor 
# e a sua posição dentro do vetor, mostrando esta informação.

# Entrada
# A primeira linha de entrada contem um único inteiro N (1 < N < 1000), indicando 
# o número de elementos que deverão ser lidos em seguida para o vetor X[N] de 
# inteiros. A segunda linha contém cada um dos N valores, separados por um espaço. 
# Vale lembrar que nenhuma entrada haverá números repetidos.

# Saída
# A primeira linha apresenta a mensagem “Menor valor:” seguida de um espaço e do
#  menor valor lido na entrada. A segunda linha apresenta a mensagem “Posicao:” 
# seguido de um espaço e da posição do vetor na qual se encontra o menor valor lido, 
# lembrando que o vetor inicia na posição zero.

# Exemplo de Entrada	
# 10
# 1 2 3 4 -5 6 7 8 9 10

# Exemplo de Saída

# Menor valor: -5
# Posicao: 4

n = int(input()) # lê o número de elementos do vetor
x = list(map(int, input().split())) # lê os elementos do vetor e os armazena em uma lista

menor = x[0] # inicializa a variável menor com o primeiro elemento do vetor
posicao = 0 # inicializa a variável posicao com zero
for i in range (len(x)): # percorre o vetor para encontrar o menor valor e sua posição
	if (x[i] < menor): # se o elemento atual for menor que o menor valor encontrado até agora, atualiza o menor valor e a posição
		menor = x[i] # atualiza o menor valor 
		posicao = i # atualiza a posição

print(f"Menor valor: {menor}") # imprime o menor valor
print(f"Posicao: {posicao}") # imprime a posição do menor valor