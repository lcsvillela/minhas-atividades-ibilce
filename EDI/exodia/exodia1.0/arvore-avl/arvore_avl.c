#include "arvore_avl.h"


//libera a árvore da memória
node* libera_arvore(node* raiz){

	if (raiz != NULL){
	
		raiz -> esq = libera_arvore(raiz -> esq);
		raiz -> dir = libera_arvore(raiz -> dir);
		free (raiz);
	}
	return NULL;

}

void imprime_preordem(node*raiz){

	if (raiz != NULL){
	
		printf("\n%d altd: %d, atle: %d", raiz -> num, raiz -> altd, raiz -> alte);
		imprime_preordem(raiz -> esq);
		imprime_preordem(raiz -> dir);
	}

}


void imprime_ordem(node*raiz){
        
	if ( raiz != NULL){
		imprime_ordem(raiz ->esq);
		printf("\n%d altd: %d, alte: %d", raiz -> num, raiz-> altd, raiz -> alte);
        	imprime_ordem(raiz->dir);
    } 
}


void imprime_posordem(node *raiz){

	if ( raiz != NULL){
	
		imprime_posordem( raiz -> esq);
		imprime_posordem(raiz -> dir);
		printf("\n%d altd: %d alte: %d", raiz -> num, raiz -> altd, raiz -> alte);
	}

}


node* rotacao_simples_esquerda(node*raiz){//
   
   node *temp1, *temp2;
   temp1 = raiz -> dir;
   temp2 = raiz -> esq;
   raiz -> dir = temp2;
   temp1 -> esq = raiz;
   
   if( raiz -> dir == NULL)
   		raiz -> altd = 0;
   else if( raiz -> dir -> alte > raiz -> dir -> altd)
	   raiz -> altd = raiz -> dir -> alte + 1;
   else
	   raiz -> altd = raiz -> dir -> altd+1;

   if (temp1 -> esq -> alte > temp1 -> esq -> altd){
   	temp1 -> alte = temp1 -> esq -> alte+1;

   }else
	   temp1 -> alte = temp1 -> esq -> altd +1;

   return temp1;
}


node * rotacao_simples_direita(node*raiz){


	node *temp1, *temp2;

	temp1 = raiz -> esq;
	temp2 = temp1 -> dir;
	raiz -> esq = temp2;
	temp1 -> dir = raiz;

	if ( raiz -> esq == NULL)
		raiz -> alte = 0;
	else if (raiz -> esq -> alte > raiz -> esq -> altd)
			raiz -> alte = raiz -> esq -> alte + 1;
		else
			raiz -> alte = raiz -> esq -> altd +1;
	

	if ( temp1 -> dir -> alte > temp1 -> dir -> altd)
		temp1 -> altd = temp1 -> dir -> alte +1;
	else
		temp1 -> altd = temp1 -> dir -> altd + 1;

	return temp1;

}

