#include "biblioteca.h"


//libera um nó especificado
void libera_no(livro* temp){
    if(temp==NULL) return;
    libera_no(temp->esq);
    libera_no(temp->dir);
    free(temp);
    temp = NULL;
}

//libera a árvore da memória
void libera_arvore(livro* raiz){
    if(raiz==NULL) return;
    libera_no(raiz);
    free(raiz);
}

//Verifica se a árvore está vazia
int vazia_avl(livro* raiz){
    if(raiz==NULL)
    	return 1;
    else
	    return 0;
}


void imprime_preordem(livro*raiz){

	if (raiz != NULL){
	
		printf ("\n");
		exibe (raiz);
		imprime_preordem(raiz -> esq);
		imprime_preordem(raiz -> dir);
	}

}


void imprime_ordem(livro*raiz){
        
	if ( raiz != NULL){
		printf("\n");
		imprime_ordem(raiz ->esq);
		exibe(raiz);
        	imprime_ordem(raiz->dir);
	        printf("\n");
    } 
}


void imprime_posordem(livro *raiz){

	if ( raiz != NULL){
	
		printf ("\n");
		imprime_posordem( raiz -> esq);
		imprime_posordem(raiz -> dir);
		exibe(raiz);
		printf ("\n");
	}

}


livro* rotacao_simples_esquerda(livro*raiz){//
   
   livro *temp1, *temp2;
   temp1 = raiz -> esq;
   temp2 = raiz -> dir;
   raiz -> dir = temp2;
   temp2 -> esq = raiz;
   
   if( raiz -> dir == NULL)
   		raiz -> altd = 0;
   else if( raiz -> dir -> alte > raiz -> dir -> altd)
	   raiz -> altd = raiz -> dir -> altd;
   else
	   raiz -> altd = raiz -> dir -> altd+1;

   if (temp1 -> esq -> alte > temp1 -> esq -> altd){
   	temp1 -> alte = temp1 -> esq -> alte+1;

   }else
	   temp1 -> alte = temp1 -> esq -> altd +1;

   return temp1;
}


livro * rotacao_simples_direita(livro*raiz){


	livro *temp1, *temp2;

	temp1 = raiz -> esq;
	temp2 = temp1 -> dir;
	raiz -> esq = temp2;
	temp1 -> dir = raiz;

	if ( raiz -> esq == NULL)
		raiz -> alte = 0;
	else{
		if (raiz -> esq -> alte > raiz -> esq -> altd)
			raiz -> altd = raiz -> esq -> alte + 1;
		else
			raiz -> alte = raiz -> esq -> altd +1;
	}

	if ( temp1 -> dir -> alte > temp1 -> dir -> altd)
		temp1 -> altd = temp1 -> dir -> alte +1;
	else
		temp1 -> altd = temp1 -> dir -> altd + 1;

	return temp1;

}

livro* balanceamento ( livro *raiz){

	int alt1, alt2;
	alt1 = raiz -> altd - raiz -> alte;
	if (alt1 == 2){
	
		alt2 = raiz -> dir -> altd - raiz -> dir -> alte;
		if (alt2 >= 0){
			raiz = rotacao_simples_esquerda(raiz);
		}else{
			raiz -> dir = rotacao_simples_direita(raiz -> dir);
			raiz = rotacao_simples_esquerda(raiz);
		}


	}else{
	
		if (alt1 == -2){
		
			alt2 = raiz -> esq -> altd - raiz -> esq -> alte;
			if (alt2 <= 0){
				raiz = rotacao_simples_direita(raiz);
			}else{
			
				raiz -> esq = rotacao_simples_esquerda(raiz -> esq);
				raiz = rotacao_simples_direita(raiz);
			}
		}
	}

	return raiz;

}



//Responsável por inserir um novo livro na árvore AVL
livro* insere_avl(livro *raiz, livro *novo){

	if (raiz == NULL){// Caso a raiz seja nula, o novo nó se torna a raiz
	
		raiz = novo;

	}else if ( novo -> ID < raiz -> ID){// Se o novo nó tiver um ID menor do que a raiz
					//ele irá ser adicionado na sub-árvore esquerda, se nao, na direita
	
		raiz -> esq = insere_avl (raiz -> esq , novo);
		if (raiz -> esq -> altd > raiz -> esq -> alte)
			raiz -> alte = raiz -> esq -> altd +1;
		else
			raiz -> alte = raiz -> esq -> alte +1;
		raiz = balanceamento (raiz);
	}else {
		raiz -> dir = insere_avl( raiz -> dir, novo);
			if(raiz -> dir -> altd > raiz -> dir -> alte)
				raiz -> altd = raiz -> dir -> altd +1;
			else
				raiz -> altd = raiz -> dir -> alte +1;
			raiz = balanceamento (raiz);
	}
	return raiz;

}
