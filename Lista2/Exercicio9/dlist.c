#include "dlist.h"
#include <stdlib.h>
#include <stdbool.h>

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
    ptr->chave = NULL;
    ptr->prev = NULL;
    ptr->next = NULL;
    return ptr;
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
