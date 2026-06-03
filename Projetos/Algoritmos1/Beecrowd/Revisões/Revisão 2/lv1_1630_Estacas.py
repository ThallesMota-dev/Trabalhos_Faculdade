# Etapa 1 — Análise do Enunciado

# Terreno retangular com dimensões X e Y. Precisamos cercar com estacas, com 
# duas restrições: a distância entre estacas deve ser sempre igual e o número 
# de estacas deve ser o menor possível.

# Etapa 2 — Descobrindo a lógica

# Pensa assim: se a distância entre estacas deve ser igual em todo o perímetro, 
# esse espaçamento precisa "caber certinho" tanto no lado X quanto no lado Y.
# Qual é o maior valor que divide X e Y ao mesmo tempo? Isso te lembra algum 
# conceito de matemática?

# Verifica com os exemplos:

# X=2, Y=5 → qual o maior divisor comum? 1 → espaçamento = 1 → lado de 2 tem 
# 2 intervalos, lado de 5 tem 5 intervalos → total de estacas = 2×(2+5) = 14 ✓
# X=76, Y=50 → maior divisor comum = 2 → 76/2=38, 50/2=25 → total = 2×(38+25) = 126 ✓

while True: # loop infinito para processar múltiplos casos de teste
	try: # tenta ler os valores de X e Y, se não conseguir (como no caso de EOF), sai do loop 
		X, Y = map(int, input().split()) # lê os valores de X e Y
		a, b = X, Y # para calcular o máximo divisor comum (MDC) usando o algoritmo de Euclides
		while (b != 0): # enquanto b não for zero, continua o processo
			a, b = b, a % b # atualiza a para b e b para o resto da divisão de a por b
		mdc = a # o valor de a após o loop é o MDC de X e Y
		estacas = 2 * (X // mdc + Y // mdc) # calcula o número total de estacas usando o MDC para determinar o espaçamento
		print(f"{estacas}") # imprime o número total de estacas
	except: # se ocorrer um erro (como EOF), sai do loop
		break # encerra o loop infinito