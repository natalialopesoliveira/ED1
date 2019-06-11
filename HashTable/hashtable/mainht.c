#include<stdio.h>

#include "hashtable.c"

#define MAXSIZEHT 11
#define MAXSIZEW 23

int main()
{
	//mudar para.. MODIFICAR TUDO
	Hash hashtable[MAXSIZEHT];
	// Node *hashtable[MAXSIZEHT];
	char word[MAXSIZEW];
	int resp,pos;

	createHT(hashtable,MAXSIZEHT);
	loadDic(hashtable);
	do
	{
		printf("\nDigite a palavra a ser buscada=");
		fflush(stdin);
		gets(word);
		pos = functionHT(word,MAXSIZEHT);
		printf("\nPalavra=%s Posicao=%d",word,pos);
		searchHT(hashtable,MAXSIZEHT,word);
		printf("\nBuscar mais? 1-SIM ou 2-NAO");
		scanf("%d",&resp);
	}while(resp==1);

	getchar();
	printHT(hashtable,MAXSIZEHT);
	return 0;

}


int loadDic(Hash hashtable[])
{
	FILE *fp=fopen("palavras.txt","a+");
    if(fp==NULL)
	    {
		  printf("\a\a\n\n\n\n\n\nERRO AO ABRIR O ARQUIVO!\n\n\n\n\n\n");
		  system("pause");
		  return -1;
		}

	int pos, x=0;
	char aux[MAXSIZEW];
	while(!feof(fp))
	{
			fgets(aux,MAXSIZEW,fp);
			strtok(aux, "\n");
			pos = functionHT(aux,MAXSIZEHT);
			printf("\nloadDic: Palavra=%s Posicao=%d",aux,pos);
			insertHT(hashtable,MAXSIZEHT,aux);
			x++;
	}
	printf("\nTAMANHO=%d",x);
	return 1;
}
