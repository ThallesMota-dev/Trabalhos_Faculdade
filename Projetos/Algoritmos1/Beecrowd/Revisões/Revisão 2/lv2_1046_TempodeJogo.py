# Etapa 1 — Análise do Enunciado
# Um jogo tem hora de início e hora de fim. O jogo pode começar num dia e terminar 
# no outro (ex: começa 16h, termina 2h). Duração mínima de 1 hora e máxima de 24 horas.
# Etapa 2 — Descobrindo a lógica
# Olha os exemplos:

# Início=16, Fim=2 → duração 10 (passou da meia-noite)
# Início=0, Fim=0 → duração 24 (mesmo horário = jogo completo de 24h)
# Início=2, Fim=16 → duração 14 (simples subtração)

i, f = map(int, input().split()) # i = hora inicial, f = hora final
if (f>i): # se a hora final for maior que a hora inicial, o jogo durou a diferença entre as horas
	duracao = f - i # duracao = hora final - hora inicial
else : # se a hora final for menor ou igual a hora inicial, o jogo durou a diferença entre as horas mais 24 horas (pois o jogo pode ter começado em um dia e terminado em outro)
	duracao = (24 - i) + f # duracao = (24 - hora inicial) + hora final
print(f"O JOGO DUROU {duracao} HORA(S)") # imprime a duração do jogo conforme o formato solicitado