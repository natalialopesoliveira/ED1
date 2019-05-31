#include "dlist.h"
#include <stdlib.h>

List *createList(){
    List *list;
    list = (List *)malloc(sizeof(List));
    if(!list) return NULL;
    list->size = 0;
    list->first = NULL;
    return list;
}

Node *createNode(){
    Node *ptr;
    ptr = (Node *)malloc(sizeof(Node));
    if(!ptr) return NULL;
    ptr->chave = 'a';
    ptr->prev = NULL;
    ptr->next = NULL;
    return ptr;
}

void insertLast(List *list, char ch){
    if(!list) return;
    Node *ptr = createNode(), *aux;
    if(!ptr) return;
    ptr->chave = ch;
    if(!list->first){
        list->first = ptr;
    }else{
        for(aux = list->first; aux->next; aux = aux->next);
        aux->next = ptr;
        ptr->prev = aux;
    }
    list->size++;
}

void revertList(List *list){
    Node *prev = NULL, *current, *next;
    if(!list || list->size <2) return;
    current = list->first;
    while(current){
        next = current->next;
        current->prev = next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list->first = prev;
}

void printList(List *list){
    printf("\nINÍCIO [ ");
    if(!list || !list->first){
        printf("] FIM\n");
        return;
    }
    Node *aux;
    for(aux = list->first; aux; aux = aux->next){
        printf("%c ",aux->chave);
    }
    printf("] FIM\n");
}
