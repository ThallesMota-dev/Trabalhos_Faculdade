# Leia 5 valores Inteiros. A seguir mostre quantos valores digitados foram pares,
# quantos valores digitados foram ímpares, quantos valores digitados foram positivos 
# e quantos valores digitados foram negativos.

# Entrada
# O arquivo de entrada contém 5 valores inteiros quaisquer.

# Saída
# Imprima a mensagem conforme o exemplo fornecido, uma mensagem por linha, não 
# esquecendo o final de linha após cada uma.

pares = 0 # Variável acumuladora dos números pares
impares = 0 # Variável acumuladora dos números ímpares
positivos = 0 # Variável acumuladora dos números positivos
negativos = 0 # Variável acumuladora dos números negativos
for i in range(5): # Laço de repetição para ler os 5 números inteiros
	n = int(input()) # Leitura do número inteiro dentro das 5 repetições
	if (n % 2 == 0): # Verificação se o número é par ou ímpar
		pares += 1 # Se o número for par, ele é adicionado à variável acumuladora de números pares
		if (n > 0): # Verificação se o número é positivo ou negativo
			positivos += 1 # Se o número for positivo, ele é adicionado à variável acumuladora de números positivos
		elif (n < 0): # Se o número for negativo, ele é adicionado à variável acumuladora de números negativos
			negativos += 1 # Se o número for negativo, ele é adicionado à variável acumuladora de números negativos
	else: # Se o número não for par, ele é ímpar
		impares += 1 # Se o número for ímpar, ele é adicionado à variável acumuladora de números ímpares
		if (n > 0): # Verificação se o número é positivo ou negativo
			positivos += 1 # Se o número for positivo, ele é adicionado à variável acumuladora de números positivos
		elif (n < 0): # Se o número for negativo, ele é adicionado à variável acumuladora de números negativos
			negativos += 1 # Se o número for negativo, ele é adicionado à variável acumuladora de números negativos
print(f"{pares} valor(es) par(es)") # Impressão do resultado da quantidade de números pares
print(f"{impares} valor(es) impar(es)") # Impressão do resultado da quantidade de números ímpares
print(f"{positivos} valor(es) positivo(s)") # Impressão do resultado da quantidade de números positivos 
print(f"{negativos} valor(es) negativo(s)") # Impressão do resultado da quantidade de números negativos