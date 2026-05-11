Algoritmo Menu_Identificação

var n1, opção: inteiro;
início
    escreva("Entre com o valor a ser testado: ");
    leia(n1);
    escreva("Você pretende identificar se o número é: ");
    escreva("Opção 1: Par ou ímpar: ");
    escreva("Opção 2: Positivo, negativo ou 0: ");
    escreva("Opção 3: Bissexto: ");
    leia(opção);
    caso opção seja:
        1:
            se (n1 resto 2) = 0 então
                escreva("Número par.");
            senão
                escreva("Número ímpar.");
        2:
            se (n1 > 0) então
                escreva("Número positivo.");
            senão se (n1 < 0) então
                escreva("Número negativo.");
            senão
                escreva("Número 0.");
        3:
            se ((n1 resto 4 = 0 e n1 resto 100 <> 0)
                ou (n1 resto 400 = 0)) então
                escreva("Ano bissexto.");
            senão
                escreva("Ano não é bissexto.");
        default:
            escreva("Opção inválida.");
fim