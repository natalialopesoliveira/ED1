#ifndef __LISTAC_H__
#define __LISTAC_H__

typedef struct tno{
    int valor;
    struct tno *prox;
}Node;

Node* createNode(int valor); //sim
void insertFirst(Node **inicio, Node **ultimo, int valor); //sim
int removeFirst(Node **inicio, Node **ultimo); //sim
void insertLast(Node **inicio, Node **ultimo, int valor); //sim
int removeLast(Node **inicio, Node **ultimo); //sim
void removeInfo(Node **inicio, Node **ultimo, int valor); //sim
void printList(Node *inicio); // sim
void printNode(Node *node); //sim

#endif // __LISTAC_H__
