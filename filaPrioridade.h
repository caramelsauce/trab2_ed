#ifndef FILAP_H
#define FILAP_H

#include "fila.h"

struct prioQueue{
    struct queue *qIdoso;
    struct queue *qEspecial;
    struct queue *qComum;
};

//aloca e inicializa as 3 filas contidas na fila de prioridade
void inicFilaPrio(struct prioQueue *q);

/*retorna 1 se a fila de prioridade estiver vazia ou 
 0 se pelo menos umas das subfilas conter um elemento*/
int filaPrioVazia(struct prioQueue *q);

//insere o nome em umas das fila de acordo com seu tipo(0-Idoso, 1-Especial, 2-Comum)
void enqueuePrio(struct prioQueue *q, char *nome, int type);

//remove um nome da fila respeitando a ordem das prioridades
char *dequeuePrio(struct prioQueue *q);

//printa as 3 filas
void printQueuePrio(struct prioQueue *q);

//conta os clientes chamados e implementa a politica de "aging"
void aging(struct prioQueue *q);

#endif