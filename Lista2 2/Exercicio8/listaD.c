#include <stdio.h>
#include <stdlib.h>
#include "listaD.h"

Node *createNode(){
    Node *ptr;
    ptr = (Node *)malloc(sizeof(Node));
    if(!ptr){
        printf("\nMemória insuficiente.");
        return NULL;
    }
    ptr->info = NULL;
    ptr->next = NULL;
    ptr->prev = NULL;
    return ptr;
}

Info *createInfo(char inf){
    Info *info;
    // char inf;
    info = (Info *)malloc(sizeof(Info));
    if(!info){
        printf("\nMemória insuficiente.");
        return NULL;
    }
    // printf("\nDigite o elemento de informação: ");
    // scanf("%c", &inf);
    info->info = inf;
    return info;
}

List *createList(){
    List *list;
    list = (List *)malloc(sizeof(List));
    if(!list){
        printf("\nMemória insuficiente.");
        return NULL;
    }
    list->last = NULL;
    list->window = NULL;
    list->first = NULL;
    list->size = 0;
    return list;
}

void insertLast(List *list, Info *info){
    if(!list || !info){
        printf("\nLista ou elemento de informação inexistentes.");
        return;
    }
    Node *aux, *ptr = createNode();
    ptr->info = info;
    if(list->size == 0){
        list->first = ptr;

    } else {
        aux = list->last;
        aux->next = ptr;
        ptr->prev = aux;
    }
    list->last = ptr;
    list->size++;
}

void posList(List *list, int pos){
    if(!list || pos > list->size || pos <= 0){
        printf("\nLista inexistente ou posição inválida.");
        return;
    }
    Node *aux;
    aux = list->first;
    for(int i = 1; i < pos; i++){
         aux = aux->next;
    }
    list->window = aux;
}

Info *infoList(List *list){
    if(!list || !list->window || list->size == 0){
        printf("\nLista inexistente ou não há nenhuma janela.");
        return NULL;
    }
    Node *aux;
    Info *info = list->window->info;
    if (list->first == list->last){
        aux = list->first;
        list->last = NULL;
        list->first = NULL;

    } else if(list->first == list->window){
        aux = list->first;
        list->first = aux->next;
        aux->next->prev = NULL;

    } else if (list->last == list->window){
        for(aux = list->first; aux->next != list->window; aux = aux->next);
        aux->next = NULL;
        list->last = aux;
        aux = list->window;
    } else{
        for(aux = list->first; aux->next != list->window; aux = aux->next);
        list->window->next->prev = aux;
        aux->next = list->window->next;
        aux = list->window;
    }
    list->window = NULL;
    free(aux);
    list->size--;
    return info;
}

void printList(List *list){
    if(!list) return;
    printf("\nINICIO [ ");
    if(list->size == 0){
        printf("] FIM\n");
        return;
    }
    Node *aux;
    for(aux = list->first; aux != list->last; aux = aux->next){
        printf("%c ", aux->info->info);
    }
    printf("%c ", aux->info->info);
    printf("] FIM\n");
}

List *ordenaList(List *list){
    if(!list || !list->first || list->size == 0) return NULL;
    Node *aux = list->first, *aux2;
    int i, j, size = list->size;
    for(i=0; i<size; i++){
        aux = list->first;
        for(j=0; j<(size-i-1); j++){
            aux2 = aux->next;
            if(aux->info->info > aux2->info->info){
                if(list->first == aux) list->first = aux2;
                if(list->last == aux2) list->last = aux;
                if(aux->prev) aux->prev->next = aux2;
                if(aux2->next) aux2->next->prev = aux;
                aux2->prev = aux->prev;
                aux->next = aux2->next;
                aux2->next = aux;
                aux->prev = aux2;
            }else{
                aux = aux2;
            }
            printList(list);
        }
    }
    return list;
}
