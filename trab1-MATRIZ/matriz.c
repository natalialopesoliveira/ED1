#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"

Celula *iniciaEsparsa(int linha, int coluna){
	Celula *temp;
	temp = (Celula*) malloc (sizeof(Celula));
	val(temp) = 0;
	lin(temp) = -1*linha;
	col(temp) = -1*coluna;
	dir(temp) = NULL;
	aba(temp) = NULL;
	return temp;
}
Celula *alocaCelula (int linha, int coluna, double valor){
	Celula *temp;
	temp = (Celula*) malloc (sizeof(Celula));
	val(temp) = valor;
	lin(temp) = linha;
	col(temp) = coluna;
	dir(temp) = NULL;
	aba(temp) = NULL;
	return temp;
}
void imprimeMatriz(Celula *matriz){
	Celula *aux,*temp;
	int linha = -1*lin(matriz);
	int coluna = -1*col(matriz);
	int i,j;
	printf("\nInfo:[%d,%d]\n",linha, coluna);
	aux = aba(matriz);

	for(i=1;i<=linha;i++){
		if(aux == NULL || lin(aux)!=i){
			printf("0 \t0 \t0 \t0\n");
		}else{
			temp = dir(aux);
			for(j=1;j<=coluna;j++){
				if(temp!=NULL && col(temp)==j){
					printf("%.2lf\t",val(temp));
					temp = dir(temp);
				}else{
					printf("0\t");
				}

			}
			printf("\n");
			aux = aba(aux);
		}


	}
}
void apagaMatriz(Celula **matriz){
	Celula *aux,*temp;
	aux = matriz[0];
	if(aba(aux)!=NULL){
		apagaMatriz(&aba(aux));
	}
	temp = aux;
	while((temp)!=NULL){
		temp = dir(temp);
//		printf("Apaguei: %d %d %f\n",lin(aux),col(aux),val(aux));
		free(aux);
		aux = temp;
	}
}
Celula *LeMatriz(){
	FILE *file;

	Celula *aux,*anterior,*celula;
	Celula *matriz;

	int ncel,i;
	int linha, coluna;
	double valor;
	char  arquivo[50];


	fflush(stdin);
	// printf("Digite o nome do arquivo.\n");
	// gets(arquivo);
	file = fopen("./teste.txt","r");

	if(file != NULL){
		fscanf(file," %d",&linha);
		fscanf(file,",%d",&coluna);
	} else{
		printf("ai\n");
	}

	// system("cls");

	matriz = iniciaEsparsa(linha, coluna); //celula -1 -1


	while(fscanf(file,"%d %d %lf",&linha,&coluna,&valor) == 3){


		val(matriz)++;
		aux = matriz;
		anterior = aux;
		//-----------------------LINHA--------------------------
		//procura nas linhas
		while(lin(aux)<linha){
			anterior = aux;
			aux = aba(aux);
			if(aux == NULL){
				break;
			}
 		}
 		celula = alocaCelula(linha,coluna,valor);
		if(aux!= NULL && lin(aux)==linha){
			//existe tal linha
			while(dir(aux)!= NULL && col(aux)<coluna){
				//anda ate a coluna correta
				aux = dir(aux);
			}
			//celula = alocaCelula(linha,coluna,valor);
			dir(celula) = dir(aux);
			dir(aux) = celula;
		}else{
			//nao existe a linha selecionada

			aux = alocaCelula(linha,-1,-1);
			aba(aux) = aba(anterior);
			aba(anterior) = aux;

			//celula = alocaCelula(linha,coluna,valor);
			dir(aux) = celula;
		}
		//-----------------------COLUNA--------------------------
		aux = matriz;
		anterior = aux;
		while(col(aux)<coluna){
			anterior = aux;
			aux = dir(aux);
			if(aux == NULL){
				break;
			}
 		}
		if(aux!= NULL && col(aux)==coluna){
			//existe tal coluna
			while(aba(aux)!= NULL && lin(aux)<linha){
				//anda ate a linha correta
				aux = aba(aux);
			}
			//celula = alocaCelula(linha,coluna,valor);
			aba(celula) = aba(aux);
			aba(aux) = celula;
		}else{
			//nao existe a coluna selecionada

			aux = alocaCelula(-1,coluna,-1);
			dir(aux) = dir(anterior);
			dir(anterior) = aux;

			aba(aux) = celula;
		}
	}
	fclose(file);

	return matriz;
}

