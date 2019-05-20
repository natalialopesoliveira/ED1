#include <stdio.h>
#include "fila.c"

//cd "/Users/onatalia86/Documents/ED1/Lista/Exercicio2/" && gcc -lstdc++ mainFila.c -o mainFila && "/Users/onatalia86/Documents/ED1/Lista/Exercicio2/"mainFila

int main(){
    Queue *queue;
    Info *info;
    int quant=5,i=0;
    queue = createQueue();
    if(queue){
        while(i<quant){
            info = createInfo();
            enfileirar(queue, info);
            imprimeQueue(queue);
            i++;
        }
        while(i>0){
            printf("\nElemento desempilhado: %d\n",desenfileirar(queue));
            imprimeQueue(queue);
            i--;
        }
    } 
    return 0;
}