#ifndef _STACK_H
#define _STACK_H

// DEFINIÇÃO DA ESTRUTURA DE DADOS:
#include <stdbool.h> 


typedef struct{
    char value;
}Info;

typedef struct tnode{
    struct tnode *next;
    Info *info;
}Node;

typedef struct{
    int size;
    Node *first;
}Stack;

//FUNÇÕES DA TAD E SUAS RESPECTIVAS ASSINATURAS:
//TODO:: assinaturas
Stack *createStack();

Node *createNode();

Info *createInfo(char c);

void freeStack(Stack *stack);

bool isEmptyStack(Stack *stack);

void printStack(Stack *stack);

int lenghtStack(Stack *stack);

bool push(Stack *stack, Info *info);

char pop(Stack *stack);

char getInfo(Stack *stack);

#endif