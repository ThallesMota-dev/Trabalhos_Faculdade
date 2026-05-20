# Leia uma quantidade indeterminada de duplas de valores inteiros X e Y. 
# Escreva para cada X e Y uma mensagem que indique se estes valores foram 
# digitados em ordem crescente ou decrescente.

# Entrada
# A entrada contém vários casos de teste. Cada caso contém dois valores inteiros 
# X e Y. A leitura deve ser encerrada ao ser fornecido valores iguais para X e Y.

# Saída
# Para cada caso de teste imprima “Crescente”, caso os valores tenham sido 
# digitados na ordem crescente, caso contrário imprima a mensagem “Decrescente”.

while True: # loop infinito para processar múltiplos casos de teste, 
	# onde o programa continuará a ler entradas até que uma condição de parada 
    # seja atingida (neste caso, quando os valores de X e Y forem iguais).
	try: # bloco try para tentar ler a entrada e processar os dados.
		x, y = input().split() # leitura da entrada, onde (x e y são os valores inteiros a serem comparados). 
		    # A função split() é usada para separar os valores de x e y, que são lidos como strings.
		x = int(x)
		y = int(y) 
		if (x == y): # verificação se os valores de x e y são iguais. Se a condição for verdadeira, 
			#significa que a leitura deve ser encerrada, e o programa irá quebrar o loop, encerrando a execução. 
			break # quebra do loop quando os valores de x e y forem iguais, encerrando a execução do programa.
		if (x > y): # verificação se o valor de x é maior que o valor de y. Se a condição for verdadeira,
            # significa que os valores foram digitados em ordem decrescente, e o programa
			print("Decrescente") # imprimirá "Decrescente".
		else: # caso contrário, significa que os valores foram digitados em ordem crescente, e o programa
			print("Crescente") # imprimirá "Crescente".
	except: # bloco except para capturar qualquer exceção que possa ocorrer durante a leitura da entrada ou o processamento dos dados.
		break # quebra do loop quando não houver mais entradas para ler, encerrando a execução do programa.