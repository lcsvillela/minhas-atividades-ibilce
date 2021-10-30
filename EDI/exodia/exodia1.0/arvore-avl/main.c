#include "arvore_avl.h"

int main (){

	node *raiz = NULL;
	node *temp;
	int escolha;
	time_t t;
	srand (t);

	do{
		int escolha = 0, num, achado = 0;
		printf ("\n\n0) Inserir na Arvore\n1)Remover um elemento\n2) Consultar um elemento\n3)Esvaziar arvore\n");
		printf ("\n\nOpcao: ");
		scanf ("%d", &escolha);

	switch (escolha){
	
		case 0: printf ("\n\nDigite um numero: ");
			scanf("%d", &num);
			raiz = insere_avl(raiz, num);
			temp = raiz;
			exibicao(temp);
			break;
		case 1: printf ("\nDigite um numero para ser removido: ");
			scanf ("%d", &num);
			raiz = remove_no(raiz, num);
			raiz = atualiza_avl(raiz);
			temp = raiz;
			exibicao(temp);
			break;
		case 2: printf ("\nDigite um numero para ser consultado: ");
			scanf("%d", &num);
			if ( consulta_avl(raiz, achado,num) == 1 )
				printf("\n\nNumero %d esta contido na arvore", num);
			else
				printf("\n\nNumero %d nao presente na arvore", num);
			break;
		case 3: raiz = libera_arvore(raiz);
			exit(0);
			break;
		case 4: raiz = modo_teste(raiz);
			temp = raiz;
			exibicao(temp);
			break;


	}
	} while(escolha != 4);

	return 0;
}
