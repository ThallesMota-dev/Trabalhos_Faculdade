#Em chats, é muito comum entre jovens e adolescentes utilizar sequências de letras,
#  que parecem muitas vezes aleatórias, para representar risadas. Alguns exemplos
#  comuns são:

# huaauhahhuahau
# hehehehe
# ahahahaha
# jaisjjkasjksjjskjakijs
# huehuehue

# Cláudia é uma jovem programadora que ficou intrigada pela sonoridade das “risada
#  digitais”. Algumas delas ela nem mesmo consegue pronunciar! Mas ela percebeu 
# que algumas delas parecem transmitir melhor o sentimento da risada que outras. 
# A primeira coisa que ela percebeu é que as consoantes não interferem no quanto 
# as risadas digitais influenciam na transmissão do sentimento. A segunda coisa 
# que ela percebeu é que as risadas digitais mais engraçadas são aquelas em que 
# as sequências de vogais são iguais quando lidas na ordem natural (da esquerda 
# para a direita) ou na ordem inversa (da direita para a esquerda), ignorando as 
# consoantes. Por exemplo, “hahaha” e “huaauhahhuahau” estão entre as risadas mais 
# engraçadas, enquanto “riajkjdhhihhjak” e “huehuehue” não estão entre as mais 
# engraçadas.

# Cláudia está muito atarefada com a análise estatística das risadas digitais e 
# pediu sua ajuda para escrever um programa que determine, para uma risada digital, 
# se ela é das mais engraçadas ou não.

# Entrada
# A entrada é composta por uma linha, contendo uma sequência de no máximo 50 caracteres, 
# formada apenas por letras minúsculas sem acentuação. As vogais são as letras 
# ‘a’,‘e’,‘i’,‘o’,‘u’. A sequência contém pelo menos uma vogal.

# Saída
# Seu programa deve produzir uma linha contendo um caractere, “S” caso a risada 
# seja das mais engraçadas, ou “N” caso contrário.

# Exemplos de Entrada	
# hahaha
# riajkjdhhihhjak
# a
# huaauhahhuahau

# Exemplos de Saída
# S
# N
# S
# S

risada = input() # lê var. risada como "string"
vogais = "" # var. vogais é acum. no formato "char"
for c in risada: # Para "char" dentro da var. risada
    if (c in "aeiou"): # Se "char" está em "aeiou"
        vogais += c # incrementa com a char(vogal"aeiou")
if (vogais[::-1] == vogais): # Se vogais(invertida) == vogais, então é engraçada
    print("S")
else: # Senão, não é engraçada
    print("N")

# Alternativa em C:
#   #include <stdio.h>
#   int main() {
#       char risada[51], vogais[51];
#       int i, j;
#       scanf("%s", risada);
#       j = 0; // indice de vogais
#       for (i = 0; risada[i] != '\0'; i++) { // loop para percorrer toda a string risada
#           if (risada[i] == 'a' || risada[i] == 'e' || risada[i] == 'i' || risada[i] == 'o' || risada[i] == 'u') {
#               // Se a str. risada tiver char = "aeiou", então: 
#               vogais[j] = risada[i]; // char vogais do indice j será igual a vogal da str. risada
#               j++; // incrementa o indice de vogais j
#           }
#       }
#       vogais[j] = '\0'; // fecha a str. com o terminador nulo '\0'
#       int palindromo = 1;  // flag: assume que é palindromo
#       int tam = j;         // j já tem o tamanho das vogais
#       for (i = 0; i < tam / 2; i++) { // loop para iterar da primeira vogal até a metade inteira do tam. das vogais
#           if (vogais[i] != vogais[tam - 1 - i]) { // Se a vogal inicial é dif. da vogal respectiva de trás para frente
#               palindromo = 0; // não é palíndromo, sai do loop
#               break;
#           }
#       }
#       if (palindromo == 1) { // Se é palindromo, então é engraçado
#           printf("S\n");
#       } else {
#           printf("N\n"); // Senão, não é
#       }
#       return 0;
#   }