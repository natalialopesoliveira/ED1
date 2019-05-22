#include "listadc.c"

int main(){
    Node *first = NULL;
    insertLast(&first);

    printDList(first);
    removeInfo(&first,1);
    printDList(first);

    return 0;
}
