#include "list.c"

// cd "/Users/onatalia86/Documents/ED1/Lista2/Exercicio8/" && gcc -lstdc++ mainList.c -o mainList && "/Users/onatalia86/Documents/ED1/Lista/Exercicio8/"mainList
int main(){
    List *list = createList();
    Info *info3, *info2, *info = createInfo('a');
    insertLast(list,info);
    printList(list);
    info2 = createInfo('b');
    insertLast(list,info2);
    printList(list);
    insertLast(list,info);
    printList(list);
    insertLast(list,info);
    printList(list);
    insertLast(list,info);
    printList(list);
    posList(list, 2);
    info3 = infoList(list);
    printList(list);
    insertLast(list,info3);
    printList(list);
    return 0;
}
