#include <stdlib.h>
#include <stdio.h>
#include "bintree.h"

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
Info * rootBT(bintree *bt){
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
List *preOrderTraversalBT(bintree *bt)


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
