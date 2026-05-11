Algoritmo Mult_Soma

var operando1, operando2, resultado, contador: inteiro;
início
    contador ← 0;
    resultado ← 0;
    escreva("Entre com o primeiro valor: ");
    leia(operando1);
    escreva("Entre com o segundo valor: ");
    leia(operando2);
    enquanto (contador < operando2) faça
    início
        resultado ← resultado + operando1;
        contador ← contador + 1;
    fim
    escreva("O resultado da multiplicação é: ", resultado);
fim