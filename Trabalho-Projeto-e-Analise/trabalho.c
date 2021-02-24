#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#define DEZ 10
#define MIL 1000
#define CEM_MIL 100000
#define DEZ_MILHOES 10000000
#define REPETICAO 3
#define BUBBLE 0
#define MERGE 1
#define HEAP 2
#define COUNTING 3
#define QUICK 4
#define INSERTION 5

typedef struct Estatistica{
    int tipo; //bubble = 0; merge = 1;
              //heap =2; counting = 3; quick sort = 4
    double tempo;
    int quantidade;
    int repeticao;
    int *vetor;
}estatistica;

void bubble_sort(int *vetor, int tamanho);
int *insertion_sort(int *vetor, int tamanho);
int *merge_sort(int *vetor, int inicio, int fim);
int *heap_sort(int *vetor);
int *popula(int tamanho);
void merge(int *vetor, int inicio, int meio, int fim);
int heapsort(int *a,int len);
int heapify(int *a,int len, int index);
int construir_heap(int *a,int len);
int *conting_sort(int *vetor, int n, int max);
void quickSort(int vetor[], int baixo, int alto);
void troca(int* a, int* b);
int particao (int vetor[], int baixo, int alto);
void exibe_vetor(int *vetor, int i);
void relatorio(double tempo, int contador, int tipo, int repeticao, int exibir, int *vetor, int quantidade, FILE *registro);
estatistica relatorios[73];


int main(){

    int contador = 0, tipo, exibe = 0, repeticao;
    double tempo;
    clock_t comeco, final;
    FILE *registro; 
    
    int *vetor[73], tamanhos[4] = {DEZ, MIL, CEM_MIL, DEZ_MILHOES}, i;

    for (i = 0; i < 4; i++){
        for ( repeticao = 0; repeticao < 4; repeticao++){
            registro = fopen("relatorio3.txt", "a+");
            vetor[contador] = popula(tamanhos[i]);
            comeco = clock();
            bubble_sort(vetor[contador], tamanhos[i]-1);
            final = clock();
            tempo = ((double) (final - comeco))/ CLOCKS_PER_SEC;
            relatorio(tempo, contador, BUBBLE, repeticao, exibe, vetor[contador], tamanhos[i], registro);
            
            contador++;
            vetor[contador] = popula(tamanhos[i]);
            comeco = clock();
            conting_sort(vetor[contador], 0, tamanhos[i]-1);
            final = clock();
            tempo = ((double) (final - comeco))/ CLOCKS_PER_SEC;
            relatorio(tempo, contador, COUNTING, repeticao, exibe, vetor[contador], tamanhos[i], registro);

            contador++;
            vetor[contador] = popula(tamanhos[i]);
            comeco = clock();
            merge_sort(vetor[contador], 0, tamanhos[i]-1);
            final = clock();
            tempo = ((double) (final - comeco))/ CLOCKS_PER_SEC;
            relatorio(tempo, contador, MERGE, repeticao, exibe, vetor[contador], tamanhos[i], registro);

            contador++;
            vetor[contador] = popula(tamanhos[i]);
            comeco = clock();
            insertion_sort(vetor[contador], tamanhos[i]-1);
            final = clock();
            tempo = ((double) (final - comeco))/ CLOCKS_PER_SEC;
            relatorio(tempo, contador, INSERTION, repeticao, exibe, vetor[contador],  tamanhos[i], registro);

            contador++;
            vetor[contador] = popula(tamanhos[i]);
            comeco = clock();
            heapsort(vetor[contador], tamanhos[i]-1);
            final = clock();
            tempo = ((double) (final - comeco))/ CLOCKS_PER_SEC;
            relatorio(tempo, contador, HEAP, repeticao, exibe, vetor[contador], tamanhos[i], registro);

            contador++;
            vetor[contador] = popula(tamanhos[i]);
            comeco = clock();
            quickSort(vetor[contador], 0, tamanhos[i]-1);
            final = clock();
            tempo = ((double) (final - comeco))/ CLOCKS_PER_SEC;
            relatorio(tempo, contador, QUICK, repeticao, exibe, vetor[contador], tamanhos[i], registro);
            
        fclose(registro);
        }
    }


}

