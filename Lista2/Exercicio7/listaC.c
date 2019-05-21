#include <stdlib.h>
#include <stdio.h>
#include "listaC.h"

Node *createNode(int valor){
    Node *ptr;
    ptr = (Node *)malloc(sizeof(Node));
    if(!ptr) return NULL;
    ptr->valor = valor;
    ptr->prox = NULL;
    return ptr;

}

void insertFirst(Node **inicio, Node **ultimo, int valor){
    Node *ptr;
    ptr = createNode(valor);
    if(!ptr) return;
    if(!(*inicio)){
        *inicio = ptr;
        *ultimo = ptr;
    } else if(*inicio == *ultimo){
        ptr->prox = *inicio;
        (*inicio)->prox = ptr;
        *inicio = ptr;
    }else{
        ptr->prox = (*inicio);
        (*ultimo)->prox = ptr;
        *inicio = ptr;
    }
}

int removeFirst(Node **inicio, Node **ultimo){
    int info;
    if(!(*inicio)) return 0;
    if(*inicio == *ultimo){
        info = (*inicio)->valor;
        *inicio = NULL;
        *ultimo = NULL;
    } else {
        (*ultimo)->prox = (*inicio)->prox;
        info = (*inicio)->valor;
        (*inicio) = (*inicio)->prox;
    }
    return info;
}

void insertLast(Node *inicio, Node **ultimo, int valor){
    Node *ptr, *aux;
    if(!inicio) return;
    ptr = createNode(valor);
    if(!ptr) return;
    if(inicio == *ultimo){
        //printNode(ptr);
        ptr->prox = inicio;
        inicio->prox = ptr;
        *ultimo = ptr;
    } else{
        ptr->prox = inicio;
        (*ultimo)->prox = ptr;
        *ultimo = ptr;
    }
    // ptr->prox = inicio;
    // ultimo->prox = ptr;
    // ultimo = ptr;
    //..
}

void printList(Node *inicio){
    Node *aux;
    printf("\nINICIO [ ");
    if(!inicio){
        printf("] FIM\n");
        return;
    }
    aux = inicio;
    printf("%d ",aux->valor);
    for(aux=aux->prox; aux != inicio; aux = aux->prox){
        printf("%d ",aux->valor);
    }
    printf("] FIM\n");
}

void printNode(Node *node){
    if(!node) return;
    printf("\nNode: [ %d ]", node->valor);
    if(node->prox){
        printf("\nNode->prox: [ %d ]", node->prox->valor);
    }else{
        printf("\nNode->prox: [ ]");
    }
}
