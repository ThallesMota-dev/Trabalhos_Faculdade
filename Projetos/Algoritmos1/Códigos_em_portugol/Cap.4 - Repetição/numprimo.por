Algoritmo Primo_Versão1

var número, divisor: inteiro;
    divisível: booleano;
início
    escreva("Entre com um número a ser testado: ");
    leia(número);
    divisível ← F;
    divisor ← número - 1;
    enquanto (não(divisível) e divisor > 1) faça
    início
        se (número resto divisor = 0) então
            divisível ← V;
        senão
            divisor ← divisor - 1;
    fim
    se (não(divisível)) então
        escreva("O número ", número, " é primo.");
    senão
        escreva("O número ", número, " não é primo.");
fim

Algoritmo Primo_Versão2

var número, divisor: inteiro;
    divisível: booleano;
início
    escreva("Entre com um número a ser testado: ");
    leia(número);
    divisível ← F;
    se (número resto 2 = 0 e número > 2) então
        divisível ← V;
    senão
        divisor ← 3;
        enquanto (NAO(divisível) e divisor <= número / 2) faça
        início
            se (número resto divisor = 0) então
                divisível ← V;
            senão
                divisor ← divisor + 2;
        fim
    se (NAO(divisível)) então
        escreva("O número ", número, " é primo.");
    senão
        escreva("O número ", número, " não é primo.");
fim

Algoritmo Primo_Versão3

var número, divisor: inteiro;
    divisível: booleano;
início
    escreva("Entre com um número a ser testado: ");
    leia(número);
    divisível ← F;
    se (número resto 2 = 0 e número > 2) então
        divisível ← V;
    senão
        divisor ← 3;
        enquanto (NAO(divisível) e divisor <= número raiz 2) faça
        início
            se (número resto divisor = 0) então
                divisível ← V;
            senão
                divisor ← divisor + 2;
        fim
    se (NAO(divisível)) então
        escreva("O número ", número, " é primo.");
    senão
        escreva("O número ", número, " não é primo.");
fim