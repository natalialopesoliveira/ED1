#include "listadc.c"

int main(){
    Node *first = NULL;
    insertLast(&first);
    insertLast(&first);
    insertLast(&first);
    insertLast(&first);
    insertLast(&first);
    insertLast(&first);
    insertLast(&first);
    insertLast(&first);

    printDList(first);
    removeInfo(&first,5);
    printDList(first);

    return 0;
}
