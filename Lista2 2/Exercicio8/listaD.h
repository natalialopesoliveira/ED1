#ifndef __LISTD_H__
#define __LISTD_H__

typedef struct{
    char info;
}Info;

typedef struct tno{
    Info *info;
    struct tno *prev, *next;
}Node;

typedef struct{
    Node *last, *window, *first;
    int size;
}List;

Node *createNode(); //sim
Info *createInfo(); //sim
Info *createInfo(char inf); //sim
List *createList(); //sim
void insertLast(List *list, Info *info); //sim
void posList(List *list, int pos); //sim
Info *infoList(List *list); //sim
void printList(List *list); //sim
List *ordenaList(List *list); //sim

#endif //__LIST_H__
