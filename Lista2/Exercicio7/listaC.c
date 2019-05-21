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

void insertLast(Node *inicio, Node **ultimo, int valor){
    Node *ptr, *aux;
    if(!inicio) return;
    ptr = createNode(valor);
    if(!ptr) return;
    if(inicio == *ultimo){
        //printNode(ptr);
        ptr->prox = inicio;
        inicio->prox = ptr;
        printf("\n\nUltimo dentro - antes insertLast\n\n");
        printNode(*ultimo);
        *ultimo = ptr;
        printf("\n\nUltimo dentro - depois insertLast\n\n");
        printNode(*ultimo);
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
    aux = inicio;
    while(inicio!=NULL){
        printf("[%d]-",aux->valor);
        if(aux->prox == inicio) break;
        aux = aux->prox;
    }
    //..
}

void printNode(Node *node){
    if(!node) return;
    printf("\nNode: [ %d ]", node->valor);
    // if(node->prox){
    //     printf("\nNode->prox: [ %d ]", node->prox->valor);
    // }else{
    //     printf("\nNode->prox: [ ]");
    // }
}
