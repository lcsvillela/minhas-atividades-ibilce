import java.util.*;
import java.io.*;

public class Main {


	public static Funcionario registrarFuncionarios(){
		Scanner sc = new Scanner(System.in);

		System.out.println ("\nQual tipo de funcionario a ser registrado?" +
				"\n0)limpeza" +
				"\n1) Gerente Geral" +
				"\n2) Gerente Administrativo" +
				"\n3) Gerente Financeiro" +
				"\n4) Gerente Coordenador Técnico" +
				"\n5) Tecnico" +
				"\n6) Auxiliar tecnico" +
				"\n7) Preparador Fisico" +
				"\n8) Preparador de Goleiro" +
				"\n9) Fisioterapeuta" +
				"\n10) Analista" +
				"\n11) Supervisor" +
				"\n12) Mordomo" +
				"\n13) Jogador" +
				"\n14) Roupeiro" +
				"\n15) Gandula");
		int tipo = sc.nextInt();

		System.out.println("\nDigite o nome: ");
		sc = new Scanner(System.in);
		String nome = sc.nextLine();

		System.out.println("\nDigite o salario hora: ");
		sc = new Scanner(System.in);
		double salarioHora = sc.nextDouble();


		System.out.println("\nDigite a horas trabalhadas: ");
		sc = new Scanner(System.in);
		int horasTrabalhadas = sc.nextInt();

		System.out.println("\nDigite o ID do funcionario: ");
		sc = new Scanner(System.in);
		int ID = sc.nextInt();

		if ( tipo == 13 ){
		
			System.out.println("\nÉ reserva? 1/s ou 0/n");
			sc = new Scanner(System.in);
			int status = sc.nextInt();
			boolean reserva;
			if (status == 0){
				reserva = false;
			}
			else{
				reserva = true;
			}

			System.out.println("\nFaltas Cometidas: ");
			sc = new Scanner(System.in);
			int faltasCometidas = sc.nextInt();

			System.out.println("\nAssistencias: ");
			sc = new Scanner(System.in);
			int assistencias = sc.nextInt();

			System.out.println("\nQuantos cartoes amarelos: ");
			sc = new Scanner(System.in);
			int cartaoAmareloTotal = sc.nextInt();

			System.out.println("\nQuantos cartoes vermelhos: ");
			sc = new Scanner(System.in);
			int cartaoVermelhoTotal = sc.nextInt();

			System.out.println("\nQual a posição do jogador?" + 
					"\n0) goleiro" +
					"\n1) zagueiro" +
					"\n2)lateral" +
					"\n3) volante" +
					"\n4) meia" +
					"\n5) atacante");

			sc = new Scanner(System.in);
			int posicao = sc.nextInt();
			
			if ( posicao > 5 || posicao < 0){
				posicao = 5;
			}

			System.out.println("\nNumero da camisa: ");
			sc = new Scanner(System.in);
			int camisa = sc.nextInt();

			System.out.println("\nGols Marcados: ");
			sc = new Scanner(System.in);
			int golsMarcados = sc.nextInt();


			Jogador jogador = new Jogador();
			jogador.setJogador(faltasCometidas, reserva, assistencias, golsMarcados, cartaoAmareloTotal, cartaoVermelhoTotal, posicao, camisa, salarioHora, nome, ID, horasTrabalhadas, tipo);
			return jogador;
		}else{
			Funcionario funcionario = new Funcionario();
			funcionario.setFuncionario(salarioHora, nome, ID, horasTrabalhadas, tipo);
			return funcionario;
		}
		
	}

	
	public static Jogo registrarJogos(){

		Scanner sc = new Scanner (System.in);
		
		System.out.println("\nDigite o nome do time adversario: ");
		String adversario = sc.nextLine();

		System.out.println("\nDigite quantos gols o time adversario fez: ");
		sc = new Scanner(System.in);
		int golsAdversario = sc.nextInt();

		System.out.println("\nDigite os gols do nosso timão: ");
		sc = new Scanner(System.in);
		int golsFeitos = sc.nextInt();

		Jogo jogo = new Jogo(golsFeitos, adversario, golsAdversario);

		return jogo;
	}


	public static void gerarRelatorios(List listaFuncionarios, List listaJogos){
	System.out.println("função não implementada");
		/*	
		for (int i = 0; i < listaFuncionarios.size(); i++){
			Funcionario f = new Funcionario();
			f = listaFuncionarios.get(i);

			for (int j = 0; j < 15; j++){
			
				if ( j == f.getTipo()){}
			}
		}*/	
	}


	public static void main (String args[]){
		int escolha = 0;
		List<Funcionario> listaFuncionarios = new ArrayList<>();
		List<Jogo> listaJogos = new ArrayList<>();

		do{
		
			System.out.println("\n0) Registrar funcionarios do time" +
				"\n1) Colocar registros dos jogos" +
				"\n2) Gerar relatórios" + 
				"\n3) Sair");
			Scanner sc = new Scanner(System.in);
			escolha = sc.nextInt();
			switch(escolha){
				case 0: listaFuncionarios.add(registrarFuncionarios()); break;
				case 1: listaJogos.add(registrarJogos()); break;
				case 2: gerarRelatorios(listaFuncionarios, listaJogos); break;
				case 3: System.exit(0);
			}
		
		}while (escolha != 3);
	}


	

}
