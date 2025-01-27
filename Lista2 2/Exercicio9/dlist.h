#ifndef __DLIST_H__
#define __DLIST_H__

#include <stdbool.h>

typedef struct tnode{
    char chave;
    struct tnode *prev;
    struct tnode *next;
}Node;

typedef struct{
    int size;
    Node *first;
}List;

List *createList();

Node *createNode();

void insertLast(List *list, char ch);

void revertList(List *list);

void printList(List *list);

#endif // __DLIST_H__
