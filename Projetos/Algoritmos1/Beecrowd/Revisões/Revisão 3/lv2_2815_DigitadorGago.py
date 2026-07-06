# Francisco Iote é uma gago diferente. Ele não somente fala repetindo sílabas 
# como estranhamente quando digita um texto ele repete algumas sílabas, tornando
#  a leitura muito chata. Ele repete apenas sílabas que tenham exatamente 2 letras
#  e nunca repete uma sílaba que não seja a primeira sílaba da palavra. Ele também
#  repete apenas uma vez, ou seja a palavra bola, por exemplo, pode aparecer como
#  bola ou bobola, nunca bobobola.

# Você foi chamado como perito para traduzir alguns textos excritos por Francisco
#  eliminando as redundâncias de texto por ele geradas.

# Entrada
# A entrada é composta por apenas uma linha com até 1000 palavras, cada uma delas
#  com no máximo 15 caracteres. Esta linha de texto deve ser corrigida eliminando-se
#  as redundâncias, conforme exemplo abaixo.

# Saída
# Seu programa deve gerar uma versão do texto fornecido por Francisco que não 
# contenha as repetições descritas acima.

# Exemplos de Entrada	
# Juca comprou fafarinha na memercearia e papagou 4 reais o quilo. A mamae de 
# Juca pediu para ele comprar mamais 2 quilos.

# O papassarinho vovoou para bem longe.

# Exemplos de Saída

# Juca comprou farinha na mercearia e pagou 4 reais o quilo. A mae de Juca pediu
#  para ele comprar mais 2 quilos.

# O passarinho voou para bem longe.



palavras = input().split() # lê na mesma linha linha várias strings
resultado = [] # lista vazia onde guardamos as palavras corrigidas.
for palavra in palavras: # percorre cada palavra da lista. 
    if ((len(palavra) >= 4) and (palavra[0:2] == palavra[2:4])): # Se a palavra 
        # tem pelo menos 4 letras E os 2 primeiros caracteres são iguais aos 2 seguintes
        palavra = palavra[2:] # "corta" os 2 primeiros caracteres.
    resultado.append(palavra) # Adiciona a palavra (corrigida ou não) na lista de resultados. 
    # append coloca no final da lista.
print(" ".join(resultado)) # Junta todas as palavras da lista com espaço entre elas e imprime.




# Alternativa em C:
#
#   #include <stdio.h>
#   include <string.h>
#   int main() {
#       char palavra[16];
#       int primeiro = 1;
#       while (scanf("%s", palavra) == 1) {
#           if (primeiro == 0) {
#               printf(" ");
#           }
#           if (strlen(palavra) >= 4 && strncmp(palavra, palavra + 2, 2) == 0) {
#               printf("%s", palavra + 2);  // pula os 2 primeiros
#           } else {
#               printf("%s", palavra);
#           }
#           primeiro = 0;
#       }
#       printf("\n");
#       return 0;
#   }
# 
#
#
#
#
#
#
#
#
