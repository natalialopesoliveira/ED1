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

Info *createInfo();

void imprimeDList(DList *dlist);

int buscaOrdenada(DList *dlist, Info *info);

void insertLast(DList *dlist,Info *info);

void insertFist(DList *dlist, Info *info);

void insertPos(DList *dlist, Info *info, int pos);

int deleteFirst(DList *dlist);

int deleteLast(DList *dlist);

void deleteValue(DList *dlist, int value);

void deletePos(DList *dlist, int pos);

#endif // __LISTAD_H__