typedef struct tnode{
    int chave;
    struct tnode *next;
    struct tnode *prev;
}Node;

typedef struct{
    int size;
    Node *first;
}DList;


//b) Busca Ordenada
int buscaOrdenada(DList *list, int chave){
    int posicaoMaior, posicaoMenor, metade, i, ordenacao;
    Node *aux;
    if(!list || list->size == 0) return -1;
    if(list->first->next){
        if (list->first->chave < list->first->next->chave) ordenacao = 1;
        else ordenacao = -1;
    }
    posicaoMenor = 1;
    posicaoMaior = list->size;
    while(posicaoMenor != posicaoMaior){
        metade = (posicaoMenor + posicaoMaior)/2;
        for(i=0, aux = list->first; i<metade; i++, aux = aux->next);
        if(aux->chave > chave){
            if(ordenacao == 1){
                posicaoMaior = metade;
            } else {
                posicaoMenor = metade;
            }
        } else if (aux->chave == chave){
            return metade;
        } else {
            if(ordenacao == 1){
                posicaoMenor = metade;
            } else {
                posicaoMaior = metade;
            }
        }
    }
    if(aux->chave != chave) return -1;
    else return posicaoMaior;
}

//c) Busca desordenada
int buscaDesordenada(DList *list, int chave){
    Node *aux;
    int i;
    if(!list || list->size == 0) return -1;
    for(i=1,aux = list->first;i<=list->size;aux=aux->next,i++){
        if(aux->chave == chave) return i;
    }
    return -1;
}

// e) Intercala lista
DList * intercalaLista(DList *list1, DList *list2){
    
    if(!list1 || !list2) return;
    Dlist *list3;
    list3 = createDList();
    if(!list3) return;
    Node *aux1, *aux2 = list2->first, aux3 =list3->first;
    //fazer até quando todas tiverem elementos em comum;
    for(aux1 = list1->first; aux1;aux1 = aux1->next){
        aux3=createNode(list3,aux1->chave);
        inserirFinal(list3,aux3);
        if(aux2){
            aux3=createNode(list3,aux2->chave);
            inserirFinal(list3,aux3);
            aux2=aux2->next;
        }
    }
    //verificar se ainda tem a list2 nao finalizada, e finalizá-la
    if(aux2){
        aux3=createNode(list3,aux2->chave);
        inserirFinal(list3,aux3);
        aux2=aux2->next;
    }
    return list3;
}

//f) Ordena lista ordenação crescente e decrescente
    void ordenacaoCrescente(Dlist *list){

    }

    void or