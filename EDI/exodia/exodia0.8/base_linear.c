#include "biblioteca.h"

//responsável por armazenar as funções usadas nas estruturas lineares
//tais como pilha e fila, implementadas no projeto

//Essa função verifica se a estrutura linear está vazia
int verifica_vazia(livro *topo){

	if( topo -> prox == NULL)
		return 1;
	else
		return 0;
}

void inserir_inicio(livro *topo){
	int i = 0;
	livro *novo = criar_no();
	livro *temp = topo;
	
	printf ("\n%d", novo -> ID);
	if (verifica_vazia(topo)){
		temp -> prox = novo;
		novo -> prox = NULL;
		novo -> ant = temp;
		
	}else{
		novo -> ant = temp;
		novo -> prox = temp -> prox;
		temp -> prox = novo;
			
	}
	return;
}

void inserir_final(livro *topo){

	livro *temp = topo, *novo, *temp2;
	novo = criar_no();
	if ( topo -> prox != NULL ){
		
		while (temp -> prox != NULL){
			temp2 = temp;
			temp = temp -> prox;
		}
		temp -> prox = novo;
		novo -> prox = NULL;
		novo -> ant = temp;
	}
	return;
}


void remover_final(livro* topo){

	livro *temp = topo -> prox;
	livro *temp2;

	if ( topo -> prox != NULL ){
		
		while (temp -> prox != NULL){
			temp2 = temp;
			temp = temp -> prox;
		}
		temp2 -> prox = NULL;
		free(temp);
		
	}
	return;
}

void remover_inicio(livro *topo){
	livro *temp = topo;
	livro *temp2 = topo -> prox;
	if ( topo -> prox != NULL){ 
		
		if(temp2 != NULL){
	
			temp = temp -> prox;
			temp2 = temp -> prox;
		
			temp2 -> ant = topo;
			temp2 -> prox = NULL;
			topo -> prox = temp2;
			free(temp);
		}else{
	
			temp = temp -> prox;
			topo -> prox = NULL;
			free(temp);
		}
		}else{
			printf ("\nestrutura vazia\n");
		}


	return;
}



void limpar_linear(livro *topo){

	livro *temp = topo;
	livro *temp2;
	if( verifica_vazia(topo)){
	while (temp -> prox != NULL){
		temp2 = temp;
		temp = temp -> prox;
		free(temp);
	}

	free(temp2);
	}

	return;

}

void exibir_linear(livro *topo){

	livro *temp = topo ;

	if (topo -> prox != NULL){
		
		while (temp -> prox != NULL){
	
			temp = temp -> prox;
			exibe(temp);
			//printf ("\n%d", temp -> ID);
		}
	}
	else{
		printf ("\nEstrutura vazia!\n");
	}
	return;
}



