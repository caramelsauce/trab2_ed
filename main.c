#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "filaPrioridade.h"

void menu();

int main()
{
    //localidade
    setlocale(LC_ALL, "Portuguese");

    //declaração da variável da fila de prioridade e a variável de controle do loop
    struct prioQueue q;
    int quit = 0;

    //inicialização da fila 
    inicFilaPrio(&q);

    //loop principal
    while(!quit){
        //declaração de variáveis
        int op;
        char nome[50], *cliente;
        int t;

        //printar o menu e recolher a opção escolhida
        menu();
        scanf("%d", &op);

        //switch para tratar a escolha
        switch(op){
            case 1:
                //recolher o nome e o tipo do cliente para inserir na fila adequada
                printf("\nDigite o nome do cliente: ");
                getchar();  //retirar o '\n' do buffer
                gets(nome);
                printf("\nDigite o tipo de cliente: ");
                scanf("%d", &t);
                enqueuePrio(&q, nome, t);   //função para inserir                
                break;
            case 2:
                //remover o primeiro da fila de maior prioridade
                cliente = dequeuePrio(&q);
                
                //testar se a fila não está vazia
                if(cliente == NULL)
                    printf("\n\nFila Vazia\n");
                
                //mostrar o retirado da fila e desalocar o ponteiro usado para armazenar o nome
                else{
                    printf("\nPróximo a ser chamado:%s\n", cliente);
                    free(cliente);
                }
                break;
            case 3:
                //mostrar as 3 filas
                printQueuePrio(&q);
                break;
            case 0:
                //sair do loop
                quit = 1;
                break;
            default:
                //tratamento para opções que não existem
                printf("\n\nOpção Inválida\n\n");
                break;
        }
    }
    return 0;
}

void menu()
{
    printf("\n1 - Inserir Cliente Na Fila\n");
    printf("\n2 - Chamar Cliente\n");
    printf("\n3 - Imprimir Fila\n");
    printf("\n0 - Sair\n");
    printf("\nOpção: ");
}