void relatorio(double tempo, int contador, int tipo, int repeticao, int exibir, int *vetor, int quantidade, FILE *registro){

    char algoritimo[30] = {'\0'};
    switch (tipo){
        case 0: strcpy(algoritimo, "Bubble Sort");
                break;
        case 1: strcpy(algoritimo, "Merge Sort");
                break;
        case 2: strcpy(algoritimo, "Heap Sort");
                break;
        case 3: strcpy(algoritimo, "Counting Sort");
                break;
        case 4: strcpy(algoritimo, "Quick Sort");
                break;
        case 5: strcpy(algoritimo, "Insertion Sort");
                break;
    }

    if( exibir == 0){
        relatorios[contador].tempo = tempo;
        relatorios[contador].tipo = tipo;
        relatorios[contador].repeticao = repeticao;
        relatorios[contador].vetor = vetor;
        relatorios[contador].quantidade = quantidade;
        fprintf(registro, "\n%d-----------\nTempo: %f",contador, tempo);
        fprintf(registro, "\nTipo: %s", algoritimo);
        fprintf(registro, "\nrepeticao: %d", repeticao);
        fprintf(registro, "\nelementos: %d\n", quantidade);
    }else{
        printf ("\n%d------------\nTempo: %f", contador, tempo);
        printf ("\nTipo: %s", algoritimo);
        printf ("\nRepeticao: %d", repeticao);
        printf ("\nQuantidade: %d\n", quantidade);

    }
}

int *popula(int tamanho){
    
   int *vetor = (int*) malloc (sizeof(int)*tamanho);
   time_t t;
   srand ( (unsigned)time (&t) );
   for (int i = 0; i < tamanho; i++)
       vetor[i] = rand() % 10;

   return vetor;

}

void exibe_vetor(int *vetor, int tamanho){

    for (int i = 0; i< tamanho; i++)
        printf("%d ", vetor[i]);
    printf("\n");
}

void bubble_sort(int *vetor, int tamanho){
   int i, j, aux;

    for (i = 0; i < tamanho -1; i++) {

        for (j = 1; j < tamanho - 1-i; j++)        
            if (vetor[j] > vetor[j+1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        
    }
}

int *insertion_sort(int *vetor, int tamanho){
    int key, j, i;
    for (i = 1; i < tamanho; i++) {
        key = vetor[i];
        j = i - 1;
        while (j >= 0 && vetor[j] > key) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = key;
    }
}

void merge(int *vetor, int inicio, int meio, int fim){
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;
 
    int esquerda[n1], direita[n2];
 
    for (i = 0; i < n1; i++)
        esquerda[i] = vetor[inicio + i];
    for (j = 0; j < n2; j++)
        direita[j] = vetor[meio + 1 + j];
 
    i = 0;
    j = 0;
    k = inicio;
    while (i < n1 && j < n2) {
        if (esquerda[i] <= direita[j]) {
            vetor[k] = esquerda[i];
            i++;
        }
        else {
            vetor[k] = direita[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        vetor[k] = esquerda[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        vetor[k] = direita[j];
        j++;
        k++;
    }
}

int *merge_sort(int *vetor, int inicio, int fim){
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
 
        // Sort first and second halves
        merge_sort(vetor, inicio, meio);
        merge_sort(vetor, meio + 1, fim);
 
        merge(vetor, inicio, meio, fim);
    }
}

int heapsort(int *a,int len){
    construir_heap(a,len);
    int temp;
    int novolen=len;
    while(novolen > 1){
        temp=a[0];
        a[0]=a[novolen-1];
        a[novolen-1]=temp;
        novolen--;
        heapify(a,novolen,0);

    }
    return 0;
}

int construir_heap(int *a,int len){
    int i;
    for (i=len-1; i>=0; i--) {
        if(2*i+1>len-1) continue;
        heapify(a,len,i);
    }
    return 0;
}
int heapify(int *a,int len, int index){
    int esquerda = 2 * index + 1;
    int direita = 2 * index + 2;
    int temp;
    if (esquerda > len - 1) {
        return 0;
    }
    else if(esquerda == len - 1){
        if(a[index] < a[esquerda]){
            temp = a[index];
            a[index] = a[esquerda];
            a[esquerda] = temp;
        }
        return 0;
    }
    else{
        if (a[index] < a[esquerda] || a[index] < a[direita]) {
            if (a[esquerda] < a[direita]) {
                temp = a[index];
                a[index] = a[direita];
                a[direita] = temp;
                heapify (a, len, direita);
            }
            else{
                temp = a[index];
                a[index] = a[esquerda];
                a[esquerda] = temp;
                heapify(a, len, esquerda);
            }
        }
    }
}

void troca(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}


int particao (int vetor[], int baixo, int alto){
    int pivo = vetor[alto];
    int i = (baixo - 1);

    for (int j = baixo; j <= alto- 1; j++)
    {

        if (vetor[j] < pivo)
        {
            i++;
            troca(&vetor[i], &vetor[j]);
        }
    }
    troca(&vetor[i + 1], &vetor[alto]);
    return (i + 1);
}


void quickSort(int vetor[], int baixo, int alto){
    if (baixo < alto)
    {
        int particao_index = particao(vetor, baixo, alto);


        quickSort(vetor, baixo, particao_index - 1);
        quickSort(vetor, particao_index + 1, alto);
    }
}


int *conting_sort(int *vetor, int n, int max){
     int count[max],i,j;
     
     for(i=0;i<n;++i)
        count[vetor[i]]=count[vetor[i]]+1;
}
