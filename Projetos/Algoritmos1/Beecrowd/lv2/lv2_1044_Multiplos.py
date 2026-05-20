# Leia 2 valores inteiros (A e B). Após, o programa deve mostrar uma mensagem 
# "Sao Multiplos" ou "Nao sao Multiplos", indicando se os valores lidos são múltiplos entre si.

# Entrada
# A entrada contém valores inteiros.

# Saída
# A saída deve conter uma das mensagens conforme descrito acima.

a, b = input().split() # leitura dos valores inteiros A e B, separados por espaço, e armazenados em variáveis a e b.
a = int(a) # conversão do valor de a de string para inteiro.
b = int(b) # conversão do valor de b de string para inteiro.
if a % b == 0 or b % a == 0: # verificação se a é múltiplo de b ou se b é múltiplo de a, utilizando o operador resto (%).
    print("Sao Multiplos")
else:
    print("Nao sao Multiplos")