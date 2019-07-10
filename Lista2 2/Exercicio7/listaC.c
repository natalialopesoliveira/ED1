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
    Node *aux;
    if(!(*inicio)) return 0;
    aux = *inicio;
    if(*inicio == *ultimo){
        info = (*inicio)->valor;
        *inicio = NULL;
        *ultimo = NULL;
    } else {
        (*ultimo)->prox = (*inicio)->prox;
        info = (*inicio)->valor;
        (*inicio) = (*inicio)->prox;
    }
    free(aux);
    return info;
}

void insertLast(Node **inicio, Node **ultimo, int valor){
    Node *ptr, *aux;
    if(!(*inicio)) return;
    ptr = createNode(valor);
    if(!ptr) return;
    if(*inicio == *ultimo){
        //printNode(ptr);
        ptr->prox = *inicio;
        (*inicio)->prox = ptr;
        *ultimo = ptr;
    } else{
        ptr->prox = *inicio;
        (*ultimo)->prox = ptr;
        *ultimo = ptr;
    }
}

int removeLast(Node **inicio, Node **ultimo){
    int info;
    Node *aux, *aux2;
    if(!(*inicio)) return 0;
    aux2 = *ultimo;
    if(*inicio == *ultimo){
        info = (*ultimo)->valor;
        *ultimo = NULL;
        *inicio = NULL;
    }else{
        for(aux = *inicio; aux->prox != *ultimo; aux = aux->prox);
        aux->prox = (*inicio);
        info = (*ultimo)->valor;
        *ultimo = aux;
    }
    free(aux2);
    return info;
}

void removeInfo(Node **inicio, Node **ultimo, int valor){
    Node *aux, *aux2;
    int i;
    if(!inicio) return;
    if(*inicio == *ultimo && (*inicio)->valor == valor){
        removeFirst(inicio, ultimo);
    } else if((*inicio)->valor == valor){
        removeFirst(inicio, ultimo);
    } else if((*ultimo)->valor == valor){
        removeLast(inicio, ultimo);
    }else{
        for(aux = *inicio; aux->valor != valor && aux != *ultimo; aux = aux->prox){
            if(aux->prox->valor == valor){
                aux2 = aux->prox;
                aux->prox = aux->prox->prox;
                free(aux2);
                return;
            }
        }
    }
    return;
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
