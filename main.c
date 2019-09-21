#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "filaPrioridade.h"

void menu();

int main()
{
    setlocale(LC_ALL, "Portuguese");
    struct prioQueue q;
    int quit = 0;
    inicFilaPrio(&q);

    while(!quit){
        int op;
        char nome[50], *cliente;
        int t;
        menu();
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("\nDigite o nome do cliente: ");
                getchar();
                gets(nome);
                //scanf("%s", &nome);
                printf("\nDigite o tipo de cliente: ");
                scanf("%d", &t);
                enqueuePrio(&q, nome, t);                   
                break;
            case 2:
                cliente = dequeuePrio(&q);
                if(cliente == NULL)
                    printf("\n\nFila Vazia\n");
                else{
                    printf("\nPróximo a ser chamado:%s\n", cliente);
                    free(cliente);
                }
                break;
            case 3:
                printQueuePrio(&q);
                break;
            case 0:
                quit = 1;
                break;
            default:
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