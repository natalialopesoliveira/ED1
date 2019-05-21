#ifndef __LISTAC_H__
#define __LISTAC_H__

typedef struct tno{
    int valor;
    struct tno *prox;
}Node;

Node* createNode(int valor);
void insertFirst(Node *inicio, Node *ultimo, int valor);
int removeFirst(Node *inicio, Node *ultimo);
void insertLast(Node *inicio, Node *ultimo, int valor);
int removeLast(Node *inicio, Node *ultimo);
void removeInfo(Node *inicio, Node *ultimo, int valor);
void printList(Node *inicio);
void printNode(Node *node);


#endif // __LISTAC_H__
