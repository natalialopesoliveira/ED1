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

void insertPos(Lista *lista, int ch, int pos){
    No *aux, *ptr;
    int size=0;
    int i;
    if(!lista || (!lista->inicio && pos != 1)) return;
    if(lista->inicio){
        for(aux = lista->inicio; aux; aux = aux->prox){
            size++;
        }
    } else size = 0;
    if(pos > (size+1) || pos <= 0) return;
    if(pos == 1) insertFirst(lista, ch);
    else if(pos == (size+1)) insertLast(lista, ch);
    else {
        ptr = createNode();
        if(!ptr) return;
        ptr->ch = ch;
        for(aux = lista->inicio, i = 1; i<pos; i++, aux = aux->prox);
        ptr->ant = aux->ant;
        ptr->prox = aux;
        aux->ant->prox = ptr;
        aux->ant = ptr;
    }
}

void exchangeInfo(Lista *lista1, Lista *lista2, int ch1, int ch2){
    if(!lista1 || !lista2 || ch1 == ch2) return;
    int pos1, pos2;
    pos1 = getPos(lista1, ch1);
    pos2 = getPos(lista2, ch2);
    if(pos1 != 0){
        if(pos1 > getSize(lista2)) insertLast(lista2,ch1);
        else insertPos(lista2, ch1, pos1);
    }
    if(pos2 != 0){
        if(pos2 > getSize(lista1)) insertLast(lista1,ch2);
        else insertPos(lista1, ch2, pos2);
    }
    removeInfo(lista1, ch1);
    removeInfo(lista2, ch2);
}

int getPos(Lista *lista, int ch){
    if(!lista || !lista->inicio) return 0;
    int i=0;
    No *aux;
    for(aux = lista->inicio; aux; aux = aux->prox){
        i++;
        if(aux->ch == ch) return i;
    }
    return 0;
}

int getSize(Lista *lista){
    if(!lista || !lista->inicio) return 0;
    int size=0;
    No *aux;
    for(aux = lista->inicio; aux; aux = aux->prox, size++);
    return size;
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
