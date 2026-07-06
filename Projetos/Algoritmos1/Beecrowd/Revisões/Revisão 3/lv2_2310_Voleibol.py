# Um treinador de voleibol gostaria de manter estatísticas sobre sua equipe. 
# A cada jogo, seu auxiliar anota quantas tentativas de saques, bloqueios e 
# ataques cada um de seus jogadores fez, bem como quantos desses saques, bloqueios
#  e ataques tiveram sucesso (resultaram em pontos). Seu programa deve mostrar 
# qual o percentual de saques, bloqueios e ataques do time todo tiveram sucesso.

# Entrada
# A entrada é dada pelo número de jogadores N (1 ≤ N ≤ 100), seguido pelo nome 
# e cada um dos jogadores. Abaixo do nome de cada jogador, seguem duas linhas 
# com três inteiros cada. Na primeira linha S, B e A (0 ≤ S,B,A ≤ 10000) 
# representam a quantidade de tentativas de saques, bloqueios e ataques e na 
# segunda linha, S1, B1 e A1 (0 ≤ S1 ≤ S; 0 ≤ B1 ≤ B; 0 ≤ A1 ≤ A) com o número 
# de saques, bloqueios e ataques deste jogador que tiveram sucesso.

# Saída
# A saída deve conter o percentual total de saques, bloqueios e ataques do time 
# todo que resultaram em pontos, conforme mostrado no exemplo.

# Exemplo de Entrada	

# 3
# Renan
# 10 20 12
# 1 10 9
# Jonas
# 8 7 1
# 2 7 0
# Edson
# 3 3 3
# 1 2 3

# Exemplo de Saída

# Pontos de Saque: 19.05 %.
# Pontos de Bloqueio: 63.33 %.
# Pontos de Ataque: 75.00 %.

N = int(input()) # Número de jogadores no time
acumS = 0 # inicializações das var. acumuladoras
acumB = 0
acumA = 0
acumS1 = 0 
acumB1 = 0 
acumA1 = 0
for i in range(N): # loop para ler as informações e operar as incrementações
    nome = input() # leitura do nome do jogador
    S, B, A = map(int, input().split()) # Saque, Block e Ataque na mesma linha
    S1, B1, A1 = map(int, input().split()) # Stats acertadas na mesma linha
    acumS += S # incrementação às var. acumuladoras
    acumB += B 
    acumA += A  
    acumS1 += S1 
    acumB1 += B1 
    acumA1 += A1  

percS = (acumS1 / acumS) * 100.00 # operação de porcentagem de acerto 
percB = (acumB1 / acumB) * 100.00
percA = (acumA1 / acumA) * 100.00

print(f"Pontos de Saque: {percS:.2f} %.") # impressão da porcentagem de acerto 
print(f"Pontos de Bloqueio: {percB:.2f} %.")
print(f"Pontos de Ataque: {percA:.2f} %.")

# alternativa em C:
#   #include <stdio.h>
#   int main() {
#       int N, i, acumS = 0, acumB = 0, acumA = 0, acumS1 = 0, acumB1 = 0, acumA1 = 0;
#       float percS, percB, percA;
#       char nome[21];
#       scanf("%d", &N);
#
#       for (i=0; i<N; i++) {
#           scanf("%s", nome);
#           scanf("%d %d %d", &S, &B, &A);
#           scanf("%d %d %d", &S1, &B1, &A1);
#           acumS += S;
#           acumB += B; 
#           acumA += A;  
#           acumS1 += S1; 
#           acumB1 += B1; 
#           acumA1 += A1;  
#       }
#
#       percS = (acumS1 / acumS) * 100.00; 
#       percB = (acumB1 / acumB) * 100.00;
#       percA = (acumA1 / acumA) * 100.00;
#       printf("Pontos de Saque: %.2f %.", percS); 
#       printf("Pontos de Bloqueio: %.2f %.", percB);
#       printf("Pontos de Ataque: %.2f %.", percA);
#       return 0;
#   }