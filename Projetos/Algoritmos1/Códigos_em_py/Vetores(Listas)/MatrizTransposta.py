matriz = [[None for i in range (4)]for j in range (4)]
for i in range (4) :
    for j in range (4) :
        matriz[i][j] = int(input("[%d][%d]: " % (i+1,  j+1)))

for i in range (4) :
    for j in range (4) :
        print(matriz[i][j], end = ' ') # não pula linha
    print() # pula linha
    
for i in range (4) :
    for j in range (4) :
        print(matriz[j][i], end = ' ') # não pula linha
    print() # pula linha