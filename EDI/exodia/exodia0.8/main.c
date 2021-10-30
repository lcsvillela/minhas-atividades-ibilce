#include "biblioteca.h"

//Aluno: Lucas Villela Canoas
//Data: 27 de julho de 2019

time_t t;

int main (){

	livro *raiz = criar_no();
	livro *raiz_avl = cria();
	raiz_avl = NULL;
	livro *topo = cria();
	srand(t);
	int escolha = 0;

	do{

	printf("0) Usar pilha\n1) Usar fila\n2)usar arvore binaria\n3)usar arvore avl\n4)Sair");
	scanf("%d", &escolha);
	
		switch(escolha){
	
			case 0: menu_pilha(topo); break;
			case 1: menu_fila(topo); break;
			case 2: menu_arvoreb(raiz); break;
			case 3: menu_arvore_alv(raiz_avl); break;
			case 4: exit(0); 
		}
	}while( escolha != 4);


}
