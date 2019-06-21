#include "matrizesparsa.c"

//para leitura de arquivo:
// cd ~/Documents/ED1/trab1-MATRIZ && gcc main.c -o main && ./main

int main(){
    Celula *A= criaCelula(-1,-1,0);
    LeMatriz(A);
    ImprimeMatriz(A);
    return 0;
}
