# Leia um valor inteiro N. Apresente todos os números entre 1 e 10000 que divididos por N dão resto igual a 2.

# Entrada
# A entrada contém um valor inteiro N (N < 10000).

# Saída
# Imprima todos valores que quando divididos por N dão resto = 2, um por linha.

n = int(input()) # Lê o valor inteiro N
for i in range(1, 10001): # Itera de 1 a 10000
	if (i % n == 2): # Verifica se o resto da divisão de i por n é igual a 2
		print(i) # Imprime o valor de i que satisfaz a condição, um por linha