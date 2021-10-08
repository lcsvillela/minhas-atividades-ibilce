/* O objetivo é escrever um programa que registre os alunos e professores, calcule a média e exiba a média do aluno, se ele foi aprovado, reprovado
 * ou foi para exame
 * */

import java.util.*;

public class Main{

	static List<Disciplina> disciplinaLista = new ArrayList<>(); //Cria uma lista de disciplinas para registrar os alunos
	static List<Aluno> alunosLista = new ArrayList<>(); //Cria uma lista de alunos
	static Disciplina disciplina = new Disciplina(); //Cria um objeto
	static Aluno aluno = new Aluno();
	
	public static void cadastrarDisciplina(){
		String nomeProfessor;
		String id;
		String nomeDisciplina;
		double nota1;
		double nota2;
		
			Scanner sc = new Scanner(System.in);



			
			System.out.println("\nDigite o nome do professor: ");
			nomeProfessor = sc.nextLine();
			System.out.println("\nDigite o identificador da matéria: ");
			id = sc.nextLine();
			System.out.println("\nDigite o nome da disciplina: ");
			nomeDisciplina = sc.nextLine();
			System.out.println("\nDigite a nota da primeira prova: ");
			nota1 = sc.nextDouble();
			System.out.println("\nDigite a nota da segunda prova: ");
			nota2 = sc.nextDouble();

			disciplina.setDisciplina(nomeProfessor, id, nomeDisciplina, nota1, nota2);
			disciplinaLista.add(disciplina);

			



	}

	public static void cadastrarAluno(){

		String nome;
		String matricula;
		String idade;
		String sexo;
		String cidade;
		String ingresso;

		
		int escolha = 1;
		do{

			Scanner sc = new Scanner(System.in); // Esvazia o Buffer

			System.out.println("\nNome do aluno: ");
			nome = sc.nextLine();

			System.out.println("\nMatricula:");
			matricula = sc.nextLine();

			System.out.println("\nIdade: ");
			idade = sc.nextLine();

			System.out.println("\nSexo: ");
			sexo = sc.nextLine();

			System.out.println("\nCidade: ");
			cidade = sc.nextLine();

			System.out.println("\nAno de Ingresso: ");
			ingresso = sc.nextLine();


			aluno.setAluno( nome, matricula, idade, sexo, cidade, ingresso);
			alunosLista.add(aluno);

				

			cadastrarDisciplina();

			System.out.println("\nDeseja cadastrar mais alunos? 1/0");
			escolha = sc.nextInt();
					
		
		}while (escolha == 1);
	
	}

	public static void resultados(){
	
		double media;

		for (int i = 0; i < alunosLista.size(); i++){
			
			Aluno aluno = new Aluno();
			Disciplina disciplina = new Disciplina();		
			alunosLista.get(i);
			disciplinaLista.get(i);
			


			String situacao;
			media = disciplina.getMedia();	
			System.out.println("media: " +media);
			if ( media > 5 ){
				situacao = "Aprovado";
			} else if ( media < 5 && media > 3 ){
				situacao = "Exame";
			}else{
				situacao = "Reprovado";
			}

			System.out.println("\nNome do Aluno: " + aluno.getNome() + "\nMatricula: " + aluno.getMatricula());
			System.out.println("\nDisciplina: " + disciplina.getNomeDisciplina() + "\nSituacao: " + situacao);
		}
	}

	public static void main(String arg[]){
	

		cadastrarAluno(); //Cadastra os alunos e registra uma disciplina que estão participando

		resultados();//exibe os resultados dos alunos

	
	}
	

}
