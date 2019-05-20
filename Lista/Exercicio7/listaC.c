#include <stdlib.h>
#include <stdio.h>
#include "listaC.h"

Node *createNode(int valor){
    Node *ptr;
    ptr = (Node *)malloc(sizeof(Node));
    if(!ptr) return NULL;
    ptr->valor = valor;
    ptr->prox = ptr;
    return ptr;

}

void insertLast(Node *inicio, Node *ultimo, int valor){
    Node *ptr, *aux;
    if(!inicio) return;
    ptr = createNode(valor);
    if(!ptr) return;
    //..
}

void printList(Node *inicio){
    Node *aux;
    printf("\nINICIO [ ");
    if(!inicio){
        printf("] FIM\n");
        return;
    }
    //..
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
