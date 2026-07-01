# Em uma pacata cidade do interior, o senhor Severino decidiu montar a própria 
# biblioteca, já que coleciona vários livros desde sua juventude. Como ele não 
# sabe programar, pediu ajuda ao neto para criar um programa que cadastre e ordene
# seus livros pelo código. Porém, seu neto ainda está no ensino fundamental, e como
# sabe muito pouco de programação, acabou criando um programa que somente cadastra
# os livros, mas não os ordena.

# Desse modo, o senhor Severino recorreu a você, pois sabe de suas habilidades 
# com programação. Sua tarefa é simples: ordenar os cadastros dos códigos dos livros.

# Entrada
# A entrada contém vários casos de teste. Cada teste começa com um valor N (1 ≤ N ≤ 1000).
#  Em seguida, N linhas terão os códigos dos livros, que estão sempre no formato "xxxx", 
# isto é, não haverá o cadastro '1', por exemplo, mas "0001". A entrada termina com 
# fim de arquivo.

# Saída
# Seu programa deverá imprimir o cadastro dos códigos ordenado. Não haverá linha
#  em branco entre os casos de teste.

# Exemplo de Entrada	
# 3
# 1233
# 0015
# 0100
# 7
# 0752
# 1110
# 0001
# 6322
# 8000
# 6321
# 0000

# Exemplo de Saída

# 0015
# 0100
# 1233
# 0000
# 0001
# 0752
# 1110
# 6321
# 6322
# 8000

while True: # enquanto houver casos de teste
	try: # tente esse algoritmo
		n = int(input()) # leitura do número de livros
		livro = [None] * n # cria um vetor de tamanho n para armazenar os códigos dos livros

		for i in range (n): # lê os códigos dos livros e armazena no vetor
			livro[i] = int(input()) # converte o código do livro para inteiro e armazena no vetor

		for i in range (n-1): # ordena o vetor de códigos dos livros usando o método de ordenação bubble sort
			for j in range (n-1): # compara os elementos adjacentes do vetor
				if (livro[j] > livro[j+1]): # se o elemento atual for maior que o próximo, troca os elementos de posição
					aux = livro[j] # armazena o valor do elemento atual em uma variável auxiliar
					livro[j] = livro[j+1] # atribui o valor do próximo elemento ao elemento atual
					livro[j+1] = aux # atribui o valor da variável auxiliar ao próximo elemento

		for i in range (n): # imprime os códigos dos livros ordenados, formatando-os com 4 dígitos
			print(f"{livro[i]:04d}") # formata o código do livro com 4 dígitos, adicionando zeros à esquerda se necessário
	except: # se ocorrer algum erro (como EOF), sai do loop
		break