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
	
		case 0: arvoreb_insere(&raiz); break;
		case 1: arvoreb_posordem(raiz); break;
		case 2: arvoreb_preordem(raiz); break;
		case 3: arvoreb_ordem(raiz); break;
		default: arvoreb_libera(raiz); break;
	}
	}while( escolha != 4);

	return;

}

//a função insere na árvore binária de modo interativo
void arvoreb_insere(livro **raiz) 
{
    livro *temp, *temp2;
    
    livro *novo = criar_no();

    if (*raiz == NULL)
        *raiz = criar_no();
    else
    {
        temp = *raiz;
        while (temp != NULL)
        {
            temp2 = temp;
            if (novo -> ID < temp -> ID)
                temp = temp -> esq;
            else
                temp = temp -> dir;
        }

        if (novo -> ID < temp2 -> ID)
            temp2 -> esq = criar_no();
        else
            temp2 -> dir = criar_no();
    }
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
	/* RED - Vai para a Raiz, depois para a sub-árvore esquerda e posteriormente na sub-árvore direita */
	if(raiz == NULL)
		return;
	exibe(raiz);
	arvoreb_preordem(raiz -> esq);
	arvoreb_preordem(raiz -> dir);
}

void arvoreb_posordem(livro *raiz)
{
	/* EDR - Vai na sub-árvore esquerda, depois na sub-árvore direita e depois a Raiz */
	if(raiz == NULL)
		return;
	arvoreb_posordem(raiz ->esq );
	arvoreb_posordem(raiz -> dir);
	exibe(raiz);
}


//libera a árvore da memória
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
