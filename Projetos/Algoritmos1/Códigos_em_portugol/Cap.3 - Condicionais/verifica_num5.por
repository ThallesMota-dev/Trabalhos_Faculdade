Algoritmo Verifica5

var a: inteiro;
início
1▸  escreva("Entre com um valor: ");
2▸  leia(a);
3▸  se (a = 5) então         { a = 5 retorna um valor lógico/booleano }
        início               { Começo do bloco de instruções 1 }
4▸          escreva("Condição Verdadeira");
5▸          escreva("O valor é ", a);
        fim                  { Término do bloco de instruções 1 }
6▸  escreva("Fim do algoritmo.");   { Continuação do algoritmo }
fim

Algoritmo Verifica5_Versão2

var a: inteiro;
início
    escreva("Entre com um valor: ");
    leia(a);
    se (a = 5) então
        início
            escreva("Condição Verdadeira");
            escreva("O valor é ", a);
        fim
    senão
        início
            escreva("Condição Falsa");
            escreva("O valor não é 5, é ", a);
        fim
    escreva("Fim do algoritmo.");
fim