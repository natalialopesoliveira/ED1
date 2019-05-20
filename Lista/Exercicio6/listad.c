#include <stdlib.h>
#include <stdio.h>
#include "listad.h"

Lista *createList(){
    Lista *lista;
    lista = (Lista *)malloc(sizeof(Lista));
    if(!lista) return NULL;
    lista->inicio = NULL;
    lista->fim = NULL;
    return lista;
}

No *createNode(){
    No *ptr;
    ptr = (No *)malloc(sizeof(No));
    if(!ptr) return NULL;
    ptr->ch = 0;
    ptr->prox = NULL;
    ptr->ant = NULL;
    return ptr;
}

void insertFirst(Lista *lista, int ch){
    No *ptr, *aux;
    if(!lista || !(ptr = createNode()))
        return;
    ptr->ch = ch;
    if(lista->inicio){
        aux = lista->inicio;
        if(lista->inicio == lista->fim) lista->fim = aux;
        lista->inicio = ptr;
        lista->inicio->prox = aux;
        lista->inicio->prox->ant = lista->inicio;
    }else {
        lista->inicio = ptr;
        lista->fim = ptr;
    }
}

void insertLast(Lista *lista, int ch){
    No *ptr, *aux;
    if(!lista || !(ptr = createNode()))
        return;
    ptr->ch = ch;
    if(lista->fim){
        aux = lista->fim;
        if(lista->inicio == lista->fim) lista->inicio = aux;
        lista->fim = ptr;
        lista->fim->ant = aux;
        lista->fim->ant->prox = lista->fim;
    } else {
        lista->inicio = ptr;
        lista->fim = ptr;
    }
}

void removeInfo(Lista *lista, int ch){
    No *aux, *aux2;
    if(!lista || !lista->inicio) return;
    for(aux = lista->inicio; aux; aux = aux->prox){
        if(aux->ch == ch){
            if(aux->ant && aux->prox){
                aux->ant->prox = aux->prox;
                aux->prox->ant = aux->ant;
            } else if(aux->ant){
                aux->ant->prox = NULL;
                lista->fim = aux->ant;
            } else if(aux->prox){
                aux->prox->ant = NULL;
                lista->inicio = aux->prox;
            } else {
                lista->inicio = NULL;
                lista->fim = NULL;
            }
        }
    }
}

void printList(Lista *lista){
    No *aux;
    printf("\nINICIO [ ");
    if(!lista || !lista->inicio){
        printf("] FIM\n");
        return;
    }
    for(aux = lista->inicio; aux; aux = aux->prox){
        printf("%d ",aux->ch);
    }
    printf("] FIM\n");
}