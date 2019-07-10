#include <stdio.h>
#include "pilha.c"

// cd "/Users/onatalia86/Documents/ED1/Lista/Exercicio1/" && gcc -lstdc++  mainPilh&& "/Users/onatalia86/Documents/ED1/Lista/Exercicio1/"mainPilha
int main(){
    Stack *stack = createStack();
    int quant = 5, i=0, info, altur, top;
    while(i<quant){
        Info *info = createInfo();
        salvarInfo(info);
        empilhar(stack,info);
        imprimeStack(stack);
        altur = altura(stack);
        printf("\nAltura: %d\n",altur);
        top = topo(stack);
        printf("\nTopo: %d\n",top);
        i++;
    }
    
    while(i>=0){
        info = desempilhar(stack);
        printf("\nElemento desempilhado: %d\n",info);
        imprimeStack(stack);
        altur = altura(stack);
        printf("\nAltura: %d\n",altur);
        top = topo(stack);
        printf("\nTopo: %d\n",top);
        i--;
    }

    return 0;
}