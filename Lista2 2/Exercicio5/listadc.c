#include <stdlib.h>
#include <stdio.h>
#include "lisdadc.h"

Node *createNode(){
    Node *ptr;
    int chave;
    ptr = (Node *)malloc(sizeof(Node));
    if(!ptr) return NULL;
    ptr->prev = ptr;
    ptr->next = ptr;
    printf("\nDigite o elemento de informação: ");
    scanf("%d", &chave);
    ptr->info = chave;
    return ptr;
}

void insertFirst(Node **first){
    Node *ptr, *aux;
    ptr = createNode();
    if(!ptr) return;
    if(!(*first)){
        *first = ptr;
        return;
    } else if ((*first)->next == *first) {
        aux = *first;
        *first = ptr;
        (*first)->next = aux;
        (*first)->prev = aux;
        (*first)->next->next = *first;
        (*first)->next->prev = *first;
    } else {
        aux = *first;
        *first = ptr;
        (*first)->next = aux;
        (*first)->prev = aux->prev;
        (*first)->prev->next = *first;
        (*first)->next->prev = *first;
    }
}

int removeFirst(Node **first){
    Node *aux;
    int info;
    if(!(*first)) return 0;
    aux = *first;
    if((*first)->next == *first){
        *first = NULL;
    } else {
        aux->prev->next = aux->next;
        aux->next->prev = aux->prev;
        *first = (*first)->next;
    }
    info = aux->info;
    free(aux);
    return info;
}

void insertLast(Node **first){
    Node *ptr, *aux;
    ptr = createNode();
    if(!ptr) return;
    if(!(*first)){
        *first = ptr;
        return;
    } else if ((*first)->next == *first) {
        (*first)->prev = ptr;
        (*first)->next = ptr;
        ptr->prev = *first;
        ptr->next = *first;
    } else {
        (*first)->prev->next = ptr;
        ptr->prev = (*first)->prev;
        ptr->next = *first;
        (*first)->prev = ptr;
    }
}

int removeLast(Node **first){
    Node *aux;
    int info;
    if(!(*first)) return 0;
    if((*first)->next == *first){
        aux = *first;
        *first = NULL;
    } else {
        aux = (*first)->prev;
        (*first)->prev = aux->prev;
        aux->prev->next = (*first);
    }
    info = aux->info;
    free(aux);
    return info;
}

void removeInfo(Node **first, int info){
    if(!(*first)) return;
    Node *aux;
    if((*first)->info == info){
        if((*first)->info == info)
            removeFirst(first);
        return;
    } else {
        for(aux = (*first)->next; aux != *first; aux = aux->next){
            if(aux->info == info){
                removeFirst(&aux);
            }
        }
    }
}

void printDList(Node *first){
    printf("\nINICIO [ ");
    Node *aux;
    if(!first ){
        printf("] FIM\n");
        return;
    }
    if(first->next == first){
        printf("%d ", first->info);
    } else{
        printf("%d ", first->info);
        for(aux = first->next; aux != first; aux = aux->next){
            printf("%d ", aux->info);
        }
    }
    printf("] FIM\n");
}

void printNode(Node *node){
    if(!node) return;
    printf("\nNode: [ %d ]",node->info);
    printf("\nNode->prev: [ %d ]",node->prev->info);
    printf("\nNode->next: [ %d ]",node->next->info);
    return;
}
