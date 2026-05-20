while True: # loop infinito para processar múltiplos casos de teste, onde o programa continuará a ler entradas até que uma condição de parada seja atingida (neste caso, quando não houver mais entradas para ler).
    try: # bloco try para tentar ler a entrada e processar os dados. Se ocorrer um erro (como EOFError quando não houver mais entradas), o programa irá capturar a exceção e quebrar o loop, encerrando a execução.
        n, m = input().split() # leitura da entrada, onde (n é o número de casos de teste) e (m é o número para o qual queremos verificar a divisibilidade por 3). A função split() é usada para separar os valores de n e m, que são lidos como strings.
        n = int(n)
        m = int(m)
        soma = 0 # variável para armazenar a soma dos dígitos de m, iniciada com 0 para garantir que a soma seja calculada corretamente.
        while (m > 0): # loop para extrair os dígitos de m e somá-los. O loop continua enquanto m for maior que 0, o que significa que ainda há dígitos para processar.
            digito = m % 10 # cálculo do dígito mais à direita de m usando o operador resto (%). Este é o dígito que será adicionado à soma.
            soma = soma + digito # adição do dígito extraído à soma total dos dígitos de m.
            m = m // 10 # atualização de m para remover o dígito mais à direita, usando a divisão inteira (//). Isso prepara m para a próxima iteração do loop, onde o próximo dígito mais à direita será processado.
        if (soma % 3 == 0): # verificação se a soma dos dígitos de m é divisível por 3 usando o operador resto (%). Se a condição for verdadeira, significa que m é divisível por 3, e o programa imprimirá "sim". Caso contrário, imprimirá "nao".
            print(f"{soma} sim")
        else :
            print(f"{soma} nao")
    except: # bloco except para capturar qualquer exceção que possa ocorrer durante a leitura da entrada ou o processamento dos dados. Se uma exceção for capturada, o programa irá executar o código dentro deste bloco.
        break # quebra do loop quando não houver mais entradas para ler, encerrando a execução do programa.