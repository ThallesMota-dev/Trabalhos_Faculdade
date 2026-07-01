# Escreva um algoritmo que leia um inteiro N (0 ≤ N ≤ 100), correspondente a 
# ordem de uma matriz M de inteiros, e construa a matriz de acordo com o exemplo 
# abaixo.

# Entrada
# A entrada consiste de vários inteiros, um valor por linha, correspondentes as 
# ordens das matrizes a serem construídas. O final da entrada é marcado por um 
# valor de ordem igual a zero (0).

# Saída
# Para cada inteiro da entrada imprima a matriz correspondente, de acordo com o 
# exemplo. (os valores das matrizes devem ser formatados em um campo de tamanho 
# 3 justificados à direita e separados por espaço. Após o último caractere de 
# cada linha da matriz não deve haver espaços em branco. Após a impressão de 
# cada matriz deve ser deixada uma linha em branco.

# Exemplo de Entrada
# 1
# 2
# 3
# 4
# 5
# 0

# Exemplo de Saída

# 1
# 1   2
# 2   1

# 1   2   3
# 2   1   2
# 3   2   1

# 1   2   3   4
# 2   1   2   3
# 3   2   1   2
# 4   3   2   1

# 1   2   3   4   5
# 2   1   2   3   4
# 3   2   1   2   3
# 4   3   2   1   2
# 5   4   3   2   1

while True: # repetição infinita para ler os valores de n
    try: # enquanto houver valores de n, o programa continua executando
        n = int(input()) # leia o valor de n

        if (n == 0): # se n for igual a 0, saia do loop
            break

        m = [[None for i in range(n)] for j in range(n)] # crie uma matriz n x n

        for i in range(n): # dois for aninhados para percorrer a matriz por: i-linhas e 
            for j in range(n): # j-colunas
                m[i][j] = abs(i - j) + 1 # preencha a matriz com o módulo da diferença entre i e j + 1

        for i in range(n): # percorra a matriz por linhas
            for j in range(n): # percorra a matriz por colunas
                if (j == n - 1): # se j for igual a n - 1, ou seja, se for a última coluna da linha, imprima o valor da 
                    # matriz e vá para a próxima linha
                    print(f"{m[i][j]:>3}") 
                else: # se não for a última coluna da linha, imprima o valor da matriz e continue na mesma linha 
                    # imprimindo um espaço em branco
                    print(f"{m[i][j]:>3}", end=" ") 

        print() # imprima uma linha em branco após a impressão da matriz

    except: # se ocorrer algum erro, saia do loop
        break 