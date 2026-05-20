# Leia um valor inteiro X (1 <= X <= 1000). Em seguida mostre os ímpares de 1 até X,
# um valor por linha, inclusive o X, se for o caso.

# Entrada
# O arquivo de entrada contém 1 valor inteiro qualquer.

# Saída
# Imprima todos os valores ímpares de 1 até X, inclusive X, se for o caso.

X = int(input()) # leitura do valor inteiro X, que representa o limite superior para a geração dos números ímpares.
for i in range(1, X + 1, 2): # loop que itera de 1 até X (inclusive), com um passo de 2, para gerar apenas os números ímpares.
    print(i) # impressão do número ímpar gerado.

# Outro Algoritmo possível, acontece utilizando uma variável para contar a quantidade de números ímpares gerados.

x = int(input()) # leitura do valor inteiro x, que representa o limite superior para a geração dos números ímpares.
impar = 0 # variável para contar a quantidade de números ímpares gerados.
for i in range(1, x + 1, 2): # loop que itera de 1 até x (inclusive), com um passo de 2, para gerar apenas os números ímpares.
	print(i) # impressão do número ímpar gerado.
	impar += 1 # incremento da variável impar para contar a quantidade de números ímpares gerados.
print(impar) # impressão da quantidade total de números ímpares gerados.