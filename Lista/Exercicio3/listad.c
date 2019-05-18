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
    dlist->size--;
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
    dlist->size--;
    return info;
}

int deletePos(DList *dlist, int pos){
    Node *aux;
    int value, i;
    if(!dlist || pos < 1 || pos > dlist->size || dlist->size == 0) return 0;
    if(pos == 1){
       return deleteFirst(dlist);
    } else if(pos == dlist->size)
        return deleteLast(dlist);
    else {
        for(aux=dlist->first, i=1; i<pos; aux = aux->next,i++);
        if(aux->next){
            aux->prev->next = aux->next;
            aux->next->prev = aux->prev;
        }else{
            aux->prev->next = NULL;
        }
    }
    dlist->size--;
    value = aux->info->info;
    free(aux);
    return value;
}

void intercalaLista(DList *dlist1, DList *dlist2, DList *dlist3){
    Node *aux1, *aux2, *ptr, *ptrAnt;
    if(!dlist1 || !dlist2 || !dlist3 || dlist1->size == 0 || dlist2->size == 0) return;
    int size3;
    if(dlist1->size >= dlist2->size){
        aux2=dlist2->first;
        for(aux1=dlist1->first; aux1; aux1=aux1->next){
            if(ptr) ptrAnt = ptr;
            ptr = (Node *)malloc(sizeof(Node));
            if(!dlist3->first) dlist3->first = ptr;
            ptr->info = aux1->info;
            ptr->next = NULL;
            ptr->prev = NULL;
            dlist3->size++;
            if(dlist3->size != 1){
                ptr->prev = ptrAnt;
                ptr->prev->next = ptr;
            }
            if(aux2){
                ptrAnt = ptr;
                ptr = (Node *)malloc(sizeof(Node));
                ptr->info = aux2->info;
                ptr->next = NULL;
                ptr->prev = ptrAnt;
                ptr->prev->next = ptr;
                dlist3->size++;
                aux2=aux2->next;
            }
        }
    } else {
        aux2=dlist2->first;
        for(aux1=dlist1->first; aux1; aux1=aux1->next){
            if(ptr) ptrAnt = ptr;
            ptr = (Node *)malloc(sizeof(Node));
            if(!dlist3->first) dlist3->first = ptr;
            ptr->info = aux1->info;
            ptr->next = NULL;
            ptr->prev = NULL;
            dlist3->size++;
            if(dlist3->size != 1){
                ptr->prev = ptrAnt;
                ptr->prev->next = ptr;
            }
            ptrAnt = ptr;
            ptr = (Node *)malloc(sizeof(Node));
            ptr->info = aux2->info;
            ptr->next = NULL;
            ptr->prev = ptrAnt;
            ptr->prev->next = ptr;
            dlist3->size++;
            aux2=aux2->next;
        }
        while(aux2){
            ptrAnt = ptr;
            ptr = (Node *)malloc(sizeof(Node));
            ptr->info = aux2->info;
            ptr->next = NULL;
            ptr->prev = ptrAnt;
            ptr->prev->next = ptr;
            dlist3->size++;
            aux2=aux2->next;
        }
    }
}
