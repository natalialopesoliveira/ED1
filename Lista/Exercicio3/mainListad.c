#include "listad.c"

// cd "/Users/onatalia86/Documents/ED1/Lista/Exercicio3/" && gcc -lstdc++ mainListad.c -o mainListad && "/Users/onatalia86/Documents/ED1/Lista/Exercicio3/"mainListad
int main(){
    DList *dlist;
    Info *info;
    int quant = 5,i=0, value;
    dlist = createDList();
    if(dlist){
        while(i<quant){
            info = createInfo();
            insertFist(dlist, info);
            imprimeDList(dlist);
            i++;
        }
        info = createInfo();
        insertLast(dlist, info);
        imprimeDList(dlist);
        value = deleteLast(dlist);
        printf("Delete last:  %d \n",value);
        imprimeDList(dlist);
        info = createInfo();
        insertPos(dlist, info, 5);
        imprimeDList(dlist);
    }else{
        printf("\nA lista não pôde ser criada\n");
    }

    return 0;
}