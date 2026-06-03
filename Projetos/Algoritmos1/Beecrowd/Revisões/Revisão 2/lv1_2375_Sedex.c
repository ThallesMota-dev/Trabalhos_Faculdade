/* Etapa 1 — Análise do Enunciado
O problema fala de uma bola de boliche (esfera sólida) que precisa caber dentro 
de uma caixa com três dimensões. Vamos pensar junto:
A bola é uma esfera. A informação que temos dela é o diâmetro N. A caixa tem 
altura A, largura L e profundidade P.

Primeira pergunta pra você raciocinar:

Para uma esfera caber dentro de uma caixa retangular, qual é a condição? O que 
o diâmetro da bola precisa satisfazer em relação às dimensões da caixa? Pense 
nas três dimensões — a bola precisa "passar" em todas elas ou basta uma?

Etapa 2 — Entrada e Saída
Enquanto pensa na lógica, vamos já mapear a estrutura de I/O:

Entrada:
Linha 1: um inteiro N (diâmetro)
Linha 2: três inteiros A, L, P separados por espaço

Saída:
S se cabe, N se não cabe

Confere os exemplos pra validar seu raciocínio:

Diâmetro 3, caixa 2×3×5 → N (não cabe). Por que não cabe, se 3 ≤ 3 e 3 ≤ 5? 
Qual dimensão impediu? 3 <= 2 é a condição que falhou.
Diâmetro 5, caixa 5×5×5 → S (cabe)
Diâmetro 9, caixa 15×9×10 → S (cabe)*/

#include <stdio.h> 
int main() {
	int N, A, L, P; /* diâmetro da bola(N) e dimensões da caixa(A, L, P) */
	scanf("%d", &N); /* leitura do diâmetro da bola */
	scanf("%d %d %d", &A, &L, &P); /* leitura das dimensões da caixa */
	if (N <= A && N <= L && N <= P) { /* se o diâmetro da bola for menor ou igual a todas as dimensões da caixa */
		printf("S\n"); /* a bola cabe na caixa */
	} else { /* se o diâmetro da bola for maior que alguma das dimensões da caixa */
		printf("N\n"); /* a bola não cabe na caixa */
	} 
	return 0;
}