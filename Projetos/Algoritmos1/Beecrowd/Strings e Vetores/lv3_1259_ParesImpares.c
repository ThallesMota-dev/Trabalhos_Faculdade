/* Considerando a entrada de valores inteiros não negativos, ordene estes valores
 segundo o seguinte critério:

Primeiro os Pares
Depois os Ímpares
Sendo que deverão ser apresentados os pares em ordem crescente e depois os ímpares 
em ordem decrescente.

Entrada
A primeira linha de entrada contém um único inteiro positivo N (1 < N <= 105) 
Este é o número de linhas de entrada que vem logo a seguir. As próximas N linhas 
conterão, cada uma delas, um valor inteiro não negativo.

Saída
Apresente todos os valores lidos na entrada segundo a ordem apresentada acima. 
Cada número deve ser impresso em uma linha, conforme exemplo abaixo.

Exemplo de Entrada	
10
4
32
34
543
3456
654
567
87
6789
98

Exemplo de Saída
4
32
34
98
654
3456
6789
567
543
87*/


#include <stdio.h>
int num[100000], pares[100000], impares[100000];
int main() {
	int n, i, j, total_par = 0, total_impar = 0, aux;
	scanf("%d", &n);
	for (i=0; i<n; i++) {
		scanf("%d", &num[i]);
		if (num[i] % 2 == 0) {
			pares[total_par] = num[i];
			total_par++;
		} else {
			impares[total_impar] = num[i];
			total_impar++;
		}
	}
	for (i=0; i<total_par; i++) {
		for (j=0; j<total_par - 1; j++) {
			if (pares[j] > pares[j+1]) {
				aux = pares[j];
				pares[j] = pares[j+1];
				pares[j+1] = aux;
			}
		}
	}
	for (i=0; i<total_impar; i++) {	
		for (j=0; j<total_impar - 1; j++) {
			if (impares[j] < impares[j+1]) {
				aux = impares[j];
				impares[j] = impares[j+1];
				impares[j+1] = aux;
			}
		}
	}
	for (i=0; i<total_par; i++) {
		printf("%d\n", pares[i]);
	}
	for (i=0; i<total_impar;i++) {
		printf("%d\n", impares[i]);
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

int pares[100000], impares[100000];

int crescente(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int decrescente(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int n, i, num, total_par = 0, total_impar = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &num);
        if (num % 2 == 0) {
            pares[total_par] = num;
            total_par++;
        } else {
            impares[total_impar] = num;
            total_impar++;
        }
    }
    qsort(pares, total_par, sizeof(int), crescente);
    qsort(impares, total_impar, sizeof(int), decrescente);
    for (i = 0; i < total_par; i++) {
        printf("%d\n", pares[i]);
    }
    for (i = 0; i < total_impar; i++) {
        printf("%d\n", impares[i]);
    }
    return 0;
}