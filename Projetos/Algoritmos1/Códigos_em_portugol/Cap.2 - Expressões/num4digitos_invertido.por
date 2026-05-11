Algoritmo "NumeroInvertido"

Var
   n, d1, d2, d3, d4, invertido : Inteiro

Início
   Escreva("Digite um número de 4 dígitos: ")
   Leia(n)

   d1 <- n MOD 10          {unidade}
   d2 <- (n DIV 10) MOD 10 {dezena}
   d3 <- (n DIV 100) MOD 10{centena}
   d4 <- n DIV 1000        {milhar}

   invertido <- (d1 * 1000) + (d2 * 100) + (d3 * 10) + d4

   Escreva("Número invertido: ", invertido)

Fimalgoritmo