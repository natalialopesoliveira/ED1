#include <bool.h>

typedef struct node{
    int num;
    int coeff;
    struct node *next;
};

struct node *add_poly(struct node *start1, struct node *start2, struct node *start3);

struct node *sub_poly(struct node *start1, struct node *start2, struct node *start3);

struct node *mult_poly(struct node *start1, struct node *start2, struct node *start3);

struct node *div_poly(struct node *start1, struct node *start2, struct node *start3);

struct node *add_poly(struct node *start1, struct node *start2, struct node *start3){
    
}
void add(struct node *start1, struct node *start2, struct node *start3){
    if (!criaNode(start3)) exit(1);

    if(start1->coeff > start2->coeff){
        if(start1->next!=NULL)
            add(start1->next,start2,start3->next);
        start3->num = start1->num;
    }else if(start1->coeff < start2->coeff){
        if(start2->next!=NULL)
            add(start1,start2->next,start3);
    }
    else if(start1->coeff==start2->coeff){
        start3->num = start1->num + start2->num;
    }
}
bool criaNode(struct node *no){
    no=(struct node*)malloc(sizeof(struct node));
    if(no!=NULL) return true;
    return false;
}
struct node *add_poly(struct node *start1, struct node *start2, struct node *start3){
    struct node aux1, aux2, aux3 = start3;
    int coeff;
    if(!start1 || !start2) return NULL;
    start3=(struct node*)malloc(sizeof(struct node));
    if(!start3) return NULL;
    if(start1->coeff >= start2->coeff) coeff = start1->coeff;
    else coeff = start2->coeff;
    for(; coeff >= 0; coeff--){
        for(aux1 = start1;aux1->coeff != coeff && aux1 != NULL;aux1 = aux1->next);
        for(aux2 = start2;aux2->coeff != coeff && aux2 != NULL;aux2 = aux2->next);
        if(aux1 || aux2){
            aux3->coeff = coeff;
            if(aux1 && aux2){
                aux3->num = aux1->num + aux2->num;
            } else if(aux1 && !aux2){
                aux3->num = aux1->num;
            } else if(!aux1 && aux2){
                aux3->num = aux2->num;
            }
            aux3->next = (struct node*)malloc(sizeof(struct node));
            if(!aux3->next) return NULL;
            else aux3 = aux3->next;
        }
    }
    return start3;
}
struct node *add_poly(struct node *start1, struct node *start2, struct node *start3){
    struct node *aux3;
    int coeff;
    if(!start1 || !start2) return NULL;
    start3=(struct node*)malloc(sizeof(struct node));
    if(!start3) return NULL;
    aux3 = start3;
    if(start1->coeff >= start2->coeff){
        for(;start1 != NULL;start1=start1->next){
            if(start1->coeff == start2->coeff){
                aux3->num = start1->num + start2->num;
                start2 = start2->next;
            } else {
                aux3->num = start1->num;
            }
            aux->next = (struct node*)malloc(sizeof(struct node));
            if(aux->next) aux = aux->next;
            else return NULL;
        }
    } else {
        for(;start2 != NULL;start2=start2->next){
            if(start1->coeff == start2->coeff){
                aux3->num = start1->num + start2->num;
                start1 = start1->next;
            } else {
                aux3->num = start2->num;
            }
        }
        aux->next = (struct node*)malloc(sizeof(struct node));
        if(aux->next) aux = aux->next;
        else return NULL;
    }
    
    return start3;
}

struct node *sub_poly(struct node *start1, struct node *start2, struct node *start3){
   struct node aux1, aux2, aux3 = start3;
    int coeff;
    if(!start1 || !start2 || !start3) return NULL;
    if(start1->coeff >= start2->coeff) coeff = start1->coeff;
    else coeff = start2->coeff;
    for(coeff; coeff >= 0; coeff--){
        for(aux1 = start1;aux1->coeff != coeff, aux1;aux1 = aux1->next);
        for(aux2 = start2;aux2->coeff != coeff, aux2;aux2 = aux2->next);
        if(aux1 || aux2){
            aux3->coeff = coeff;
            if(aux1 && aux2){
                aux3->num = aux1->num - aux2->num;
            } else if(aux1 && !aux2){
                aux3->num = aux1->num;
            } else if(!aux1 && aux2){
                aux3->num = -aux2->num;
            }
            aux3->next = (struct node*)malloc(sizeof(struct node));
            if(!aux3->next) return NULL;
            else aux3 = aux3->next;
        }
    }
    return start3;
}

struct node *mult_poly(struct node *start1, struct node *start2, struct node *start3){
   
    
}

struct node *div_poly(struct node *start1, struct node *start2, struct node *start3){
   
    
}