# Escreva um algoritmo que leia 2 números e imprima o resultado da divisão do 
# primeiro pelo segundo. Caso não for possível mostre a mensagem “divisao impossivel” 
# para os valores em questão.

# Entrada
# A entrada contém um número inteiro N. Este N será a quantidade de pares de 
# valores inteiros (X e Y) que serão lidos em seguida.

# Saída
# Para cada caso mostre o resultado da divisão com um dígito após o ponto decimal, 
# ou “divisao impossivel” caso não seja possível efetuar o cálculo.

# Obs.: Cuide que a divisão entre dois inteiros em algumas linguagens como o C 
# e C++ gera outro inteiro. Utilize cast :)

N = int(input()) # leitura do número inteiro N, que representa a quantidade de pares de valores inteiros (X e Y) a serem lidos.
for i in range(N): # loop que itera de 0 a N-1 vezes para ler os pares de valores inteiros (X e Y).
    x, y = input().split() # leitura dos valores inteiros X e Y, separados por espaço, e armazenados em variáveis x e y.
    x = int(x) 
    y = int(y) 
    if y == 0: # verificação se o valor de y é igual a zero, para evitar divisão por zero.
        print("divisao impossivel")
    else:
        resultado = x / y # cálculo da divisão de x por y.
        print(f"{resultado:.1f}") # impressão do resultado da divisão com um dígito após o ponto decimal.