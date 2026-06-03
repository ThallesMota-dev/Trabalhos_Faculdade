# Etapa 1 — Análise do Enunciado
# Um sistema de log registra eventos de uma porta (abriu ou fechou). 
# Cada registro tem três números: hora, minuto e ocorrência. 
# O programa precisa converter isso em texto legível.
# Etapa 2 — Entrada e Saída
# Entrada:

# Linha 1: quantidade de casos de teste
# Próximas linhas: três inteiros H, M, O por linha

# Saída (por caso):

# Formato: HH:MM - A porta abriu! ou HH:MM - A porta fechou!

# Agora olha o exemplo com atenção:

# 15 30 1 → 15:30 - A porta abriu!
# 23 50 0 → 23:50 - A porta fechou!
# 0 5 1 → 00:05 - A porta abriu!

n = int(input()) # quantidade de casos de teste
for i in range (n): # para cada caso de teste
	H, M, O = map(int, input().split()) # H: hora, M: minuto, O: ocorrência (0 ou 1)
	if (O == 0): # se a ocorrência for 0, a porta fechou
		print(f"{H:02d}:{M:02d} - A porta fechou!") # formata a hora e minuto com dois dígitos e imprime a mensagem
	elif (O == 1): # se a ocorrência for 1, a porta abriu
		print(f"{H:02d}:{M:02d} - A porta abriu!") # formata a hora e minuto com dois dígitos e imprime a mensagem
