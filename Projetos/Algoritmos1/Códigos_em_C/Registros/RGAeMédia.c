#include <stdio.h>
typedef struct {
	char nome[51];
	int rga;
	double media;  
} Aluno;
int main() {
	Aluno alunos[10];
	int i, maior = 0, menor = 0;
	for (i=0; i<10; i++) {
		printf("RGA: \n");
		scanf("%d", &alunos[i].rga);
		printf("Nome: \n");
		scanf("%s", alunos[i].nome);
		printf("Média: \n");
		scanf("%lf", &alunos[i].media);
	}
	for (i=1; i<10; i++) { /* i=1 pois, o primeiro maior a ser
verificado é o maior = 0. O mesmo vale para o menor. */
		if (alunos[i].media > alunos[maior].media) {
			maior = i;
		}
		if (alunos[i].media < alunos[menor].media) {
			menor = i;
		} 
	}
	printf("Maior média - RGA: %d | Nome: %s | Média: %.2lf\n", 
		alunos[maior].rga, alunos[maior].nome, alunos[maior].media);
	printf("Menor média - RGA: %d | Nome: %s | Média: %.2lf\n", 
		alunos[menor].rga, alunos[menor].nome, alunos[menor].media);
	return 0;
}