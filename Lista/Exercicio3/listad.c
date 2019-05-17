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

int buscaOrdenada(DList *dlist, Info *info){
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

// void insertLast(DList *dlist,Info *info){
//     Node *ptr, *aux;
//     if(!dlist || !(ptr=(Node *)malloc(sizeof(Node)))) return ;
//     ptr->info = info;
//     ptr->next = NULL;
//     //se for vazia
//     if(dlist->size == 0){
//         dlist->first = ptr;
//         ptr->prev = NULL;
//     } else {
//         for(aux = dlist->first ; aux->next != NULL; aux = aux->next);
//         aux->next = ptr;
//         ptr->prev = aux;
//     }
    return 0;
}

void insertFist(DList *dlist, Info *info){
    Node *ptr, *aux;
    if(!dlist || !(ptr=(Node *)malloc(sizeof(Node)))) return;
    ptr->info = info;
    //se for vazia
    if(dlist->size == 0){
        dlist->first = ptr;
        ptr->prev = NULL;
    } else {
        
    }
}

void deleteLast(DList *dlist,Info *info){

}
