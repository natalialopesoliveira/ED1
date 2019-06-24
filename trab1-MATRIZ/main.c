#include "matrizesparsa.c"

//para leitura de arquivo:
// cd ~/Documents/ED1/trab1-MATRIZ && gcc main.c -o main && ./main

int main(){
    Celula *A= criaCelula(-1,-1,0);
    // ImprimeMatriz(A);

    LeMatriz(A);

    printf("\nA\n");
    printf("A->linha: %d\t", A->linha);
    printf("A->coluna: %d\t", A->coluna);
    printf("A->valor: %lf\t", A->valor);
    printf("\n");



    // ImprimeMatriz(A);
    return 0;
}
