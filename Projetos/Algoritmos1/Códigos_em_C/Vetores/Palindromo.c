#include <stdio.h>
int main() {
    char caract[51];
    int tam = 0, i, j, palindromo = 1;

    scanf("%[^\n]", caract);
    
    while (caract[tam] != '\0') {
        tam++;
    }

    i = 0;
    j = tam - 1;
    
    while (i < j) {
        while (caract[i] == ' ') i++; 
        while (caract[j] == ' ') j--; 
        if (caract[i] != caract[j]) {
            palindromo = 0;
            break;
        }
        i++;
        j--;
    }

    i = 0;
    j = 0;

    while (caract[i] != '\0') {
        if ([i] != ' ') {
            if (caract[i] >= 'A' && caract[i] <= 'Z') {
                caract[j] = caract[i] + 32;
            } else {
                caract[j] = caract[i];
            }
            j++;
        }
        i++;
    }

    if (palindromo == 1) {
        printf("Palindromo\n");
    } else {
        printf("Não Palindromo\n");
    }
    
    return 0;
}