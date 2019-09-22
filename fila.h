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

//seta o inicio e o fim da fila pra NULL
void inicFila(struct queue *q);

//retorna 1 se o inicio da fila for NULL ou 0 caso contrario
int filaVazia(struct queue *q);

//poe um novo nome no final da fila
void enqueue(struct queue *q, char *nome);

/*retorna uma 'char*' com o nome do primeiro da fila
 *esse ponteiro deve ser desalocado */
char *dequeue(struct queue *q);

//printa todos os elementos da fila
void printQueue(struct queue *q);

#endif