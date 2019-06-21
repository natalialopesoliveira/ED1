#ifndef __MATRIZ_H__
#define __MATRIZ_H__

typedef struct Tcelula{
	struct Tcelula *direita, *abaixo;
	int linha, coluna;
	double valor;
}Celula;

Celula *criaCelula(int linha, int coluna, double valor); //sim
void ImprimeMatriz(Celula *A); //sim
void LeMatriz(Celula *A);

void insere(int i, int j, double v, Celula *A); //sim

void ApagaMatriz(Celula *A); //sim
void SomaMatriz(Celula *A, Celula *B, Celula **C);
void auxSomaMatriz(Celula *A, Celula *B, Celula *C);
void MultiplicaMatriz(Celula *A, Celula *B, Celula **C);



#endif // __MATRIZ_H__
