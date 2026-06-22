/* Faça um programa que realize o cadastro de contas bancárias com as seguintes 
informações: número da conta, nome do cliente e saldo. O banco permitirá o 
cadastramento de apenas quinze contas e não poderá haver mais de uma conta com 
o mesmo número. Crie o menu de opções a seguir: 1 Cadastrar contas. 2 Visualizar 
todas as contas de determinado cliente 3 Excluir a conta com menor saldo 
(Suponha a não-existência de saldos iguais). 4 Sair. */

#include <stdio.h> 
#include <string.h> // para usar a função strcmp para comparar strings
typedef struct { // definição da estrutura Conta
    char nome[100]; // nome do cliente
    int numero_conta; // número da conta
    float saldo; // saldo da conta
} Conta; // definição da estrutura Conta
int main() { 
    Conta contas[15]; // array para armazenar as contas, com limite de 15
    int total_contas = 0, i, num_novo, opcao, existe_conta, menor_saldo; // variáveis para controle do total de contas, número da nova conta, maior número de conta, opção do menu, flag para verificar existência de conta, índices para loops e índice da conta com menor saldo, 
    char busca[100];
    do { // loop para exibir o menu e processar as opções
        printf("1 - Cadastrar\n"); // opção para cadastrar uma nova conta
        printf("2 - Visualizar por cliente\n"); // opção para visualizar todas as contas de um cliente específico
        printf("3 - Excluir menor saldo\n"); // opção para excluir a conta com o menor saldo
        printf("4 - Sair\n"); // opção para sair do programa
        scanf("%d", &opcao); // ler a opção escolhida pelo usuário

        switch (opcao) { // processar a opção escolhida pelo usuário
            case 1: // cadastrar nova conta
                if (total_contas == 15) { // verificar se o limite de contas foi atingido
                    printf("Limite de contas atingido!\n"); // mensagem de erro se o limite de contas for atingido
                    break; // sair do case 1
                }

                printf("Numero da conta: "); // solicitar o número da conta ao usuário
                scanf("%d", &num_novo); // ler o número da conta a ser cadastrada

                existe_conta = 0; // flag para verificar se o número da conta já existe
                for (i = 0; i < total_contas; i++) { // verificar se o número da conta já existe no array de contas
                    if (contas[i].numero_conta == num_novo) { // se o número da conta já existe, marcar a flag e sair do loop
                        existe_conta = 1; // marcar que a conta já existe
                        printf("Numero de conta ja existe!\n"); // mensagem de erro se o número da conta já existir
                        break; // sair do loop, pois já sabemos que a conta existe
                    }
                }

                if (existe_conta == 0) { // se a conta não existe, cadastrar a nova conta
                    contas[total_contas].numero_conta = num_novo; // atribuir o número da conta à nova conta
                    printf("Nome do cliente: "); // solicitar o nome do cliente ao usuário
                    scanf("%s", contas[total_contas].nome); // ler o nome do cliente e armazenar na nova conta
                    printf("Saldo da conta: "); // solicitar o saldo da conta ao usuário
                    scanf("%f", &contas[total_contas].saldo); // ler o saldo da conta e armazenar na nova conta
                    total_contas++; // incrementar o total de contas cadastradas
                }
                break; // sair do case 1 após cadastrar a nova conta
            case 2: /* visualizar contas */ 
                printf("Nome do cliente: "); // solicitar o nome do cliente ao usuário para buscar suas contas
                scanf("%s", busca); // ler o nome do cliente a ser buscado
                for (i = 0; i < total_contas; i++) { // percorrer o array de contas para encontrar as contas do cliente buscado
                    if (strcmp(contas[i].nome, busca) == 0) { // se o nome da conta for igual ao nome buscado, exibir as informações da conta
                        printf("Conta: %d | Saldo: %.2f\n", contas[i].numero_conta, contas[i].saldo); // exibir o número da conta e o saldo da conta do cliente encontrado
                    }
                }
                break; // sair do case 2 após exibir as contas do cliente buscado
            case 3:
                if (total_contas == 0) { // verificar se há contas cadastradas antes de tentar excluir a conta com menor saldo
                    printf("Nenhuma conta cadastrada!\n"); // mensagem de erro se não houver contas cadastradas
                    break; // sair do case 3 se não houver contas cadastradas
                }
                menor_saldo = 0; // inicializar o índice da conta com menor saldo como o primeiro índice do array de contas
                for (i = 1; i < total_contas; i++) { // percorrer o array de contas para encontrar a conta com o menor saldo
                    if (contas[i].saldo < contas[menor_saldo].saldo) { // comparar o saldo da conta atual com o saldo da conta com menor saldo encontrada até agora
                        menor_saldo = i; // atualizar o índice da conta com menor saldo
                    }
                }
                // substitui pela última e reduz o total
                contas[menor_saldo] = contas[total_contas - 1]; // substituir a conta com menor saldo pela última conta cadastrada
                total_contas--; // decrementa o total de contas, efetivamente excluindo a conta com o menor saldo
                break; // sair do case 3 após excluir a conta com o menor saldo
            case 4: // sair do programa
                printf("Saindo...\n"); // mensagem de despedida ao sair do programa 
                break; // sair do case 4
            default: // caso o usuário digite uma opção inválida
                printf("Opcao invalida!\n"); // mensagem de erro para opção inválida
                break; // sair do default
        }
    } while (opcao != 4); // continuar exibindo o menu até que o usuário escolha a opção de sair (4)

    return 0; // retornar 0 para indicar que o programa terminou com sucesso
}