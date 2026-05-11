Algoritmo Soma_Ímpares_Versão1

var inferior, superior, num, soma: inteiro;
início
    soma ← 0;
    escreva("Entre com o limite inferior: ");
    leia(inferior);
    escreva("Entre com o limite superior: ");
    leia(superior);
    num ← inferior;
    enquanto (num <= superior) faça
    início
        se (num resto 2 = 1) então
            soma ← soma + num;
        num ← num + 1;
    fim
    escreva("Somatório: ", soma);
fim

Algoritmo Soma_Ímpares_Versão2

var superior, num, soma: inteiro;
início
    soma ← 0;
    escreva("Entre com o limite superior: ");
    leia(superior);
    num ← 1;
    repita
    início
        se (num resto 2 > 0) então
            soma ← soma + num;
        num ← num + 1;
    fim
    até (num > superior);
    escreva("A soma dos números ímpares é: ", soma);
fim

Algoritmo Soma_Ímpares_Versão4

var superior, num, soma: inteiro;
início
    soma ← 0;
    escreva("Entre com o limite superior: ");
    leia(superior);
    para (num ← 1; num <= superior; num ← num + 1) faça
        se (num resto 2 > 0) então
            soma ← soma + num;
    escreva("A soma dos números ímpares é: ", soma);
fim