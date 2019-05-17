#ifndef __MATRIZ_H__
#define __MATRIZ_H__

typedef struct TCelula{
    struct Tcelula *direita, *abaixo;
    int linha, coluna;
    double valor;
}Celula;

typedef struct{
    Celula *direita, *abaixo;
    int linha, coluna;
}Matriz;

Celula *createCelula(int linha, int coluna, double valor);

void ImprimeMatriz( Celula *cabeca);

void LeMatriz (Matriz * A);

void ApagaMatriz(Matriz * A);

void SomaMatriz (Matriz *A, Matriz *B, Matriz *C);

void MultiplicaMatriz (Matriz *A, Matriz *B, Matriz *C);





#endif __MATRIZ_H__
