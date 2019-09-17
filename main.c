#include <stdio.h>
#include <stdlib.h>
#include "filaPrioridade.h"

int main()
{
    struct prioQueue q;
    inicFilaPrio(&q);
    enqueuePrio(&q, "Joao", 0);
    enqueuePrio(&q, "Ze", 1);
    enqueuePrio(&q, "Maria", 2);
    printQueuePrio(&q);
    printf("\nRemovendo %s\n", dequeuePrio(&q));
    printQueuePrio(&q);
    return 0;
}
