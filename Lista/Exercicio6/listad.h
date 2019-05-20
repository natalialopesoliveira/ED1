#ifndef __LISTAD_H__
#define __LISTAD_H__

typedef struct no{
    int ch;
    struct no *prox, *ant;
}No;

typedef struct lista{
    No *inicio, *fim;
}Lista;

Lista *createList(); //sim
No *createNode(); //sim
void insertFirst(Lista *lista, int ch); //sim
void insertLast(Lista *lista, int ch); //sim
void removeInfo(Lista *lista, int ch); // sim
void exchangeInfo(Lista *lista1, Lista *lista2, int ch1, int ch2);
void printList(Lista *lista); //sim

#endif // __LISTAD_H__