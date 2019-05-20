#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Queue *createQueue(){
    Queue *queue;
    queue = (Queue *)malloc(sizeof(Queue));
    if(!queue) return NULL;
    queue->size = 0;
    queue->first = NULL;
    return queue;
}

Info *createInfo(){
    Info *info;
    int value;
    info = (Info *)malloc(sizeof(Info));
    if(!info) return NULL;
    printf("\nDigite o valor da informação: ");
    scanf("%d",&value);
    info->value = value;
    return info;
}

Node *createNode(){
    Node *node;
    Info *info;
    node = (Node *)malloc(sizeof(Node));
    if(!node) return NULL;
    node->info = NULL;
    node->next = NULL;
    return node;
}

void imprimeQueue(Queue *queue){
    Node *ptr;
    if(!queue || queue->size == 0){
        printf("\nINICIO [ ");
        printf("] FIM \n");
    }
    printf("\nINICIO [ ");
    for(ptr=queue->first;ptr;ptr=ptr->next){
        printf("%d ",ptr->info->value);
    }
    printf("] FIM \n");
}

void enfileirar(Queue *queue, Info *info){
    Node *ptr,*comp;
    ptr = createNode();
    if (!ptr || !queue) return;
    ptr->info = info;
    ptr->next = NULL;
    if((queue->size) == 0){
        queue->first = ptr;
    }else if((queue->size) == 1){
        queue->first->next = ptr;
    }else{
        for(comp = queue->first; comp->next;comp = comp->next);
        comp->next = ptr;
    }
    queue->size++;
}


int desenfileirar(Queue *queue){
    Node *ptr;
    int value;
    if(!queue) return 0; //se eu tenho uma funçao int eu posso retornar NULL?
    ptr = queue->first;
    if(ptr->next){
        queue->first = ptr->next; //verificar em pilha se fiz duas vezes a mesma verificaçao.
    }else{
        queue->first = NULL;
    }
    value = ptr->info->value;
    free(ptr);
    queue->size--;
    return value;
}

int comprimento(Queue *queue){
    if (!queue) return 0;
    return queue->size;
}
    
int proximo(Queue *queue, Info *info){
    Node *ptr;
    if(!queue || queue->size == 0) return 0;
    for(ptr = queue->first ; ptr->info == info || ptr->next == NULL ; ptr = ptr->next);
    if(ptr->next == NULL) return 0;
    return ptr->next->info->value;
}
