#include "filaPrioridade.h"

void inicFilaPrio(struct prioQueue *q)
{
    q->qIdoso = malloc(sizeof(struct queue *));
    inicFila(q->qIdoso);
    q->qEspecial = malloc(sizeof(struct queue *));
    inicFila(q->qEspecial);
    q->qComum = malloc(sizeof(struct queue *));
    inicFila(q->qComum);
}

int filaPrioVazia(struct prioQueue *q)
{
    if(filaVazia(q->qIdoso) && filaVazia(q->qEspecial) && filaVazia(q->qComum))
        return 1;
    else
        return 0;
}

void enqueuePrio(struct prioQueue *q, char *nome, int type)
{
    switch(type){
        case 0:
            enqueue(q->qIdoso, nome);
            break;
        case 1:
            enqueue(q->qEspecial, nome);
            break;
        case 2:
            enqueue(q->qComum, nome);
            break;
        default:
            printf("\nTipo de cliente inválido\n");
    }
}

char *dequeuePrio(struct prioQueue *q)
{
    if(!filaVazia(q->qIdoso)){
        aging(q, 0);
        return (dequeue(q->qIdoso));
    }
    else if(filaVazia(q->qIdoso) && !filaVazia(q->qEspecial)){
        aging(q, 1);
        return (dequeue(q->qEspecial));
    }
    else
        return (dequeue(q->qComum));
}

void printQueuePrio(struct prioQueue *q)
{
    printf("\nFila Idoso:\n");
    printQueue(q->qIdoso);
    printf("\nFila Especial:\n");
    printQueue(q->qEspecial);
    printf("\nFila Comum:\n");
    printQueue(q->qComum);
}

void aging(struct prioQueue *q, int op)
{
    static int contIdoso = 0, contEspecial = 0;
    char *nome;
    if(op == 0 && !filaVazia(q->qEspecial))
        contIdoso++;
    else if(op == 1 && !filaVazia(q->qComum))
        contEspecial++;
    if(contIdoso == 5){
        nome = dequeue(q->qEspecial);
        if(nome != NULL)
            enqueue(q->qIdoso, nome);
        nome = dequeue(q->qComum);
        if(nome != NULL)
            enqueue(q->qEspecial, nome);
        contIdoso = 0;
    }
    if(contEspecial == 5){
        nome = dequeue(q->qComum);
        if(nome != NULL)
            enqueue(q->qEspecial, nome);
        contEspecial = 0;
    }
}