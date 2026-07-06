class escola:
    nome = None
    nota = [None] * 4
    media = None

alunos = [escola() for i in range(40)]
for i in range (40):
    alunos[i].nota = [None] * 4
    alunos[i].nome = input(f"Nome do Aluno({i+1:02d}): ")
    for j in range (4):
        alunos[i].nota[j] = float(input(f"Nota({j+1:02d}) do " 
            f"Aluno({alunos[i].nome}): "))

soma_sala = 0
for i in range (40):
    soma_notas = 0
    for j in range(4):
        soma_notas += alunos[i].nota[j] 
    alunos[i].media = soma_notas / 4.00
    print(f"Média do Aluno({alunos[i].nome}): {alunos[i].media}")
    soma_sala += alunos[i].media
    
media_sala = soma_sala / 40.00
print(f"Média da Sala: {media_sala}")