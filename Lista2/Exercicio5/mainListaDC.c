#include "listadc.c"

// cd "/Users/onatalia86/Documents/ED1/Lista/Exercicio5/" && gcc -lstdc++ mainListaDC.c -o mainListaDC && "/Users/onatalia86/Documents/ED1/Lista/Exercicio5/"mainListaDC
int main(){
    Node *first = NULL;
    first = createNode();
    insertLast(first);
    insertLast(first);
    insertLast(first);
    insertLast(first);
    insertLast(first);
    printDList(first);
    removeInfo(first, 2);
    return 0;
}
