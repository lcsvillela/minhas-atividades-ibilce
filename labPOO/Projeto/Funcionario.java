public class Funcionario implements InterfaceEmpregado {

	protected double salarioHora;
	protected String nome;
	protected int horaExtra;
	protected int horasTrabalhadas;
	protected int ID;
	protected int tipo;

	// Identificação, descrição, quantidade
	protected enum empregadosTipo{	
		limpeza(0, "Limpeza", 10),
		gerenteGeral(1, "Gerente Geral", 1),
		gerenteAdministrativo(2, "Gerente Administrativo", 1),
		gerenteFinanceiro(3, "Gerente Financeiro", 1),
		coordenadorTecnico(4, "Coordenador Tecnico", 1),
		tecnico(5, "Tecnico", 1),
		auxiliarTecnico(6, "Auxiliar Tecnico", 1),
		preparadorFisico(7, "Preparador Fisico", 4),
		preparadorGoleiro(8, "Preparador Goleiro", 2),
		fisioterapeuta(9, "Fisioterapeuta", 4),
		analista(10, "Analista", 3),
		supervisor(11, "Supervisor", 2),
		mordomo(12, "Mordomo", 15),
		jogador(13, "Jogador", 22),
		roupeiro(14, "Roupeiro", 12),
		gandula(15, "gandula", 14);
		
		private int valor;
		private String descricao;
		private int quantidade;

		private empregadosTipo(int valor, String descricao, int quantidade){
			this.valor = valor;
			this.descricao = descricao;
			this.quantidade = quantidade;
		}


		public int getEmpregadoID(){
			return valor;
		}


		public String getEmpregadoTipo(){
			return descricao;
		}

		public int getQuantidade(){
			return quantidade;
		}
	}
	

	public void setFuncionario ( double salarioHora, String nome, int ID, int horasTrabalhadas, int tipo){
		this.salarioHora = salarioHora;
		this.nome = nome;
		this.horaExtra = horaExtra;
		this.ID = ID;
		this.tipo = tipo;
	}


	public double getSalario (){
		return this.salarioHora;
	}


	public String getNome(){
		return this.nome;
	}



	public int getHorasTrabalhadas(){
		return this.horasTrabalhadas;
	}


	public int getID(){
		return this.ID;
	}
}
