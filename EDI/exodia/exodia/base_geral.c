#include "biblioteca.h"

//Esse arquivo é uma base geral de funções, que podem ser usadas tanto em 
//estruturas lineares como em estruturas não lineares


//Essa função cria um nó raiz ou um nó topo, independente da estrutura
livro* cria(){
	livro *topo =  (livro*) malloc (sizeof(livro));
	topo -> prox = NULL;
	topo -> esq = NULL;
	topo -> dir = NULL;
	return topo;
}


//responsável por preencher aleatoriamente com dados as informações
livro* criar_no(){
	int i;
	livro *novo = (livro*) malloc (sizeof ( livro ) );

	novo -> ID = rand () % 1000 + 1;
	
	for ( i = 0; i < 18; i++){
		novo -> nome[i]= (char)rand () % 4 + 100;
		novo -> autor[i] = (char)rand() % 4 + 100;
	}
	novo -> nome[19] = '\0';
	novo -> autor[19] = '\0';
	novo -> volume = rand() % 5 + 1;
	novo -> edicao = rand() % 10 + 1;
	novo -> ano = rand () % 1980 + 2019;
	novo -> paginas = rand () % 300 + 200;
	
	return novo;
}

//Responsável por exibir a informação dos nós
void exibe(livro *topo){

	int i;
	
	printf("\nNome: %s", topo -> nome);
	printf ("\nAutor: %s", topo -> autor);
	printf("\nID: %d", topo -> ID);
	printf ("\nPaginas: %d", topo -> paginas);
	printf("\nAno: %d", topo -> ano);
	printf("\nVolume: %d", topo -> volume);
	printf("\nEdicao %d\n", topo -> edicao);
}


