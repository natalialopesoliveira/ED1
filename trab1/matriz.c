#include <stdlib.h>
#include <stdbool.h>
#include "matriz.h"

Celula *createCelula(int linha, int coluna, double valor){
    Celula *celula;
    celula = (Celula *)malloc(sizeof(Celula));
    if(!celula) return NULL;
    celula->linha = linha;
    celula->coluna = coluna;
    celula->valor = valor;
    celula->direita = NULL:
    celula->abaixo = NULL;
    return celula;
}
