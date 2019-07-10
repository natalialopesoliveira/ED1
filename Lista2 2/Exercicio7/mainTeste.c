#include "listaC.c"

// cd "/Users/onatalia86/Documents/ED1/Lista2/Exercicio7/" && gcc -lstdc++ mainTeste.c -o mainTeste && "/Users/onatalia86/Documents/ED1/Lista2/Exercicio7/"mainTeste
int main(){
    Node *inicio, *ultimo;
    int i;
    inicio = NULL;
    ultimo = NULL;

    inicio = createNode(1);
    ultimo = inicio;
    // printList(inicio);
    insertFirst(&inicio, &ultimo, 0);
    insertLast(&inicio, &ultimo, 2);
    insertLast(&inicio, &ultimo, 3);
    insertFirst(&inicio, &ultimo, -1);
    insertLast(&inicio, &ultimo, 4);
    insertFirst(&inicio, &ultimo, -2);
    insertLast(&inicio, &ultimo, 5);
    insertFirst(&inicio, &ultimo, -3);
    printList(inicio);

    removeInfo(&inicio, &ultimo, 4);
    printList(inicio);


    return 0;
}
