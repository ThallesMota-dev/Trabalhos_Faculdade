# Leia 1 valor inteiro N (2 < N < 1000). A seguir, mostre a tabuada de N:      
# 1 x N = N      2 x N = 2N        ...       10 x N = 10N

# Entrada
# A entrada contém um valor inteiro N (2 < N < 1000).

# Saída
# Imprima a tabuada de N, conforme o exemplo fornecido.

n = int(input()) # Lê o valor inteiro N
for i in range(1, 11): # Loop de 1 a 10 para calcular a tabuada
	resultado = i * n  # Calcula o resultado da multiplicação
	print(f"{i} x {n} = {resultado}") # Imprime a tabuada no formato solicitado