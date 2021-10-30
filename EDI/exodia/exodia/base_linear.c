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


//Tem o necessário para a construção de uma pilha organizado em um menu
void menu_pilha(livro *topo){

	int escolha = 0;

	do{
	printf ("\n### Menu Pilha\n");
	printf ("0) Adicionar\n1)remover\n2)Exibir\n3)Sair");
	scanf("%d", &escolha);

	
	
	
		switch (escolha){
	
			case 0: inserir_inicio(topo); break;
			case 1: remover_inicio(topo); break;
			case 2: exibir_linear(topo); break;
			default:limpar_linear(topo); 
		}

	} while( escolha != 3);
	return;
}


//Tem o necessário para implementar uma fila organizado em um menu
void menu_fila(livro *topo){

	int escolha;
	printf ("\n### Menu Fila ###");
	
	do{
	printf ("\n0)Adicionar\n1)Remover\n2)Exibir\n3)Sair");
	scanf("%d", &escolha);

	

		switch(escolha){
	
			case 0: inserir_inicio(topo); break;
			case 1: remover_final(topo); break;
			case 2: exibir_linear(topo); break;
			default: limpar_linear(topo);
		}
	}while ( escolha != 3);

	return;
}
