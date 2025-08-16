#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0


// Structures
typedef struct data
{
    int info;
} DATA;

typedef struct Node_t
{
    DATA data;
    struct Node_t *prev;
} NODE;

typedef struct Queue
{
    NODE *head;
    NODE *tail;
    int size;
    int limit;
} Queue;

// functions

Queue *ConstructQueue(int limit);
void DestructQueue(Queue *queue);
int Enqueue(Queue *queue, NODE *item);
NODE *Dequeue(Queue *pQueue);
int isEmpty(Queue *q);

// implementations

Queue *ConstructQueue(int limit){
    Queue *queue = (Queue *) malloc(sizeof(Queue));

    if(queue == NULL){
        return NULL;
    }

    if(limit <= 0){
        limit = 655335;
    }

    queue->limit = limit;
    queue->size = 0;
    queue->head = NULL;
    queue->tail = NULL;

    return queue;
}

void DestructQueue(Queue *queue){
    NODE *pN;
    while(!isEmpty(queue)){
        pN = Dequeue(queue);
        free(pN);
    }
    free(queue);
}

int Enqueue(Queue *queue, NODE *item){
    if(queue == NULL || item == NULL){
        return FALSE;
    }

    if(queue->size >= queue->limit){
        return FALSE;
    }

    item->prev == NULL;
    if(queue->size == 0){
        queue->head = item;
        queue->tail = item;
    }else{
        queue->tail->prev = item;
        queue->tail = item;
    }
    queue->size++;

    return TRUE;
}

NODE *Dequeue(Queue *queue){
    NODE *item;
    if(isEmpty(queue)){
        return NULL;
    }

    item = queue->head;
    queue->head = (queue->head)->prev;
    queue->size--;

    return item;
}

int isEmpty(Queue *queue){
    if(queue == NULL){
        return FALSE;
    }

    if(queue->size == 0){
        return TRUE;
    }else{
        return FALSE;
    }
}

// main

int main(){
    int i, value;
    Queue *q = ConstructQueue(7);
    NODE *node;

    for(i = 0; i < 7; i++){
        node = (NODE *) malloc(sizeof(NODE));
        value = 100 + i;
        printf("Entrando na fila: %d\n", value);
        node->data.info = value;
        Enqueue(q, node);
    }

    while(!isEmpty(q)){
        node = Dequeue(q);
        printf("\nSaindo da fila: %d\n", node->data.info);
        free(node);
    }

    DestructQueue(q);
    return(EXIT_SUCCESS);

}