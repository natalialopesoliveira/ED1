#ifndef __LIST_H__
#define __LIST_H__

typedef struct{
    char info;
}Info;

typedef struct tno{
    Info *info;
    struct tno *next;
}Node;

typedef struct{
    Node *last, *window, *first;
    int size;
}List;

Node *createNode();
// Info *createInfo();
Info *createInfo(char inf);
List *createList();
void insertLast(List *list, Info *info);
Info *removeFirst(List *list);
void posList(List *list, int pos);
Info *infoList(List *list);
void printList(List *list);

#endif //__LIST_H__
