/*Nome
numero de matricula
turma
prova1
prova2
prova3
ano-turma

funções
	media simples de cada aluno
	media da turma
	comparativo entre ano da turma

Obs
	guarda ao menos 5 anos
	minimo de 3 turmas

----------------------------------
Escrito por Lucas Villela Canôas |
disciplina: Estrutura de Dados I |
---------------------------------|
	*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int quantidade_anos = 5; // define o numero de anos para guardar na memoria
int quantidade_turmas = 3; // define o numero de turmas por ano
int quantidade_alunos = 20; //define o numero de alunos por sala


typedef struct Alunos{

	int nome;
	int matricula;
	int turma;
	float p1,p2,p3;
	int ano;
}aluno;

int integridade(aluno **turmas);
void compara(aluno ***pturmas);
void popula(aluno ***pturmas);
aluno **aloca (aluno ***pturmas);
void desaloca(aluno ***pturmas);


int main(){
	
	int continuar;
	int i;
	aluno ***pturmas; //Usando indireção multipla,
			  //podemos fazer com que a mesma estrutura da memória tenha os anos e as turmas de forma mais organizada

	aluno buffer;

	pturmas = (aluno***) malloc (sizeof(aluno**)*quantidade_anos); //Armazena memória para a quantidade de anos registrados, observe que é necessário sempre fazer a conversão para o tipo do armazenamento 

	for (i = 0; i < quantidade_anos; i++)
		pturmas[i] = aloca(pturmas); //Faz a alocação de memória para as turmas e TADs
	
	

	popula(pturmas);
	compara(pturmas);
	desaloca(pturmas);
	printf ("\n");
	return 0;



}

//verifica se a memória pode ser alocada
int integridade (aluno **turmas){

	if (!(turmas))
		return 0;
	else
		return 1; 


}


void desaloca(aluno ***pturmas){

	free (pturmas);
}

//Retorna o ponteiro para o bloco de memória em que as turmas serao armazenadas
aluno** aloca (aluno ***pturmas){

	aluno **turmas;
	int i;
	turmas = (aluno**) malloc (sizeof(aluno*)*quantidade_turmas); //Aloca memória para a quantidade de turmas para cada ano da escola

	for (i = 0; i < quantidade_turmas; i++)
		turmas[i] = (aluno*) malloc (sizeof(aluno)*quantidade_alunos); //Aloca memória para a quantidade de alunos

	if (!integridade(turmas))
		exit (1);
	else
		return (turmas);



}

//Preenche com dados aleatorios para testar o programa
void popula(aluno ***pturmas){
	
	int i, j, k, l;
	time_t t;
	srand(t);

	for (i = 0; i < quantidade_anos; i++){

		printf ("Ano %d ", i);

		for (j = 0; j < quantidade_turmas; j++){
			
			printf ("\nTurma %d \n\n", j);

			for (k = 0; k < quantidade_alunos; k++){
		
				pturmas[i][j][k].p1 = rand () % 10 + 0;
				pturmas[i][j][k].p2 = rand () % 10 + 0;
				pturmas[i][j][k].p3 = rand () % 10 + 0;
				
				pturmas[i][j][k].nome = rand () % 200 + 40;
				pturmas[i][j][k].matricula = rand () % 10000 + 99999;
				pturmas[i][j][k].turma = j;
				pturmas[i][j][k].ano = i;
							
			}
		
		}
	
	}

}

//Essa função realiza a comporação das notas dos alunos
void compara(aluno ***pturmas){

	float media_turma = 0, media_ano = 0, media_aluno = 0, soma_turma = 0, soma_ano;
	int i, j, k ;

	for (i = 0; i < quantidade_anos; i++){

		for (j = 0; j < quantidade_turmas; j++) {

			printf ("\n\nAno: %d Turma: %d\n", i, j);

			//Percorre os alunos em cada turma e ano para calcular as medias do aluno, da turma e do ano
			for (k = 0; k < quantidade_alunos; k++){

				media_aluno = (pturmas[i][j][k].p1 + pturmas[i][j][k].p2 + pturmas[i][j][k].p3)/3;
				soma_turma += media_aluno;
				printf ("\nAluno %d do ano %d e da turma %d tem uma media: %f", pturmas[i][j][k].nome, i, j, media_aluno);

			
			}
			
		media_turma = (soma_turma / quantidade_alunos);
		soma_ano += media_turma;

		printf ("\nMedia da turma %d: %f", j, media_turma);
		media_turma = 0;
        soma_turma = 0;
		}
	
	media_ano = soma_ano/(quantidade_turmas);
	printf ("\nMedia do ano %d: %f", i, media_ano);
	soma_ano = 0;

	}

}

