#include <stdio.h>
#include <stdlib.h>
#include "matrizesparsa.h"

Celula *criaCelula(int linha, int coluna, double valor){
    Celula *ptr;
    if((ptr = (Celula*)malloc(sizeof(Celula)))){
        ptr->direita = NULL;
        ptr->abaixo = NULL;
        ptr->linha = linha;
        ptr->coluna = coluna;
        ptr->valor = valor;
        return ptr;
    }
    return NULL;
}

void ImprimeMatriz(Celula *A){
    if(!A || !A->direita || !A->abaixo) return;
    Celula *aux, *aux1;

    //calcular o número de linhas e de colunas da matriz
    int linhas, colunas, i, j;
    linhas = A->linha;
    colunas = A->coluna;
    //navegar pelas linhas para conseguir imprimir a matriz
    aux = A->abaixo;
    for(i=1; i<=linhas; i++){
        //linha nao existe
        if(aux && aux->linha != i){
            printf("\n");
            for(j=1; j<=colunas; j++){
                printf("0\t");
            }
        }
        //linha existe
        else {
            aux1 = aux->direita;
            printf("\n");
            for(j=1; j<=colunas; j++){
                //se existe elemento naquela coluna
                if(aux1 && aux1->coluna == j){
                    printf("%.2lf\t", aux1->valor);
                    aux1 = aux1->direita;
                }
                //se nao
                else{
                    printf("0\t");
                }
            }
        }
    }

}

void LeMatriz(Celula *A){
    FILE *file;
    int linha, coluna;
    double valor;
    file = fopen("./teste.txt","r");
    if(file != NULL){
        fscanf(file,"%d",&linha);
		fscanf(file,",%d",&coluna);
	} else{
		printf("Não foi possível abrir o arquivo.\n");
	}
    //para reservar o valor do número de linhas e colunas originais da matriz, já que como as ultimas colunas podem apenas conter zeros(assim como as ultimas linhas), não é possível obter o valor depois
    A->linha = linha;
    A->coluna = coluna;

    //salvando elemento por elemento
    while(fscanf(file,"%d %d %lf",&linha,&coluna,&valor) == 3){
        insere(linha, coluna, valor, A);
    }

}

void insere(int i, int j, double v, Celula *A){
    if(!A) return;
    Celula *anterior = NULL, *atual, *ptr;
    ptr = criaCelula(i, j, v);
    if(!ptr) return;
    //PARA LINHA

    for(atual = A->abaixo; atual && atual->linha<i; anterior = atual, atual = atual->abaixo);
    // if(atual) printf("\n\n\natual: %d \n\n\n",atual->linha);


    //achou a linha
    if(atual && atual->linha == i){

        //procura a coluna
        for(atual = A->direita; atual && atual->coluna<j; anterior = atual, atual = atual->direita);
        //a célula a ser adicionada será a última da linha e depois da anterior
        if(!atual){
            anterior->direita = ptr;
        }
        //a célula a ser adicionada será entre a anterior e a atual
        else{
            anterior->direita = ptr;
            ptr->direita = atual;
        }
    }

    //se não existir a linha
    else{
        Celula *linha = criaCelula(i, -1, 0);
        linha->direita = ptr;

        //se existir celula anterior
        if(anterior) anterior->abaixo = linha;
        //se não existir, a linha criada é logo abaixo da célula cabeça
        else A->abaixo = linha;
        //se existir celula atual
        if(atual) linha->abaixo = atual;
    }


    //PARA COLUNA
    for(atual = A->direita; atual && atual->coluna<j; anterior = atual, atual = atual->direita);
    //achou a coluna
    if(atual && atual->coluna == j){
        for(atual = A->abaixo; atual && atual->linha<i; anterior = atual, atual = atual->abaixo);
        //a célula a ser adicionada será a última da coluna e depois da anterior
        if(!atual){
            anterior->abaixo = ptr;
        }
        //a célula a ser adicionada será entre a anterior e a atual
        else{
            anterior->abaixo = ptr;
            ptr->abaixo = atual;
        }

    }
    //se não existir a coluna
    else{
        Celula *coluna = criaCelula(-1, j, 0);
        coluna->abaixo = ptr;
        //se existir celula anterior
        if(anterior) anterior->direita = coluna;
        //se não existir, a coluna criada é logo ao lado da célula cabeça
        else A->direita = coluna;
        //se existir celula atual
        if(atual) coluna->direita = atual;
    }
}

void ApagaMatriz(Celula *A){
    if(!A) return;
    ApagaMatriz(A->direita);
    ApagaMatriz(A->abaixo);
    free(A);
}

// void SomaMatriz(Celula *A, Celula *B, Celula **C){
//     if(!A || !B || !A->direita || !B->direita) return;
//     Celula *aux;
//     //calcular o número de linhas e de colunas da matriz A
//     int linhasA, colunasA;
//     for(aux=A->direita; aux->direita; aux = aux->direita);
//     colunasA = aux->coluna;
//     for(aux=A->abaixo; aux->abaixo; aux = aux->abaixo);
//     linhasA = aux->linha;
//
//     //calcular o número de linhas e de colunas da matriz B
//     int linhasB, colunasB;
//     for(aux=B->direita; aux->direita; aux = aux->direita);
//     colunasB = aux->coluna;
//     for(aux=B->abaixo; aux->abaixo; aux = aux->abaixo);
//     linhasB = aux->linha;
//     //verificar se é possível fazer a soma das matrizes
//     if(linhasA != linhasB && colunasA != colunasB) return;
//
//     auxSomaMatriz(A->direita, B, C);
//     auxSomaMatriz(A, B->direita, C);
//
// }
//
// void auxSomaMatriz(Celula *A, Celula *B, Celula *C){
//     if(!A || !B) return;
//
// }
