#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "dlist.c"

List *decodifica(List *list);
void *inverteNos(Node *p, Node *q);
bool isVogal(char chave);
int main(){

}

List *decodifica(List *list){
    Node *aux, *aux2;
    if (!list || list->size == 0) return NULL;
    for(aux=list->first, aux2=list->first; aux, aux2; aux=aux->next){
        if(!isalpha(aux->chave) || !isVogal(aux->chave)){
            aux2 = aux;
            for(aux; ((!isVogal(aux)) || (!isalpha(aux->chave))) && aux; aux=aux->next);
            inverteNos(aux2,aux);
        }
    }
    inverteLista(List *list);
    return list;
}

void *inverteNos(Node *p, Node *q){
    Node *prev = NULL, *current, *next, *first, *last;
    if(!p || !q) return;
    first = p->prev;
    last = q->next;
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
    else return false;
}