#ifndef __FILA_H__
#define __FILA_H__

#include <stdbool.h>

typedef struct{
    int value;
}Info;

typedef struct tnode{
    Info *info;
    struct tnode *next;
}Node;

typedef struct {
    int size;
    Node *first;
}Queue;

Queue *createQueue();

Info *createInfo();

Node *createNode();

void imprimeQueue(Queue *queue);

void enfileirar(Queue *queue, Info *info);

int desenfileirar(Queue *queue);

int comprimento(Queue *queue);

int proximo(Queue *queue, Info *info);

#endif // __FILA_H__