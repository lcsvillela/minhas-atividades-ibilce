#include "biblioteca.h"

//Arquivo responsável para ter as funções que manipulam e dão opções
//para a utilização da árvore binária


void menu_arvoreb(livro *raiz){

	int escolha;


	do{
	printf("### Menu Arvore Binaria\n\n0)Inserir\n1)Exibir em pos-ordem\n2)Exibir em pre-ordem\n3)Exibir em ordem\n4)Sair");

	scanf("%d", &escolha);
	livro *novo;
	switch(escolha){
	
		case 0: novo = criar_no(); arvoreb_insere(&raiz,novo); break;
		case 1: arvoreb_posordem(raiz); break;
		case 2: arvoreb_preordem(raiz); break;
		case 3: arvoreb_ordem(raiz); break;
		default: arvoreb_libera(raiz); break;
	}
	}while( escolha != 4);

	return;

}

void arvoreb_insere(livro *raiz, livro *novo)
{
	if(raiz == NULL)
	{
		raiz = criar_no();
		printf("%s inserido\n", novo -> nome);
		free(novo);
		return;
	}

	if(novo -> ID < raiz -> ID)
	{
		arvoreb_insere(raiz -> esq, novo);
		return;
	}

	if(novo -> ID > raiz -> ID)
	{
		arvoreb_insere(raiz -> dir, novo);
		return;
	}
	printf("\n%s ja esta na arvore\n", novo -> nome);
}


void arvoreb_ordem(livro *raiz)
{
	
	if(raiz == NULL)
		return;
	arvoreb_ordem(raiz -> esq);
	exibe(raiz);
	arvoreb_ordem(raiz -> dir);
}

void arvoreb_preordem(livro *raiz)
{
	/* RED - Visita a Raiz, caminha na sub-árvore esquerda e caminha na sub-árvore direita */
	if(raiz == NULL)
		return;
	exibe(raiz);
	arvoreb_preordem(raiz -> esq);
	arvoreb_preordem(raiz -> dir);
}

void arvoreb_posordem(livro *raiz)
{
	/* EDR - Caminha na sub-árvore esquerda, caminha na sub-árvore direita e visita a Raiz */
	if(raiz == NULL)
		return;
	arvoreb_posordem(raiz ->esq );
	arvoreb_posordem(raiz -> dir);
	exibe(raiz);
}

int arvoreb_libera( livro *raiz){
	livro *temp = raiz;

	if((temp) != NULL){
		arvoreb_libera(temp -> esq);
	  arvoreb_libera( temp->dir);
	  free(temp);
	  temp = NULL;
	  exit(0);
  }
	return 0;
}
