Algoritmo Média_Turma

var cont, alunos: inteiro;
    nota, soma, média: real;
início
    cont ← 0;
    soma ← 0;
    escreva("Entre com o número de alunos");
    leia(alunos);
    enquanto (cont < alunos) faça
    início
        escreva("Entre com a nota do aluno: ", cont + 1);
        leia(nota);
        soma ← soma + nota;
        cont ← cont + 1;
    fim
    média ← soma / alunos;
    escreva("A média da turma é: ", média);
fim

Algoritmo Média_Escola_Versão2

var cont_a, alunos, cont_t, turmas: inteiro;
    nota, média_turma, soma_turma, média_escola, soma_escola: real;
início
    cont_t ← 0;
    soma_escola ← 0;
    escreva("Entre com o número de turmas: ");
    leia(turmas);
    enquanto (cont_t < turmas) faça
    início
        cont_a ← 0;
        soma_turma ← 0;
        escreva("Entre com o número de alunos da turma ", cont_t + 1);
        leia(alunos);
        enquanto (cont_a < alunos) faça
        início
            escreva("Entre com a nota do aluno: ", cont_a + 1);
            leia(nota);
            soma_turma ← soma_turma + nota;
            cont_a ← cont_a + 1;
        fim
        média_turma ← soma_turma / alunos;
        escreva("A média da turma ", cont_t + 1, " é: ", média_turma);
        soma_escola ← soma_escola + média_turma;
        cont_t ← cont_t + 1;
    fim
    média_escola ← soma_escola / turmas;
    escreva("A média da escola é: ", média_escola);
fim