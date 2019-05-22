#ifndef __LISTADC_H__
#define __LISTADC_H__

typedef struct tno{
    struct tno *prev, *next;
    int info;
}Node;

Node *createNode(); //sim

void insertFirst(Node **first); //sim

int removeFirst(Node **first); //sim

void insertLast(Node **first); //sim

int removeLast(Node **first); //sim

void removeInfo(Node **first, int info); //nao

void printDList(Node *first); //sim

void printNode(Node *node); //sim

#endif // __LISTADC_H__
//FALTAM:
//insertFirst
//removeFirst
//removeInfo
