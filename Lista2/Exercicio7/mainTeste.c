#include "listaC.c"

// cd "/Users/onatalia86/Documents/ED1/Lista2/Exercicio7/" && gcc -lstdc++ mainTeste.c -o mainTeste && "/Users/onatalia86/Documents/ED1/Lista2/Exercicio7/"mainTeste
int main(){
    Node *inicio, *ultimo;
    inicio = NULL;
    ultimo = NULL;

    inicio = createNode(1);
    ultimo = inicio;
    printList(inicio);
    insertLast(inicio, ultimo, 2);
    insertLast(inicio, ultimo, 3);
    insertLast(inicio, ultimo, 4);
    insertLast(inicio, ultimo, 5);

    // Node *a,*b,*c,*d;
    //
    // a = createNode(1);
    //
    // b = createNode(2);
    //
    // c = createNode(3);
    //
    // d = createNode(4);
    //
    // a->prox = b;
    // b->prox = c;
    // c->prox = d;
    // d->prox = a;
    // inicio = a;
    // ultimo = d;
    // printList(inicio);
    // printf("\n" );
    //
    // insertLast(inicio,ultimo,5);
    //
    printList(inicio);

    return 0;
}
