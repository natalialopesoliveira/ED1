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

DList *createDList();

int buscaOrdenada(DList *dlist, Info *info);

void insertLast(DList *dlist,Info *info);

void insertFist(DList *dlist, Info *info);

void deleteLast(DList *dlist,Info *info);

#endif // __LISTAD_H__