#ifndef HTH
#define HTH
#define MAXLEN 11

typedef struct tnode{

	char *info;
	struct tnode *next;

}Node;

/* funcao: void createHT(Node *hashtable,int size)
   *  acao:        funcao que cria uma hashtable
   *  entrada:     vetor representando a hashtable
   *  saida:       void
   *  suposicoes:  nenhuma
*/
void createHT(Node *hashtable[],int sizeht);

/* funcao: Node *createNodeHT(char *inf)
   *  acao:        funcao que cria um novo no e aloca
   					espaco para a string inf, armazenando uma
   					copia dela no novo no criado
   *  entrada:     elemento de informacao do novo no
   *  saida:       ponteiro para um no
   *  suposicoes:  nenhuma
*/
Node *createNodeHT(char *inf);

/* funcao: int functionHT(char *inf)
   *  acao:        funcao que calcula o valor hash de uma chave
   *  entrada:     chave
   *  saida:       inteiro representando o valor hash de uma chave
   *  suposicoes:  nenhuma
*/
int functionHT(char *inf,int sizeht);

/* funcao: void printHT(Node *hashtable[])
   *  acao:        funcao que imprime o conteudo de uma tabela hash
   *  entrada:     tabela hash
   *  saida:       void
   *  suposicoes:  nenhuma
*/
void printHT(Node *hashtable[],int sizeht);

/* funcao: void insertHT(Node *hashtable[], char *name)
   *  acao:        funcao que insere uma chave na tabela hash
   *  entrada:     tabela hash e chave a ser inserida
   *  saida:       void
   *  suposicoes:  nenhuma
*/
void insertHT(Node *hashtable[],int sizeht, char *name);

/* funcao: void deleteHT(Node *hashtable[], char *wd)
   *  acao:        funcao que deleta uma chave da tabela hash
   *  entrada:     tabela hash e chave a ser deletada
   *  saida:       void
   *  suposicoes:  nenhuma
*/
void deleteHT(Node *hashtable[], int sizeht, char *wd);

/* funcao: void searchHT(Node *hashtable[], char *wd)
   *  acao:        funcao que busca uma chave na tabela hash
   *  entrada:     tabela hash e chave a ser buscada
   *  saida:       void
   *  suposicoes:  nenhuma
*/
void searchHT(Node *hashtable[], int sizeht, char *wd);



#endif // HTH
