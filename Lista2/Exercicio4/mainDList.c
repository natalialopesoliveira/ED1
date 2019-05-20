#include "listad.c"

// cd "/Users/onatalia86/Documents/ED1/Lista/Exercicio4/" && gcc -lstdc++ mainDList.c -o mainDList && "/Users/onatalia86/Documents/ED1/Lista/Exercicio4/"mainDList

int main(){
    DList *dlist1, *dlist2;
    Info *info;

    dlist1 = createDList();
    dlist2 = createDList();
    if(dlist1 && dlist2){
        
    } else {
        printf("\nNão foi possível criar as listas.");
    }
}