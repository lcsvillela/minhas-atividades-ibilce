#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <stdlib.h>
#include <stdio.h>
#include<time.h>
typedef struct Livro{

	char nome[20];
	int ID;
	int paginas;
	int ano;
	char autor[20];
	int volume;
	int edicao;
	struct Livro *prox;
	struct Livro *ant;
	struct Livro *dir;
	struct Livro *esq;
} livro;

//base_geral.c
livro* cria();
livro* criar_no();
void menu_pilha(livro *topo);
void menu_fila(livro *topo);
void menu_arvore_bin(livro *raiz);
//void menu_arvore_avl(livro *raiz);

livro* criar_no();

//base_linear.c
int verifica_vazia(livro *topo);
void inserir_inicio(livro *topo);
void remover_inicio(livro *topo);
void inserir_final(livro *topo);
void remover_final(livro *topo);
void limpar_linear(livro* topo);
void exibir_linear(livro *topo);

//arvore_binaria.c
void arvoreb_preordem(livro *topo);
void arvoreb_ordem(livro *topo);
void arvoreb_posordem(livro *topo);
void arvoreb_insere(livro *topo, livro *novo);
int arvoreb_libera(livro *raiz);

//arvore_avl.c
//void 

#endif
