n, m = input().split() # n = número de corredores, m = número de voltas
n = int(n) 
m = int(m) 
menor_tempo = 999999999 # variável para armazenar o menor tempo encontrado, iniciada com um valor muito alto para garantir que o primeiro tempo lido seja considerado como menor.
vencedor = 0 # variável para armazenar o número do corredor vencedor, iniciada com 0 para indicar que ainda não foi encontrado um vencedor.
for i in range(n): # loop para ler os tempos de cada corredor, onde i representa o índice do corredor (de 0 a n-1).
    tempos = input().split() # leitura dos tempos de cada volta para o corredor atual, armazenados em uma lista chamada "tempos".
    soma = 0 # variável para armazenar a soma dos tempos de um corredor, iniciada com 0 para garantir que a soma seja calculada corretamente.
    for j in range(m): # loop para somar os tempos de cada volta do corredor atual, onde j representa o índice da volta (de 0 a m-1).
        soma = soma + int(tempos[j]) # conversão do tempo da volta de string para inteiro e adição à soma total dos tempos do corredor em cada volta.
    if soma < menor_tempo: # comparação do tempo total do corredor atual com o menor tempo encontrado até agora. Se o tempo atual for menor, significa que encontramos um novo vencedor.    
        menor_tempo  = soma # atualização do menor tempo encontrado com o tempo total do corredor atual, indicando que este é o novo menor tempo.
        vencedor = i + 1 # atualização do número do corredor vencedor com o índice do corredor atual (i) mais 1, pois os corredores são numerados a partir de 1, enquanto os índices começam em 0.
print(f"{vencedor}") # impressão do número do corredor vencedor, formatado como uma string. O f-string é usado para inserir a variável "vencedor" diretamente na string de saída.