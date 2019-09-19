#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elemento{
    char nome[50];
    struct elemento *next;
};

struct queue{
    struct elemento *inicio, *fim;
};

void inicFila(struct queue *q);

int filaVazia(struct queue *q);

void enqueue(struct queue *q, char *nome);

char *dequeue(struct queue *q);

void printQueue(struct queue *q);

#endif