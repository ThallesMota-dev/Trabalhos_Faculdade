# Leia 6 valores. Em seguida, mostre quantos destes valores digitados foram positivos. 
# Na próxima linha, deve-se mostrar a média de todos os valores positivos digitados, 
# com um dígito após o ponto decimal.

# Entrada
# A entrada contém 6 números que podem ser valores inteiros ou de ponto flutuante. 
# Pelo menos um destes números será positivo.

# Saída
# O primeiro valor de saída é a quantidade de valores positivos. A próxima 
# linha deve mostrar a média dos valores positivos digitados.

acum = 0 # contador de positivos
positivos = 0 # acumula a soma dos positivos para calcular a média depois
for i in range(6): # para ler os 6 valores
	n = float(input()) # lê o valor, pode ser inteiro ou de ponto flutuante, por isso float
	if (n > 0): # se o valor for positivo, acumula a quantidade e a soma
		acum += 1 # acumula a quantidade de positivos
		positivos += n # acumula a soma dos positivos para calcular a média depois
print(f"{acum} valores positivos") # imprime a quantidade de positivos
print(f"{positivos / acum:.1f}") # imprime a média dos positivos, dividindo a soma dos positivos pela quantidade de positivos, com 1 dígito após o ponto decimal