#include "listad.c"

// cd "/Users/onatalia86/Documents/ED1/Lista/Exercicio3/" && gcc -lstdc++ mainListad.c -o mainListad && "/Users/onatalia86/Documents/ED1/Lista/Exercicio3/"mainListad
int main(){
    DList *dlist, *dlist1, *dlist2;
    Info *info;
    int quant = 5,i=0, value;
    dlist = createDList();
    dlist1 = createDList();
    if(dlist && dlist1){
        while(i<quant-2){
            info = createInfo();
            insertLast(dlist, info);
            // imprimeDList(dlist);
            i++;
        }
        i=0;
        while(i<quant){
            info = createInfo();
            insertLast(dlist1, info);
            // imprimeDList(dlist);
            i++;
        }
        imprimeDList(dlist);
        imprimeDList(dlist1);
        dlist2 = createDList();
        intercalaLista(dlist, dlist1, dlist2);
        imprimeDList(dlist2);
        // info = createInfo();
        // insertLast(dlist, info);
        // imprimeDList(dlist);
        // value = deleteLast(dlist);
        // printf("Delete last:  %d \n",value);
        // value = deleteFirst(dlist);
        // printf("Delete first:  %d \n",value);
        // imprimeDList(dlist);
        // info = createInfo();
        // insertPos(dlist, info, 4);
        // imprimeDList(dlist);
        // value = deletePos(dlist,4);
        // printf("Delete pos 4:  %d \n",value);
        // imprimeDList(dlist);
    }else{
        printf("\nA lista não pôde ser criada\n");
    }

    return 0;
}