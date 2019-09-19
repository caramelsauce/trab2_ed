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
    if(!filaVazia(q->qIdoso))
        return (dequeue(q->qIdoso));
    else if(filaVazia(q->qIdoso) && !filaVazia(q->qEspecial))
        return (dequeue(q->qEspecial));
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