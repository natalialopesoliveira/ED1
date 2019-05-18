#include <stdio.h>
#include <stdlib.h>
#include "listad.h"

//cria lista
DList *createDList(){
    DList *ptr;
    ptr=(DList *)malloc(sizeof(DList));
    if(ptr){
        ptr->size = 0;
        ptr->first = NULL;
        return ptr;
    } else return NULL;
}

Info *createInfo(){
    Info *info;
    int value;
    info = (Info *)malloc(sizeof(Info));
    if (!info) return NULL;
    printf("\nDigite o valor da informação: ");
    scanf("%d",&value);
    info->info = value;
    return info;
}

void imprimeDList(DList *dlist){
    Node *ptr;
    if(!dlist || dlist->size == 0) return;
    printf("\nINICIO [ ");
    for(ptr=dlist->first;ptr;ptr=ptr->next){
        printf("%d ",ptr->info->info);
    }
    printf("] FIM\n");
}

// int buscaOrdenada(DList *dlist, Info *info){
//     Node *aux;
//     if(!dlist || dlist->size == 0) return NULL;
//     int divisao, i = 0, j, posicaoMenor = 1, posicaoMaior, posicao, size, info, ordenacao;
//     info = info->info;
//     size = dlist->size;
//     posicaoMaior = size;
//     //verificar se a lista está ordenada crescente ou decrescente
    
//     // for(j=1;j<posicao;j++, aux = aux->next);
//     if(size == 1){
//         if((aux = dlist->first) == info) return 1; 
//         else return NULL;
//     } else {
//         aux = dlist->first;
//         if (aux->info->info < aux->next->info->info) ordenacao=1;
//         else if(aux->info->info > aux->next->info->info) ordenacao = -1;
//         else{
//             aux = aux->next;
//             if 
//             if((aux->info->info > aux->next->info->info) &&
//         }
//     }
//     while (i == 0){
//         posicao = (posicaoMaior + posicaoMenor)/2;
//         for(j=0, aux = dlist->first;j<posicao ;j++, aux = aux->next);
//         if(aux->info->info == info) return posicao;

//         //se posicaoAnt == posicao , return NULL
//     }
// }

void insertLast(DList *dlist,Info *info){
    Node *ptr, *aux;
    ptr=(Node *)malloc(sizeof(Node));
    if(!dlist || !ptr) return;
    ptr->info = info;
    ptr->next = NULL;
    //se for vazia
    if(dlist->size == 0){
        dlist->first = ptr;
        ptr->prev = NULL;
    } else if(dlist->size == 1) {
        dlist->first->next = ptr;
        ptr->prev = dlist->first;
    }else{
        for(aux = dlist->first ; aux->next; aux = aux->next);
        aux->next = ptr;
        ptr->prev = aux;
    }
    dlist->size++;
}

void insertFist(DList *dlist, Info *info){
    Node *ptr, *aux;
    ptr = (Node *)malloc(sizeof(Node));
    if(!dlist || !ptr) return;
    ptr->info = info;
    //se for vazia
    if(dlist->size == 0){
        dlist->first = ptr;
        ptr->prev = NULL;
        ptr->next = NULL;
    } else {
        aux = dlist->first;
        dlist->first = ptr;
        ptr->prev = NULL;
        ptr->next = aux;
        aux->prev = ptr;
    }
    dlist->size++;
}

void insertPos(DList *dlist, Info *info, int pos){
    Node *ptr, *aux;
    int i= 1;
    if(!dlist) return;
    ptr = (Node *)malloc(sizeof(Node));
    if(!ptr) return;
    if(pos > dlist->size || pos < 1){
        free(ptr);
        return;
    }
    if(pos == 1)
        insertFist(dlist, info);
    else {
        for(aux=dlist->first;i<pos;aux=aux->next,i++);
        ptr->prev = aux->prev;
        ptr->next = aux;
        aux->prev->next = ptr;
        if(aux->next)
            aux->next->prev = ptr;
    }
    ptr->info = info;
    dlist->size++;
}

int deleteFirst(DList *dlist){
    Node *ptr, *aux;
    int info;
    if(!dlist || dlist->size == 0) return 0;
    if(dlist->size == 1){
        ptr = dlist->first;
        dlist->first = NULL;
    } else {
        ptr = dlist->first;
        ptr->next->prev = NULL;
        dlist->first = dlist->first->next;
    }
    info = ptr->info->info;
    free(ptr);
    return info;
}

int deleteLast(DList *dlist){
    Node *ptr, *aux;
    int info;
    if(!dlist || dlist->size == 0) return 0;
    if(dlist->size == 1){
        ptr = dlist->first;
        dlist->first = NULL;
    } else {
        for(aux=dlist->first;aux->next;aux=aux->next);
        ptr=aux;
        ptr->prev->next = NULL;
    }
    info = ptr->info->info;
    free(ptr);
    return info;
}
