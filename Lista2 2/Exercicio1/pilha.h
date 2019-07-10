#ifndef __PILHA_H__
#define __PILHA_H__
#include <stdbool.h>

typedef struct {
    int info;
}Info;

typedef struct tnode {
    struct tnode *next;
    Info *info;
}Node;

typedef struct {
    int size;
    Node *first;
}Stack;

Stack *createStack();

Node *createNode();

Info *createInfo();

void salvarInfo(Info *info);

void imprimeStack(Stack *stack);

bool empilhar(Stack *stack, Info *info);

int desempilhar(Stack *stack);

int altura(Stack *stack);

int topo(Stack *stack);
#endif // __PILHA_H__