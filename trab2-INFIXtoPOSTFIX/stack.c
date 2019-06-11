#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

Stack *createStack(){
    Stack *ptr;
    if((ptr=(Stack *)malloc(sizeof(Stack)))){
        ptr->size=0;
        ptr->first=NULL;
        return ptr;
    }
return NULL;
}

Node *createNode(){
    Node *ptr;
    if((ptr=(Node *)malloc(sizeof(Node)))){
        ptr->info=NULL;
        ptr->next=NULL;
        return ptr;
    }
    return NULL;
}

Info *createInfo(char c){
    Info *ptr;
    if((ptr=(Info *)malloc(sizeof(Info)))){
        ptr->value=c;
        return ptr;
    }
    return NULL;
}

void freeStack(Stack *stack){
    Node *aux;
    if (!stack) return;
    while(stack->first){
        aux=stack->first;
        stack->first=stack->first->next;
        free(aux->info);
        free(aux);
    }
    free(stack);
}

bool isEmptyStack(Stack *stack){
    if(!stack) return true;
    if(stack->first) return false;
    else return true;
}

void printStack(Stack *stack){
    Node *ptr;
    if(isEmptyStack(stack)) return;
    printf("\n TOP[ ");
    ptr=stack->first;
    while(ptr)
    {
        //fazer impressao de vetor de char
        printf("%c ",ptr->info->value);
        ptr = ptr->next;
    }
    printf("]BOTTOM");
}

int lenghtStack(Stack *stack){
    if (!stack) return -1;
    return stack->size;
}

bool push(Stack *stack, Info *info){
    Node *ptr;
    if((ptr=createNode()) && (stack)){
        ptr->info=info;
        ptr->next=stack->first;
        stack->first=ptr;
        stack->size++;
        return true;
    } else return false;
}

char pop(Stack *stack){
    if(!stack || isEmptyStack(stack)) return 0;
    Node *ptr;
    char info;
    ptr=stack->first;
    stack->first=ptr->next;
    stack->size--;
    info=ptr->info->value;
    free(ptr);
    return info;
}

char getInfo(Stack *stack){
    char info;
    if(!isEmptyStack(stack) || !stack){
        info=stack->first->info->value;
        return info;
    } else return 0;
}
