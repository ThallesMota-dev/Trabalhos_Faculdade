nomes = [None] * 10
for i in range (10) :
    nomes[i] = input("Nome (%d): " % (i+1))
nome_qualquer = input("Nome qualquer: ")

achou = False
for i in range (10) :
    if (nome_qualquer == nomes[i]) :
        achou = True

if (achou) :
    print("Achei")
else :
    print("Não Achei")