Algoritmo Fatorial

var valor, fat, n: inteiro;
início
    escreva("Entre com um valor: ");
    leia(valor);
    se (valor < 0) então
        escreva("Valor inválido!");
    senão
    início
        fat ← 1;
        n ← valor;
        enquanto (n > 1) faça
        início
            fat ← fat * n;
            n ← n - 1;
        fim
        escreva("O fatorial calculado é: ", fat);
    fim
fim