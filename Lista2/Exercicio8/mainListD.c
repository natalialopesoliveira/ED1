#include "listaD.c"

int main(){
    List *list = createList(), *list2;
    Info *info1 = createInfo('g');
    Info *info2 = createInfo('f'); Info *info3 = createInfo('e');
    Info *info4 = createInfo('d'); Info *info5 = createInfo('c');
    Info *info6 = createInfo('b'); Info *info7 = createInfo('a');

    insertLast(list, info1);
    insertLast(list, info2);
    insertLast(list, info3);
    insertLast(list, info4);
    insertLast(list, info5);
    insertLast(list, info6);
    insertLast(list, info7);
    printList(list);
    list2 = ordenaList(list);
    if(!list2) printf("lista vazia");
    else printList(list2);

    return 0;
}
