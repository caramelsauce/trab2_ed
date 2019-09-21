#ifndef FILAP_H
#define FILAP_H

#include "fila.h"

struct prioQueue{
    struct queue *qIdoso;
    struct queue *qEspecial;
    struct queue *qComum;
};

void inicFilaPrio(struct prioQueue *q);

int filaPrioVazia(struct prioQueue *q);

void enqueuePrio(struct prioQueue *q, char *nome, int type);

char *dequeuePrio(struct prioQueue *q);

void printQueuePrio(struct prioQueue *q);

void aging(struct prioQueue *q, int op);

#endif