n = int(input()) # número de casos de teste
for i in range(n): # loop para processar cada caso de teste, onde i representa o índice do caso (de 0 a n-1).
    num = int(input()) # leitura do número para o qual queremos verificar se o próximo número é um primo e múltiplo de 7.
    proximo = num + 1 # cálculo do próximo número, que é o número atual mais 1. Este é o número que será verificado para as condições de ser primo e múltiplo de 7.
    primo_check = proximo + 2 # cálculo do primo_check, que é o próximo número mais 2. Este é o número que será verificado para determinar se o próximo número é primo.
    cont_div = 0 # variável para contar o número de divisores do primo_check, iniciada com 0 para garantir que a contagem seja correta.
    for j in range(2, primo_check): # loop para verificar se o primo_check é divisível por algum número entre 2 e ele mesmo menos 1. O loop começa em 2 porque um número não pode ser primo se for divisível por 1, e termina em primo_check - 1 porque um número não pode ser primo se for divisível por ele mesmo.
        if primo_check % j == 0: # verificação se o primo_check é divisível por j. Se for, isso significa que o primo_check não é um número primo, e a contagem de divisores é incrementada em 1.
            cont_div += 1 # incremento da contagem de divisores do primo_check, indicando que encontramos um divisor além de 1 e ele mesmo.
    if (proximo % 7 == 0) and (proximo % 2 != 0) and (cont_div == 0): # verificação das condições para o próximo número: múltiplo de 7 (proximo % 7 == 0), ímpar (proximo % 2 != 0), primo (cont_div == 0, indicando que não encontramos divisores além de 1 e ele mesmo).
        print("Yes")
    else:
        print("No")