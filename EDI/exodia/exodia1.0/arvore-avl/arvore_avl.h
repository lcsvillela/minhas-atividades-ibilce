#ifndef ARVORE_AVL_H
#define ARVORE_AVL_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20 // Numero máximo de elementos inseridos automaticamente no modo teste

typedef struct NODE{

	int num;
	int altd;
	int alte;
	struct NODE *esq;
	struct NODE *dir;
} node;

void imprime_posordem(node *raiz);
void imprime_ordem(node *raiz);
void imprime_preordem(node *raiz);
node *insere_avl(node *raiz, int num);
node* balanceamento(node *raiz);
node *rotacao_simples_direita(node *raiz);
node *rotacao_simples_esquerda(node *raiz);
node* libera_arvore(node *raiz);
node *remove_no(node *raiz, int num);
node *atualiza_avl(node *raiz);
void exibicao(node *raiz);
int consulta_avl(node *raiz, int achado, int num);
node *modo_teste(node *raiz);

#endif
