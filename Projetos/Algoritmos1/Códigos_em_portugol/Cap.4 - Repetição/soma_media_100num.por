Algoritmo Soma_Média100

var contador: inteiro;
    valor, soma, media: real;
início
    contador ← 0;
    soma ← 0;
    enquanto (contador < 100) faça
    início
        escreva("Entre com um valor: ");
        leia(valor);
        soma ← soma + valor;  {a variável soma acumula a soma dos valores lidos}
        contador ← contador + 1;
    fim
    media ← soma / contador;
    escreva("Soma: ", soma);
    escreva("Média: ", media);
fim