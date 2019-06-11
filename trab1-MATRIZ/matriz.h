#ifndef __MATRIZ_H__
#define __MATRIZ_H__

//para facilitar na hora de fazer os apontamentos
#define dir(X)	X->direita
#define aba(X) 	X->abaixo
#define lin(X) 	X->linha
#define col(X) 	X->coluna
#define val(X)	X->valor

typedef struct TCelula{
	struct TCelula *direita, *abaixo;
	int linha, coluna;
	double valor;
}Celula;

Celula *iniciaEsparsa(int linha, int coluna); //sim

Celula *alocaCelula (int linha, int coluna, double valor); //sim

void imprimeMatriz(Celula *matriz); //sim

void apagaMatriz(Celula **matriz); //sim

Celula *LeMatriz(); //sim

void somaMatriz(Celula *matrizA,Celula *matrizB,Celula **matrizC); //nao

void multiplicaMatriz (Celula *matrizA, Celula *matrizB, Celula **matrizC); //nao mesmo

#endif // __MATRIZ_H__
