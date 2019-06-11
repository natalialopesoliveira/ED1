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

/* função que aloca memória para uma bintree, inicializando seus campos
entrada: ponteiro para o elemento de informação
saída: ponteiro para uma bintree
*/
bintree *createBintree(Info *info);

/* função que retorna o ponteiro da subárvore esquerda da bintree bt
entrada: ponteiro para a árvore bt
saída: ponteiro para a subárvore esquerda
*/
bintree *leftBintree(bintree *bt);

/* função que retorna o ponteiro da subárvore direita da bintree bt
entrada: ponteiro para a árvore bt
saída: ponteiro para a subárvore direita de bt
*/
bintree *rightBintree(bintree *bt);

/* função que retorna o elemento de informação de uma raiz bt
entrada: ponteiro para a raiz bt
saída: ponteiro para o elemento de informação
*/
Info *rootBintree(bintree *bt);

/* função que verifica se a bintree bt está vazia
entrada: ponteiro para a bintree bt
saída: 1 se vazia e 0 se não vazia
*/
int isEmptyBintree(bintree *bt);

/* função que verifica se um elemento de informação info se encontra na bintree bt
entrada: ponteiros para a bintree bt e para o elemento de informação info
saída: 1 se estiver e 0 se não
*/
int isInBintree(bintree *bt, Info *info);

/* função que apaga a bintree bt
entrada: ponteiro para a bintree bt
saída: void
*/
void destroyBintree(bintree *bt);

/* função que retorna a altura da bintree bt
entrada: ponteiro para a bintree bt
saída: inteiro representando a altura
*/
int heightBintree(bintree *bt);
#endif //__BINTREE_H__
