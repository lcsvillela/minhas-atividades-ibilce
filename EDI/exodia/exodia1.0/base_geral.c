#include "biblioteca.h"

//Esse arquivo é uma base geral de funções, que podem ser usadas tanto em 
//estruturas lineares como em estruturas não lineares


//Essa função cria um nó raiz ou um nó topo, independente da estrutura
livro* cria(){
	livro *topo =  (livro*) malloc (sizeof(livro));
	topo -> prox = NULL;
	topo -> esq = NULL;
	topo -> dir = NULL;
	topo -> alte = 0;
	topo -> altd = 0;
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

void menu_arvoreb(livro *raiz){

	int escolha;


	do{
	printf("### Menu Arvore Binaria\n\n0)Inserir\n1)Exibir em pos-ordem\n2)Exibir em pre-ordem\n3)Exibir em ordem\n4)Sair");

	scanf("%d", &escolha);
	livro *novo;
	switch(escolha){
	
		case 0: novo = criar_no(); arvoreb_insere(raiz,novo); break;
		case 1: arvoreb_posordem(raiz); break;
		case 2: arvoreb_preordem(raiz); break;
		case 3: arvoreb_ordem(raiz); break;
		default: arvoreb_libera(raiz); break;
	}
	}while( escolha != 4);

	return;

}

void menu_arvore_avl(livro *raiz){

	int escolha;


	do{
	printf("### Menu Arvore AVL\n\n0)Inserir\n1)Exibir em pos-ordem\n2)Exibir em pre-ordem\n3)Exibir em ordem\n4)Sair");

	scanf("%d", &escolha);
	livro *novo;
	switch(escolha){
	
		case 0: novo = criar_no(); raiz = insere_avl(raiz,novo); break;
		case 1: imprime_posordem(raiz); break;
		case 2: imprime_preordem(raiz); break;
		case 3: imprime_ordem(raiz); break;
		default: libera_arvore(raiz); break;
	}
	}while( escolha != 4);

	return;

}
