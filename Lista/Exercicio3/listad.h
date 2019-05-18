#ifndef __LISTAD_H__
#define __LISTAD_H__

#include <stdbool.h>

typedef struct {
    int info;
}Info;

typedef struct tnode{
    Info *info;
    struct tnode *prev;
    struct tnode *next;
}Node;

typedef struct {
    int size;
    Node *first;
}DList;

DList *createDList(); //ok

Info *createInfo(); //ok

void imprimeDList(DList *dlist); //ok

int buscaOrdenada(DList *dlist, Info *info); 

void insertLast(DList *dlist,Info *info); //ok

void insertFist(DList *dlist, Info *info); //ok

void insertPos(DList *dlist, Info *info, int pos); //ok

int deleteFirst(DList *dlist); //ok

int deleteLast(DList *dlist); //ok

void deleteValue(DList *dlist, int value);

void deletePos(DList *dlist, int pos);

#endif // __LISTAD_H__