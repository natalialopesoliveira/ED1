#ifndef __BINTREE_H__
#define __BINTREE_H__

typedef struct{
    int info;
}Info;

typedef struct bt{
    struct bt *left;
    Info *info;
    struct bt *right;
}bintree;

typedef struct tnode{
    Info *info;
    struct tnode *next;
}Node;

typedef struct{
    int size;
    Node *first;
}List;



//1)
bintree *createBT(Info *info);
//2)
bintree *leftBT(bintree *bt);
//3)
bintree *rightBT(bintree *bt);
//4)
Info *rootBT(bintree *bt);
//5)
int isEmptyBT(bintree *bt);
//6)
int isInBT(bintree *bt,Info *info);
//7)
void destroyBT(bintree *bt);
//8)
int heightBT(bintree *bt);
//9)
List *preOrderTraversalBT(bintree *bt);
void auxPreOrderTraversalBT(bintree *bt, List *list)
//10)
List *inOrderTraversalBT(bintree *bt);
void auxInOrderTraversalBT(bintree *bt, List *list)
//11)
List *postOrderTraversalBT(bintree *bt);
void auxPostOrderTraversalBT(bintree *bt, List *list);
//12)
List *levelOrderTraversalBT(bintree *bt);
//13)
bintree *treeFromInOrderPreOrderBT(List *preOrder , List *inOrder);
void auxTreeFromInOrderPreOrderBT(bintree *bt,List *preOrder, List *inOrder);

Info *createInfo(int info);
void insertLeftBT(bintree *bt, Info *info);
void insertRightBT(bintree *bt, Info *info);
#endif //__BINTREE_H__
