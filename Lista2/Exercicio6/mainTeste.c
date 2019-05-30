#include "listad.c"

int main(){
    Lista *lista, *lista2;
    lista = createList();
    lista2 = createList();
    insertFirst(lista, 3);
    insertFirst(lista, 2);
    insertFirst(lista, 1);
    insertLast(lista, 4);
    insertLast(lista, 5);
    insertLast(lista, 6);
    printList(lista);
    insertFirst(lista2, 10);
    insertFirst(lista2, 9);
    insertFirst(lista2, 8);
    insertLast(lista2, 11);
    insertLast(lista2, 12);
    insertLast(lista2, 13);
    printList(lista2);
    // removeInfo(lista,1);
    // printList(lista);
    // removeInfo(lista,2);
    // printList(lista);
    // removeInfo(lista,3);
    // printList(lista);
    // removeInfo(lista,4);
    // printList(lista);
    // removeInfo(lista,5);
    // printList(lista);
    // removeInfo(lista,6);
    // printList(lista);
    // insertPos(lista,2,7);
    // printList(lista);
    exchangeInfo(lista, lista2, 2, 12);
    printList(lista);
    printList(lista2);

    return 0;
}