void somaMatriz(Celula *matrizA,Celula *matrizB,Celula **matrizC){
	int i,j;
	Celula *auxA,*auxB,*auxC,*temp,*tempC,*rest;
	if((lin(matrizA)!=lin(matrizB) || col(matrizA)!=col(matrizB))&& !(lin(matrizA)==-1 && lin(matrizB)==-1)){
		printf("Nao eh possivel somar tais matrizes.\nDimensoes diferentes.\n");
		exit(1);
	}
	int linha = -1*lin(matrizA);
	int coluna = -1*col(matrizA);
	matrizC  = (Celula**)malloc(sizeof(Celula*));

//	if(val(matrizA)>=val(matrizB)){
//		matrizC[0] = (Celula*)malloc(val(matrizA)*sizeof(Celula));
//		memcpy(matrizC[0],matrizA,val(matrizA)*sizeof(Celula));
//		rest = matrizB;
//	}else{
//		matrizC[0] = (Celula*)malloc(val(matrizB)*sizeof(Celula));
//		memcpy(matrizC[0],matrizB,val(matrizB)*sizeof(Celula));
//		rest = matrizA;
//	}

	if(val(matrizA)>=val(matrizB)){
		rest = matrizA;
		matrizA = matrizB;
	}else{
		rest = matrizB;
	}
	matrizC[0] = (Celula*)malloc(val(rest)*sizeof(Celula));
	memcpy(matrizC[0],rest,val(rest)*sizeof(Celula));
	rest = matrizA;


	temp = aba(rest);
	auxC = aba(matrizC[0]);
	for(i=1;i<=linha && temp!=NULL;i++){
//		if(lin(temp)==i){
//			if(lin(auxC)==i){
//
//			}
//			aba(auxC) = alocaCelula(i,-1,-1);
//			auxC = aba(auxC);
//			tempC = auxC;
//
//			temp = dir(auxA);
//			while(temp!=NULL){
//				dir(tempC)=alocaCelula(i,col(temp),val(temp));
//				tempC = dir(tempC);
//				temp = dir(temp);
//			}
//			temp = dir(auxB);
//			tempC = auxC;
//			while(temp!=NULL){
//				if(dir(tempC) != NULL);
//			}
//		}
		for(j=1;j<=coluna;j++){

		}
	}
	imprimeMatriz(matrizA);
	imprimeMatriz(matrizC[0]);
}
void multiplicaMatriz (Celula *matrizA, Celula *matrizB, Celula **matrizC){
// 	int i,j;
// 	double valor;
// 	Celula *auxA,*auxB,*auxC,*tempA,*tempC,*rest;
// 	if (!matrizA || !matrizB || lin(matrizA) == 0 || col(matrizA) == 0 || lin(matrizB) == 0 || col(matrizB) == 0) return;
// 	if(col(matrizA)!=lin(matrizB)) return;
// 	int linha = -1*lin(matrizB);
// 	int coluna = -1*col(matrizA);
// 	matrizC = (Celula**)malloc(sizeof(Celula*));
// 	if(!matrizC) return;
// 	auxA=aba(matrizA);
// 	auxB=dir(matrizB);
// 	while(auxA && auxB){
// 		valor = 0;
// 		tempA=dir(auxA);
// 		for(tempB = dir(auxB); tempB; tempB = dir(tempB)){
// 			for(i=1; i<=col(matrizA); i++){
// 				if(tempA && tempB){
// 					if(col(tempA) == i && lin(tempB) == i){
// 						valor += val(tempA)*val(tempB);
// 						tempA = dir(tempA);
// 						tempB = dir(tempB);
// 					}else if((col(tempA) == i && lin(tempB) != i)){
// 						tempA = dir(tempA);
// 					}else if(col(tempA) != i && lin(tempB) == i){
// 						tempB = dir(tempB);
// 					}
// 				}
// 			}
// 			if(valor != 0) auxC = alocaCelula(lin(auxA),col(tempB),valor);
// 		}
//
//
//
// 		auxA = aba(auxA);
// 	}
}
