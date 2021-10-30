#include "biblioteca.h"


//libera um nó especificado
void libera_no(livro* temp){
    if(temp==NULL) return;
    libera_no(temp->esq);
    libera_no(temp->dir);
    free(temp);
    temp = NULL;
}

//libera a árvore da memória
void libera_arvore(livro* raiz){
    if(raiz==NULL) return;
    libera_no(raiz);
    free(raiz);
}

//Verifica se a árvore está vazia
int vazia_avl(livro* raiz){
    if(raiz==NULL)
    	return 1;
    else
	    return 0;
}

//Compara as alturas máxima das sub-árvores
int max(int a, int b){
    if(a > b) {
        return a;
    } else {
        return b;
    }
}


int altura_arvore(livro *raiz){
    if(raiz == NULL) return -1;
    if(raiz == NULL) return 0;
    int altEsq = altura_arvore( raiz -> esq);
    int altDir = altura_arvore( raiz ->dir));
    int h = max(altEsq, altDir) + 1;
    raiz->altura = h;
    raiz->balanceamento = altEsq- altDir;
    return h;
}


int total_nos_avl(livro*raiz){
    if(raiz == NULL) return -1;
    if(*raiz == NULL) return 0;
    int nodeEsq = altura_arvore(&((*raiz)->esq));
    int nodeDir = altura_arvore(&((*raiz)->dir));
    return (nodeEsq + nodeDir+1);
}


int tem_filho(livro*raiz){
    if((*raiz)->esq == NULL || (*raiz)->dir == NULL ) return 0;
    return 1;
}


void imprime_preodem(livro*raiz){
    if(raiz==NULL) printf("Deu ruim!");
    if(*raiz!=NULL) {
        //int h = altura_arvore(*raiz);
        altura_arvore(&(*raiz));
        int tem_esq = ((*raiz)->esq != NULL);
        int tem_dir = ((*raiz)->dir != NULL);
       exibe(raiz);
        if(tem_esq || tem_dir) printf(",\n\t\"filho\":[");
            imprime_preodem(&((*raiz)->esq));
            if(tem_esq && tem_dir) printf(",");
            imprime_preodem(&((*raiz)->dir));
        if(tem_esq || tem_dir) printf("]");
        printf("\n}");
    } 
}


void imprime_ordem(livro*raiz){
    if(raiz==NULL) printf("Erro");
    if(raiz!=NULL) {
        printf("\n");
        imprime_ordem(raiz ->esq);
		exibe(raiz)
        imprime_ordem(raiz->dir);
        printf("\n");
    } 
}


void imprime_posordem(livro *raiz){
    if(raiz==NULL) printf("Erro");
    if(raiz!=NULL) {
        printf("\n");
        imprime_posordem(raiz -> esq);
        imprime_posordem( raiz ->dir);
        printf("%d", raiz->ID);
        printf("\n");
    }
}


void rotacao_simples_esquerda(livro*raiz){
    printf("\nrotação a direita.");
    struct Livro *temp = raiz -> dir;
    raiz ->dir = temp->esq;
    temp->esq = raiz;
    raiz = temp;
}


void rotacao_simples_direita(livro*raiz){

    livro temp = raiz -> esq;
    raiz ->esq = temp->dir;
    temp -> dir = raiz;
    raiz = temp;
}


void rotacao_dupla_direita(livro*raiz){

    rotacao_simples_esquerda(&((*raiz)->esq));
    rotacao_simples_direita(&(*raiz));
}


void rotacao_dupla_esquerda(livro*raiz){

    rotacao_simples_direita(&((*raiz)->dir));
    rotacao_simples_esquerda(&(*raiz));
}


int insere_avl(livro *raiz, livro *novo){


    if(raiz == NULL) return -1;
    if(raiz == NULL) {
        struct Livro *novo = (struct Livro*) malloc(sizeof(struct Livro));
        if(novo==NULL) printf("\nSem espaço na memória");
		novo = cria_no();
        raiz = novo;

    } else {
        if(raiz -> ID == novo -> ID) {
            printf("\nO número %d já existe", novo->ID);
        } else {
            if(raiz -> ID > novo -> ID){
                insere_avl(raiz -> esq, novo);
            } else {
                insere_avl(raiz->dir, novo);
            }
            int h = altura_arvore(raiz);
            if( raiz ->balanceamento>1){
                if(raiz -> esq-> ID < novo -> ID){
                    rotacao_dupla_direita(raiz);
                } else {
                    rotacao_simples_direita(raiz);
                }
            }
            if( raiz ->balanceamento < -1){
                if(raiz -> dir-> ID > novo -> ID){
                   rotacao_dupla_esquerda( raiz );
                } else {
                   rotacao_simples_esquerda( raiz );
                }
            }
          
        }
    }
}