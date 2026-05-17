Algoritmo Somatório

var i, n, somat: inteiro;
início
    escreva("Entre com o limite superior: ");
    leia(n);
    somat ← 0;
    para (i ← 3; i <= n; i ← i + 1) faça
        somat ← somat + (5 * i + 2);
    escreva("O somatório é ", somat);
fim