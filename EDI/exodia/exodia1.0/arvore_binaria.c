#include "biblioteca.h"

//Arquivo responsável para ter as funções que manipulam e dão opções
//para a utilização da árvore binária


livro *arvoreb_insere(livro *raiz, livro *novo)
{
	if(raiz == NULL){
		raiz = novo;
		printf("%d inserido\n", novo -> ID);

	}else if(novo -> ID < raiz -> ID)
		raiz -> esq = arvoreb_insere(raiz -> esq, novo);
	else
		raiz -> dir = arvoreb_insere(raiz -> dir, novo);
	
	return raiz;
}


void arvoreb_ordem(livro *raiz)
{
	
	if(raiz != NULL){
		
		arvoreb_ordem(raiz -> esq);
		exibe(raiz);
		arvoreb_ordem(raiz -> dir);
	}
}

void arvoreb_preordem(livro *raiz)
{
	if(raiz != NULL){
		exibe(raiz);
		arvoreb_preordem(raiz -> esq);
		arvoreb_preordem(raiz -> dir);
	}
}

void arvoreb_posordem(livro *raiz)
{
	if(raiz != NULL){
		arvoreb_posordem(raiz ->esq );
		arvoreb_posordem(raiz -> dir);
		exibe(raiz);
}
}

livro* arvoreb_libera( livro *raiz){

	if (raiz != NULL){
	
		raiz -> esq = arvore_libera(raiz -> esq);
		raiz -> dir = arvore_libera(raiz -> dir);
		free (raiz);
	}
	return NULL;
}

livro *arvoreb_remove(livro *raiz, int ID){

	livro *temp, *temp2;

	if ( raiz -> ID == ID){
	
		if ( raiz -> esq == raiz -> dir){
		
			free(raiz);
			return NULL;
		}else if(raiz -> esq == NULL){
		
			temp = raiz -> dir;
			free(raiz);
			return temp;
		}else if ( raiz -> dir == NULL){
		
			temp = raiz -> esq;
			free (raiz);
			return temp;
		}else {
		
			temp2 = raiz -> dir;
			temp = raiz -> dir;
				while( temp -> esq != NULL)
					temp = temp -> esq;
			temp -> esq = raiz -> esq;
			free(raiz);
			return temp2;
		}
		}else if ( raiz -> ID < ID)
			raiz -> dir = arvoreb_remove(raiz -> dir, ID);
	else
		raiz -> esq = arvoreb_remove(raiz -> esq, ID);

	return raiz;

	}


