#include <bintree.h>
#include <stdlib.h>

bintree *createBintree(Info *info){
    if (!info){
        printf("Elemento de informação inválida!");
        return NULL;
    }
    bintree *bt;
    bt = (bintree *)malloc(sizeof(bintree));
    if(!bt){
        printf("Memória insuficiente!");
        return NULL;
    }
    bt->left = NULL;
    bt->right = NULL;
    bt->info = info;
    return bt;
}

bintree *leftBintree(bintree *bt){
    if(!bt){
        printf("Árvore inexistente!");
        return NULL;
    }
    return bt->left;
}

bintree *rightBintree(bintree *bt){
    if(!bt){
        printf("Árvore inexistente!");
        return NULL;
    }
    return bt->right;
}

Info *rootBintree(bintree *bt){
    if(!bt){
        printf("Árvore inexistente!");
        return NULL;
    }
    return bt->info;
}

int isEmptyBintree(bintree *bt){
    if(!bt){
        printf("Árvore vazia/inexistente!");
        return 1;
    }
    return 0;
}

int isInBintree(bintree *bt, Info *info){
    if(!bt){
        printf("Árvore vazia/inexistente!");
        return 0;
    }
    if (!info){
        printf("Elemento de informação inválida!");
        return 0;
    }
    if(rootBintree(bt)->info == info->info) return 1;
    else{
        return (isInBintree(leftBintree(bt), info) || isInBintree(rightBintree(bt), info));
    }
}

void destroyBintree(bintree *bt){
    if(!bt) return;
    destroyBintree(leftBintree(bt));
    destroyBintree(rightBintree(bt));
    free(rootBintree(bt));
    free(bt);
    return;
}

int heightBintree(bintree *bt){
    if(!bt) return 0;
    int r, l;
    l = 1 + heightBintree(leftBintree(bt));
    r = 1 + heightBintree(rightBintree(bt));
    if(r>l) return r;
    else return l;
}
