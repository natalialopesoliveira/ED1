#include "listaD.c"

int main(){
    List *list = createList();
    Info *info1 = createInfo('a'), *info2 = createInfo('b');
    insertLast(list, info1);
    printList(list);
    insertLast(list, info2);
    printList(list);
    insertLast(list, info1);
    printList(list);
    insertLast(list, info2);
    printList(list);
    posList(list,2);
    infoList(list);
    printList(list);
    return 0;
}
