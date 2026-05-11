Algoritmo Iguais_Diferentes_Versão3

var n1, n2, n3: inteiro;
início
    escreva("Entre com o primeiro valor: ");
    leia(n1);
    escreva("Entre com o segundo valor: ");
    leia(n2);
    escreva("Entre com o terceiro valor: ");
    leia(n3);
    se (n1 = n2) então
        se (n2 = n3) então                    { 3 números iguais }
            escreva("Os três valores são iguais");
        senão
          escreva("Há dois valores iguais e um diferente");
    senão                                       { n1 <> n2 }
        se (n1 = n3) então
            escreva("Há dois valores iguais e um diferente");
        senão se (n2 = n3) então               { n1 <> n3 }
            escreva("Há dois valores iguais e um diferente");
        senão                                   { n2 <> n3 }
            escreva("Todos os valores são diferentes");
    escreva("Fim do programa.");
fim