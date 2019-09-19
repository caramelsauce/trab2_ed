#include "fila.h"

void inicFila(struct queue *q)
{
    q->inicio = NULL;
    q->fim = NULL;
}

int filaVazia(struct queue *q)
{
    if(q->inicio == NULL)
        return 1;
    else
        return 0;
}

void enqueue(struct queue *q, char *nome)
{
    struct elemento *novo = malloc(sizeof(struct elemento));
    strcpy(novo->nome, nome);
    novo->next = NULL;
    if(filaVazia(q))
        q->inicio = q->fim = novo;
    else{
        q->fim->next = novo;
        q->fim = novo;
    }
}

char *dequeue(struct queue *q)
{
    struct elemento *aux = NULL;
    char *nome = malloc(sizeof(char)  * 50);
    if(filaVazia(q)){
        return NULL;
    }
    else{
        aux = q->inicio;
        strcpy(nome, q->inicio->nome);
        q->inicio = q->inicio->next;
    }
    if(q->inicio == NULL)
        q->fim = NULL;
    free(aux);
    return nome;    
}

void printQueue(struct queue *q)
{
    struct elemento *temp;
    temp = q->inicio;
    while(temp != NULL){
        printf("\t%s\n", temp->nome);
        temp = temp->next;
    }
}
