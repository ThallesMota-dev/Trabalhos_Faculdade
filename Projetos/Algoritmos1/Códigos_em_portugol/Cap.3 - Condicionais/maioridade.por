Algoritmo Maior_Idade

constante LIMITE = 18;
var idade: inteiro;
    maior: booleano;
início
    escreva("Entre com a idade: ");
    leia(idade);
    se (idade >= LIMITE) então
        maior ← V;
    senão
        maior ← F;
    se (maior) então
        escreva("É maior de idade.");     
    senão
        escreva("É menor de idade.");     
fim