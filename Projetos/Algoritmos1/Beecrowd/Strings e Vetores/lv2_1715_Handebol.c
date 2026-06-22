/* 

Frustrado e desanimado com os resultados de sua equipe de futebol, o Super 
Brasileiro Clube (SBC) resolveu investir na equipe de handebol. Para melhor 
avaliar os atletas, os técnicos identificaram que seria útil analisar a regularidade 
dos jogadores. Especificamente, eles estão interessados em saber quantos jogadores 
fizeram gols em todas as partidas.

Como o volume de dados é muito grande, eles gostariam de ter um programa de 
computador para realizar essa contagem.

Entrada

A primeira linha da entrada contém dois inteiros N e M (1 ≤ N ≤ 100 e 1 ≤ M ≤ 100), 
indicando respectivamente o número de jogadores e o número de partidas. Cada uma das 
N linhas seguintes descreve o desempenho de um jogador: a i-ésima linha contém M 
inteiros Xj (0 ≤ X j ≤ 100, para 1 ≤ j ≤ M ), informando o número de gols do i-ésimo 
jogador em cada partida.

Saída

Seu programa deve produzir uma única linha, contendo um único inteiro, o número de 
jogadores que fizeram gols em todas as partidas.

Exemplo de Entrada:

5 3

0 0 0

1 0 5

0 0 0

0 1 2

1 1 0
	
Exemplo de Saída:

0
*/

#include <stdio.h>
int main() {
    int i, j, n, m, gols, sem_gol, acum = 0;
    scanf("%d %d", &n, &m); // lê o número de jogadores e o número de partidas
    for (i=0; i<n; i++) { // para cada jogador
        sem_gol = 0; // flag para jogador sem gol
        for (j=0; j<m; j++) { // para cada partida
            scanf("%d", &gols); // lê o número de gols do jogador na partida
            if (gols == 0) { // se o jogador não fez gol na partida
                sem_gol = 1; // jogador sem gol
            }
        }
        if (sem_gol == 0) { // se o jogador fez gols em todas as partidas
            acum++; // incrementa o contador de jogadores que fizeram gols em todas as partidas
        }
    }
    printf("%d\n", acum); // imprime o número de jogadores que fizeram gols em todas as partidas
    return 0;
}