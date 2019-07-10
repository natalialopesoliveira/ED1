#include <stdlib.h>
#include <stdio.h>
#include "bintree.h"
#include "list.c"

//1)
bintree *createBT(Info *info){
    if(!info) return NULL;
    bintree *bt;
    bt = (bintree *)malloc(sizeof(bintree));
    if(!bt) return NULL;
    bt->info = info;
    bt->left = NULL;
    bt->right = NULL;
    return bt;
}

//2)
bintree *leftBT(bintree *bt){
    if(!bt) return NULL;
    if(bt->left) return bt->left;
    return NULL;
}

//3)
bintree *rightBT(bintree *bt){
    if(!bt) return NULL;
    if(bt->right) return bt->left;
    return NULL;
}

//4)
//dúvida, como posso ter certeza de que estou passando a raiz?
Info *rootBT(bintree *bt){
    if(!bt) return NULL;
    return bt->info;
}

//5)
int isEmptyBT(bintree *bt){
    if(!bt) return 1;
    if(bt->left || bt->right) return 0;
    else return 1;
}

//6)
int isInBT(bintree *bt,Info *info){
    if(!bt || !info) return 0;
    if(isInBT(leftBT(bt),info) || isInBT(rightBT(bt),info)) return 1;
    else return 0;
}

//7)
void destroyBT(bintree *bt){
    if(!bt) return;
    if(leftBT(bt)) destroyBT(leftBT(bt));
    if(right(bt)) destroyBT(rightBT(bt));
    free(bt);
}
//8)
int heightBT(bintree *bt){
    if (!bt) return 0;
    int r,l;
    l = 1 + heightBT(leftBT(bt));
    r = 1 + heightBT(rightBT(bt));
    if(r > l) return r;
    return l;
}
//9)
List *preOrderTraversalBT(bintree *bt){
    List *list;
    Node *ptr;
    Info *info;
    if(!bt) return NULL;
    list = createList();
    if(!list) return NULL;
    info = createInfo(rootBT(bt)->info);
    if(!info) {
        free(list);
        return NULL;
    }
    insertLast(list,info);
    auxPreOrderTraversalBT(leftBT(bt), list);
    auxPreOrderTraversalBT(rightBT(bt), list);
    return list;
}

void auxPreOrderTraversalBT(bintree *bt, List *list){
    if(!bt || !list) return;
    Info *info;
    info = createInfo(rootBT(bt)->info);
    if(!info) return NULL;
    insertLast(list,info);
    auxPreOrderTraversalBT(leftBT(bt), list);
    auxPreOrderTraversalBT(rightBT(bt), list);
}
//10)
List *inOrderTraversalBT(bintree *bt){
    if(!bt) return NULL;
    List *list;
    Info *info;
    list = createList();
    if(!list) return NULL;
    info = createInfo(rootBT(bt)->info);
    if(!info) {
        free(list);
        return NULL;
    }
    auxInOrderTraversalBT(leftBT(bt), list);
    insertLast(list, info);
    auxInOrderTraversalBT(rightBT(bt), list);
    return list;
}

void auxInOrderTraversalBT(bintree *bt, List *list){
    if(!bt || !list) return NULL;
    Info *info;
    info = createInfo(rootBT(bt)->info);
    if(!info) return NULL;
    auxInOrderTraversalBT(leftBT(bt), list);
    insertLast(list, info);
    auxInOrderTraversalBT(rightBT(bt), list);
}

//11)
List *postOrderTraversalBT(bintree *bt){
    if(!bt) return NULL;
    List *list;
    list = createList();
    if(!list) return NULL;
    Info *info;
    info = createInfo(rootBT(bt));
    if(!info)
    {
        free(list);
        return NULL;
    }
    auxPostOrderTraversalBT(leftBT(bt), list);
    auxPostOrderTraversalBT(rightBT(bt), list);
    insertLast(list, info);
    return list;
}

void auxPostOrderTraversalBT(bintree *bt, List *list){
    if(!bt || !list) return NULL;
    Info *info;
    info = createInfo(rootBT(bt));
    if(!info) return NULL;
    auxPostOrderTraversalBT(leftBT(bt), list);
    auxPostOrderTraversalBT(rightBT(bt), list);
    insertLast(list, info);
}

//12)
List *levelOrderTraversalBT(bintree *bt){
    if(!bt) return NULL;
    List *list;
    List *traverse;
    traverse = createList();
    list = createList();
    Node *ptr;
    if(!list || !traverse) return NULL;
    if(!info){
        free(list);
        free(traverse);
        return NULL;
    }
    insertLast(traverse, createInfo(rootBT(bt));
    while(traverse->first){
        insertLast(list,removeFirst(traverse));
        if(leftBT(bt)){
            insertLast(traverse,createInfo(root(leftBT(bt))->info));
        }
        if(rightBT(bt)){
            insertLast(traverse,createInfo(root(rightBT(bt))->info));
        }

    }
    deleteList(traverse);
    return list;
}

//13)
bintree *treeFromInOrderPreOrderBT(List *preOrder, List *inOrder){
    if(!preOrder || !inOrder) return NULL;
    bintree *bt = createBT(createInfo(preOrder->first->info));
    if(!bt) return NULL;
    auxTreeFromInOrderPreOrderBT(bt, )
}
//outros

Info *createInfo(int info){
    Info *inf;
    inf = (Info *)malloc(sizeof(Info));
    if(!inf) return NULL;
    inf->info = info;
    return inf;
}

void insertLeftBT(bintree *bt, Info *info){
    if(!bt || !info || bt->left) return;
    bintree *bt1 = createBT(info);
    bt->left = bt1;
}

void insertRightBT(bintree *bt, Info *info){
    if(!bt || !info || bt->right) return;
    bintree *bt1 = createBT(info);
    bt->right = bt1;
}
