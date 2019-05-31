#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "dlist.c"

void decodifica(List *list);
void inverteNos(Node *p, Node *q);
bool isVogal(char chave);

int main(){
    char frase[100];
    int i;
    List *list = createList();
    printf("\nInsira a mensagem a ser decodificada: ");
    gets(frase);
    for(i =0; i<strlen(frase); i++){
        insertLast(list, frase[i]);
    }
    printList(list);
    decodifica(list);
    // printList(list)
    return 0;
}

void decodifica(List *list){
    Node *aux, *aux2;
    if (!list || list->size == 0) return;
    for(aux=list->first; aux; aux=aux->next){
        if(!isalpha(aux->chave) || !isVogal(aux->chave)){
            *aux2 = *aux;

            for(aux; ((!isVogal(aux->chave)) || (!isalpha(aux->chave))) && aux->next; aux=aux->next);
            inverteNos(aux2,aux);
            printf("\n oieoie");
        }
    }
    // revertList(list);
}

void inverteNos(Node *p, Node *q){
    Node *prev = NULL, *current, *next, *first, *last;
    if(!p || !q) return;
    if(p->prev) first = p->prev;
    else first = NULL;
    // first = p->prev;
    if(q->next) last = q->next;
    else last = NULL;
    current = p;
    while(current != last){
        next = current->next;
        current->prev = next;
        current->next = prev;
        prev = current;
        current = next;
    }
    q->prev = first;
    p->next = last;
}

bool isVogal (char chave){
    if(chave == 'A' || chave == 'E' || chave == 'I' || chave == 'O' || chave == 'U') return true;
    return false;
}
