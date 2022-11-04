//Lucas Villela Canôas www.lcsvillela.com

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

//criação de estrutura de lista circular para armazenamento
typedef struct Lista{

    char palavra[100];
    struct Lista *prox;
    struct Lista *ant;

} lista;

//declaração do protótipo das funções
lista *adicionar(char *palavra, lista *cabeca);
lista* exibe(int numero, lista *aux, FILE *linhas, lista *cabeca);


int main(){

    //declaração dos arquivos e sua abertura com modo escrita ou leitura
    FILE *codigos = fopen("codigos.dat", "r");
    FILE *linhas = fopen("linhas.dat", "w");
    FILE *palavras = fopen("palavras.dat", "r");

    char buffer[MAX], *token; //um buffer para armazenar a leitura dos arquivos
    int flag_cabeca = 0, contador = 0;; // flags para controlar o estado e o contador de palavras que sobram
    lista *cabeca = malloc(sizeof(struct Lista)); //declaração do primeiro nó
    cabeca -> prox = NULL; //determinando que os ponteiros fiquem NULL
    cabeca -> ant = NULL; // medida anti-ponteiro selvagem

    lista *ultimo = cabeca, *aux = NULL; //o no cabeça nesse momento é o ultimo, variável auxiliar declarada

    fgets(buffer, MAX, palavras); //lendo a linha do arquivo de palavras
    
    token = strtok(buffer, " "); //separa a primeira string com o separados e extrai
    strcpy(cabeca -> palavra, token); // copia a primeira string para o primeiro nó
    while (token =strtok(NULL, " ")){
        ultimo = adicionar(token, cabeca); //nesse laço faço a extração das palavras e adiciono na lista circular as palavras que serão utilizadas
    }

    fgets(buffer, MAX, codigos);//leio os codigos do arquivo

    ultimo -> prox = cabeca; //o ultimo no se liga com a cabeça da lista, tornando-a circular
    cabeca -> ant = ultimo; //a cabeça se liga ao no anterior, que é o último nó

    aux = cabeca; //a variavel auxiliar é nesse momento igual a cabeça
    token = strtok(buffer, " "); // extraindo o primeiro numero do arquivo codigos que foi armazenado no buffer
    aux = exibe(atoi(token), aux, linhas, cabeca); //primeira execução do exibe que faz salvar no arquivo linhas e altera o posicionamento do ponteiro
    
    while( token = strtok(NULL, " ")){
        //nesse laço é realizado a leitura do buffer contendo os codigos
        //depois disso, a função exibe é executada e faz com que seja salvo
        //no arquivo as palavras necessárias.
        //Caso a cabeça seja retornada, sai do laço e altera a flag
            aux = exibe(atoi(token), aux, linhas, cabeca);
        
        if (aux == cabeca){
            flag_cabeca = 1;
            
            break;
        }
    }

    if (flag_cabeca == 1){
        //com a flag alterada, significa que ainda é possível que exista
        //codigos não executados, caso existam este laço é executado
        while (token = strtok(NULL, " ")){
            fprintf(linhas, "%d ", atoi(token));
        }
    }else{
        //caso a flag seja 0 ainda, signfica que existem palavras nao
        //exibidas e que os codigos acabaram. Contando o numero de palavras
        //é possível chegar no numero de linhas com cinco palavras que
        //sobram
        while ( aux != cabeca){
            contador++;
            aux = aux -> prox;
        }
        
        fprintf (linhas, "%d", contador/5);
        //salvando o numero de linhas faltantes que tem cinco palavras


    }

    fclose(linhas);
    fclose(codigos);
    fclose(palavras);//todos os arquivos fechados
}

lista* adicionar(char *palavra, struct Lista *cabeca){

    lista *elemento = malloc(sizeof(struct Lista)); // cria um novo nó
    elemento -> prox = NULL; // determina os ponteiros como NULL
    elemento -> ant = NULL;
    lista *aux = cabeca ; //varivel auxiliar para nao alterar a cabeça
    strcpy (elemento -> palavra, palavra); // copia a string para o elemento

    if (cabeca -> prox == NULL){
        //caso a lista circular esteja vazia, insere o elemento novo
        cabeca -> prox = elemento;
        elemento -> ant = cabeca;
        return elemento;//elemento retornado para marcar como último elemento

    }else{
        //caso a lista circular nao esteja vazia, vai para o ultimo elemento
        //e lá adiciona mais elemento ajustando os ponteiros para o ultimo
        //e anterior
        while (aux -> prox != NULL){
            aux = aux -> prox;
        }
        aux -> prox = elemento;
        elemento -> ant = aux;
        return elemento;
    }
}

lista* exibe(int numero, struct Lista *aux, FILE *linhas, struct Lista *cabeca){

    if (numero == 0){
        fprintf(linhas, "%s\n", "0");
        return aux;
        //caso o numero recebido seja zero, salva o numero zero no arquivo
        //e retorna o mesmo nó
    }

    if (numero > 0){
        //caso seja maior que zero, entra no laço while que decrementa
        //o numero até que seja igual a zero. Enquanto isso, salva as
        //palavras
        while (numero != 0 ){
            numero--;

            fprintf(linhas, "%s ", aux -> palavra);
            aux = aux -> prox;
            if (aux == cabeca){
                break;
                //se as palavras acabarem, quebra o laço
            }            
        }
        //pula uma linha
        fprintf(linhas, "%s", "\n");
        return aux;
    }else{
        //se o numero for menor que zero, então será incrementado
        //até que se torne zero, enquanto isso a lista circular é lida
        //no sentido contrário até que o número seja 0
        while(numero != 0){
            numero++;
            aux = aux -> ant;
            fprintf(linhas, "%s ", aux -> palavra);
        }
        fprintf(linhas, "%s", "\n");
        return aux;
    }

}
