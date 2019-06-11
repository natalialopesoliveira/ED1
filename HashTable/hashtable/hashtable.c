#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "hashtable.h"

/* funcao: void createHT(Node *hashtable,int size)
   *  acao:        funcao que cria uma hashtable
   *  entrada:     vetor representando a hashtable
   *  saida:       void
   *  suposicoes:  nenhuma
*/
//MODIFICAR
void createHT(Hash hashtable[],int sizeht)
{
	int i;
     for (i=0; i<sizeht; i++){
	 	hashtable[i].first= NULL;
	  	hashtable[i].size= 0;
	}
}

/* funcao: Node *createNodeHT(char *inf)
   *  acao:        funcao que cria um novo no e aloca
   					espaco para a string inf, armazenando uma
   					copia dela no novo no criado
   *  entrada:     elemento de informacao do novo no
   *  saida:       ponteiro para um no
   *  suposicoes:  nenhuma
*/
Node *createNodeHT(char *inf)
{
    Node *ptr;
    if((ptr=(Node *)malloc(sizeof(Node)))){
        ptr->info=(char *)malloc(sizeof(char)*(strlen(inf)+1));
        strcpy(ptr->info,inf);
        ptr->next=NULL;
        return ptr;
    }
    return NULL;
}

/* funcao: int functionHT(char *inf)
   *  acao:        funcao que calcula o valor hash de uma chave
   *  entrada:     chave
   *  saida:       inteiro representando o valor hash de uma chave
   *  suposicoes:  nenhuma
*/
int functionHT(char *inf,int sizeht)
{
	int i,sum=0;

	for(i=0;i<strlen(inf);i++)	sum+=inf[i];
	return fmod(sum,sizeht);;
}

/* funcao: void printHT(Node *hashtable[])
   *  acao:        funcao que imprime o conteudo de uma tabela hash
   *  entrada:     tabela hash
   *  saida:       void
   *  suposicoes:  nenhuma
*/
void printHT(Hash hashtable[],int sizeht)
{
	int i;
	for (i=0; i<sizeht; i++)
	{
		printf("\nIndice: %d ->", i);
		getchar();
		Node *ptr = hashtable[i].first;
		while (ptr != NULL)
		{
			printf("\t%s", ptr->info);
			ptr = ptr->next;
		}
		printf("\n\n");
		getchar();
	}

}

/* funcao: void insertHT(Node *hashtable[], char *name)
   *  acao:        funcao que insere uma chave na tabela hash
   *  entrada:     tabela hash e chave a ser inserida
   *  saida:       void
   *  suposicoes:  nenhuma
*/
void insertHT(Hash hashtable[],int sizeht, char *word)
{
	//insere no início
	//ALTERAR:
	//função que insere uma nova palavra na tabela hash. A
	//palavra deve ser inserida na lista correspondente em
	//ordem alfabética crescente sem usar busca binária. Só usar busca binária na função buscar palavra
	Node *ptr = createNodeHT(word);
	int pos = functionHT(word,sizeht);
	ptr->next = hashtable[pos].first;
	hashtable[pos].first=ptr;
	hashtable[pos].size++;
}

/* funcao: void deleteHT(Node *hashtable[], char *wd)
   *  acao:        funcao que deleta uma chave da tabela hash
   *  entrada:     tabela hash e chave a ser deletada
   *  saida:       void
   *  suposicoes:  nenhuma
*/
void deleteHT(Hash hashtable[], int sizeht, char *wd)
{
	int pos = functionHT(wd,sizeht);
	Node *ptr;
	if(hashtable[pos].first != NULL)
	{
		if(strcmp(hashtable[pos].first->info,wd) == 0)
		{
			ptr = hashtable[pos].first;
			hashtable[pos].first=hashtable[pos].first->next;
			free(ptr->info);
			free(ptr);
			hashtable[pos].size--;
		}
		else
		{
			ptr=hashtable[pos].first->next;
			Node *pptr=hashtable[pos].first;
			while(ptr!=NULL && strcmp(ptr->info,wd)!=0)
			{
				pptr=ptr;
				ptr=ptr->next;
			}
			if(ptr!=NULL)
			{
				pptr->next = ptr->next;
				free(ptr->info);
				free(ptr);
				hashtable[pos].size--;
			}
		}
	}
}

/* funcao: void searchHT(Node *hashtable[], char *wd)
   *  acao:        funcao que busca uma chave na tabela hash
   *  entrada:     tabela hash e chave a ser buscada
   *  saida:       void
   *  suposicoes:  nenhuma
*/
void searchHT(Hash hashtable[], int sizeht, char *word)
{
	//ele vai pedir para modificar retornando um node, além de fazer uma busca binária
	clock_t Ticks[2];

    int pos = functionHT(word,sizeht);
	Node *ptr=hashtable[pos].first;

	Ticks[0] = clock();
	while(ptr != NULL)
	{
		printf("\n %s ",ptr->info);
		if(strcmp(ptr->info,word)==0)
		{
			printf("\nENCONTREI! Indice: %d ->", pos);
			getchar();
			printf("\t%s", ptr->info);
			Ticks[1] = clock();
    		double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    		printf("\nTempo gasto: %g ms.", Tempo);
			return;
		}
		ptr=ptr->next;
	}
	Ticks[1] = clock();
    double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nNAO ENCONTREI!");
    printf("\nTempo gasto: %g ms.", Tempo);

}
