
#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

//cd "/Users/onatalia86/Desktop/" && gcc -lstdc++ mainExpression.c -o mainExpression && "/Users/onatalia86/Desktop/"mainExpression

Stack *createStack(){
    Stack *stack;
    stack = (Stack *)malloc(sizeof(Stack));
    if(!stack) return NULL;
    stack->size = 0;
    stack->first = NULL;
    return stack;
}

Node *createNode(){
    Node *node;
    Info *info;
    node = (Node *)malloc(sizeof(Node));
    info = createInfo();
    if(!node || !info) return NULL;
    node->next = NULL;
    node->info = info;
    return node;
}

Info *createInfo(){
    Info *info;
    info = (Info *)malloc(sizeof(Info));
    if(!info) return NULL;
    info->info = NULL;
    return info;
}

void salvarInfo(Info *info){
    int value;
    if(!info) return;
    printf("Digite o valor da informação: ");
    scanf("%d",&value);
    info->info = value;
}

void imprimeStack(Stack *stack){
    Node *ptr;
    if(!stack) return;
    printf("TOP [ ");
    if(stack->first){
        for(ptr = stack->first;ptr;ptr=ptr->next){
            printf("%d ",ptr->info->info);
        }
    }
    printf("] BOTTOM\n");
}

bool empilhar(Stack *stack, Info *info){
    Node *ptr;
    ptr = createNode();
    if(!stack || !ptr) return false;
    ptr->next = stack->first;
    ptr->info = info;
    stack->first = ptr;
    stack->size++;
    return true;
}

int desempilhar(Stack *stack){
    Node *ptr;
    int info;
    if (!stack || stack->size == 0) return NULL;
    ptr = stack->first;
    info = ptr->info->info;
    if(stack->size == 1){
        stack->first = NULL;
    } else stack->first = stack->first->next;
    free(ptr->info);
    free(ptr);
    stack->size--;
    if(stack->size == 0) stack->first = NULL;
    return info;
}

int altura(Stack *stack){
    int altura;
    if(!stack) return NULL;
    altura = stack->size;
    return altura;
}

int topo(Stack *stack){
    int topo;
    if(!stack || stack->size == 0) return NULL;
    topo = stack->first->info->info;
    return topo;
}