node* balanceamento ( node *raiz){

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



//Responsável por inserir um novo node na árvore AVL
node* insere_avl(node *raiz, int num){

	node *novo;
	if (raiz == NULL){// Caso a raiz seja nula, o novo nó se torna a raiz
	
		novo = (node*) malloc (sizeof(node));
		novo -> num = num;
		novo -> esq = NULL;
		novo -> dir = NULL;
		novo -> altd = 0;
		novo -> alte = 0;
		raiz = novo;

	}else if ( num < raiz -> num ){// Se o novo nó tiver um num menor do que a raiz
					//ele irá ser adicionado na sub-árvore esquerda, se nao, na direita
					// passando em todas as sub-arvores existentes		
		raiz -> esq = insere_avl (raiz -> esq , num);

		if (raiz -> esq -> altd > raiz -> esq -> alte)
			raiz -> alte = raiz -> esq -> altd +1;
		else
			raiz -> alte = raiz -> esq -> alte +1;
		raiz = balanceamento (raiz);
	}else {
		raiz -> dir = insere_avl( raiz -> dir, num);
			if(raiz -> dir -> altd > raiz -> dir -> alte)
				raiz -> altd = raiz -> dir -> altd +1;
			else
				raiz -> altd = raiz -> dir -> alte +1;
			raiz = balanceamento (raiz);
	}
	return raiz;

}

int consulta_avl(node *raiz, int achado, int num){ // Essa função percorre recursivamente toda a árvore
						   // logo no inicio, verifica se o status de achado mudou
						   // se mudou, já retorna o numero
						   // se não, ele passa a percorrer os numeros, comparando o elemento
						   // armazenado em cada um deles
	if ( raiz != NULL && achado == 0){
	
		if( raiz -> num == num){
			achado = 1;
		}else if( num < raiz -> num)
			achado = consulta_avl(raiz -> esq, achado, num); 
		else
			achado = consulta_avl(raiz -> dir, achado, num);
	}
	return achado;
}


node* remove_no(node *raiz, int num){

	node *temp, *temp2;

	if (raiz == NULL)
		return NULL; //Se tentar remover uma arvore vazia, nao da SEGFAULT

	if ( raiz -> num == num){
	
		if ( raiz -> esq == raiz -> dir){// A unica possibilidade de dois nós serem iguais
						 // é que ambos sejam NULL, então não há filhos neste nó,
						 // sendo assim, o nó é liberado.		
			free(raiz);
			return NULL;
		}else if(raiz -> esq == NULL){  // Se os dois nós são diferentes e o nó da esquerda é NULL
			temp = raiz -> dir;     // significa que o que não existe é justamente ele, então salvamos
			free(raiz);		// o nó da direita em uma variável temporária e liberamos a raiz
			return temp;		// retornando a variável temporária
		}else if ( raiz -> dir == NULL){
			temp = raiz -> esq;	//Basicamente a mesma coisa do bloco anterior, mas
			free (raiz);		// com o nó da direita sendo NULL
			return temp;
		}else {		
			temp2 = raiz -> dir;                // Esse é o caso mais complicado, pois os dois filhos existem.
			temp = raiz -> dir;                 // então armazena-se os dois em variáveis temporárias
				while( temp -> esq != NULL) // e procura-se o proximo nó da esquerda que seja diferente
					temp = temp -> esq; // de NULL, será este que irá subir para ocupar o lugar vago
			temp -> esq = raiz -> esq; 	    // 
			free(raiz);
			return temp2;
		}
		}else if ( raiz -> num < num)				// se o numero for maior, então vai percorrendo
			raiz -> dir = remove_no(raiz -> dir, num);	//os nós da árvore sempre para a direta
	else								// se for menor percorre os da esquerda até achar
		raiz -> esq = remove_no(raiz -> esq, num);		// o numero a ser removido

	return raiz;

	}

node *atualiza_avl(node *raiz){// realiza a tarefa de passar nó por nó atualizando os valores das alturas


	if ( raiz != NULL){

		raiz -> esq = atualiza_avl(raiz -> esq); //executa recursivamente passando por todos os nós da esquerda
							// processo que é repetido no bloco mais abaixo
		
		if ( raiz -> esq == NULL) //Se o primeiro nó não tiver filhos na esquerda, então o valor é 0
			raiz -> alte = 0;
		else if ( raiz -> esq -> alte > raiz -> esq -> altd) // porém, se o valor da altura esquerda
			raiz -> alte = raiz -> esq -> alte +1;	     // for maior do que a altura direita
		else						     // entao temos que somar 1 na esquerda
			raiz -> alte = raiz -> esq -> altd +1;	     // do contrario, soma-se 1 na direita
								     // processo repetido no bloco mais abaixo

		raiz -> dir = atualiza_avl(raiz -> dir);
		if( raiz -> dir == NULL)
			raiz -> altd = 0;
		else if (raiz -> dir -> alte > raiz -> dir -> altd)
			raiz -> altd = raiz -> dir -> alte +1;
		else
			raiz -> altd = raiz -> dir -> altd +1;
		raiz = balanceamento(raiz);
	}
	return raiz;
}

void exibicao(node *raiz){

	if ( raiz != NULL ){
		printf ("\nARVORE AVL EM ORDEM\n");
		imprime_ordem(raiz);
		printf ("\n ARVORE AVL EM PRE-ORDEM");
		imprime_preordem(raiz);
		printf ("\n ARVORE AVL EM POS-ORDEM");
		imprime_posordem(raiz);
		return;
	}else{
		printf ("\nArvore vazia!\n");
		return;
	}
}

node *modo_teste(node *raiz){ //Fiz essa função apenas para agilizar o teste da árvore
			      // o numero MAX está definido na biblioteca criada
	int num, i;
	node *temp;
	temp = raiz;
	for (i = 0; i < MAX; i++){
	
		num = rand () % 1000 + 0;
		raiz = insere_avl(raiz, num);
	}

	return raiz;

}
