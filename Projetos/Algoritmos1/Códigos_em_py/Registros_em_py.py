# Faça um algoritmo que calcule a média ponderada de 40 alunos de
# uma classe sendo que cada aluno possui 4 notas com os seus
# respectivos pesos : 2,3,2,3, após mostre o resultado final de cada um
# dos alunos e diga se ele foi aprovado ou reprovado (a média final é
# 6,0).

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

pesos = [2, 3, 2, 3] # vetor(lista) de pesos em cada posição da nota respectiva
for i in range (40):
    soma_notas = 0
    soma_pesos = 0
    for j in range(4):
        soma_notas += alunos[i].nota[j] * pesos[j] # numerador da média ponderada
        soma_pesos += pesos[j] # denominador da média ponderada
    alunos[i].media = soma_notas / soma_pesos
    
    if (alunos[i].media >= 6.00):
        print(f"Aluno({alunos[i].nome}): Aprovado!")
    else :
        print(f"Aluno({alunos[i].nome}): Reprovado!")