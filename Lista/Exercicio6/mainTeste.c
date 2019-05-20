#include "listad.c"

// cd "/Users/onatalia86/Documents/ED1/Lista/Exercicio6/" && gcc -lstdc++ mainTeste.c -o mainTeste && "/Users/onatalia86/Documents/ED1/Lista/Exercicio6/"mainTeste

int main(){
    Lista *lista;
    lista = createList();
    insertFirst(lista, 3);
    insertFirst(lista, 2);
    insertFirst(lista, 1);
    insertLast(lista, 4);
    insertLast(lista, 5);
    insertLast(lista, 6);
    printList(lista);
    removeInfo(lista,1);
    printList(lista);
    removeInfo(lista,2);
    printList(lista);
    removeInfo(lista,3);
    printList(lista);
    removeInfo(lista,4);
    printList(lista);
    removeInfo(lista,5);
    printList(lista);
    removeInfo(lista,6);
    printList(lista);
    return 0;
}