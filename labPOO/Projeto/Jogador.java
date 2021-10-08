public class Jogador extends Funcionario {

	private boolean reserva;
	private int faltasCometidas;
	private int assistencias;
	private int cartaoAmareloTotal;
	private int cartaoVermelhoTotal;
	private int posicao;
	private int camisa;

	protected int golsMarcados;

	private enum jogadorPosicao{
	
		goleiro(16, "goleiro", 2),
		zagueiro(17, "zagueiro", 8),
		lateral(18, "lateral", 6),
		volante(19, "volante", 5),
		meias(20, "meias", 6),
		atacante(21, "atacante", 5);

		private int valor;
		private String descricao;
		private int quantidade;

		private jogadorPosicao(int valor, String descricao, int quantidade){
			this.valor = valor;
			this.descricao = descricao;
			this.quantidade = quantidade;
		}

		public String getPosicao(){
			return descricao;
		}

		public int getPosicaoID(){
			return valor;
		}

		public int getQuantidade(){
			return quantidade;
		}
}

	
	public void setJogador(int faltasCometidas, boolean reserva, int assistencias, int golsMarcados, int cartaoAmareloTotal, int cartaoVermelhoTotal, int posicao, int camisa, double salarioHora, String nome, int ID, int horasTrabalhadas, int tipo){
		this.faltasCometidas = faltasCometidas;
		this.reserva = reserva;
		this.assistencias = assistencias;
		this.golsMarcados = golsMarcados;
		this.cartaoAmareloTotal = cartaoAmareloTotal;
		this.cartaoVermelhoTotal = cartaoVermelhoTotal;
		this.posicao = posicao;
		this.camisa = camisa;
		this.salarioHora = salarioHora;
		this.nome = nome;
		this.ID = ID;
		this.horasTrabalhadas = horasTrabalhadas;
		this.tipo = tipo;

	}

	public int getFaltasCometidas(){
		return faltasCometidas;
	}

	public boolean getReserva(){
		return reserva;
	}


	public int getAssistencias(){
		return assistencias;
	}


	public int getCartaoAmareloTotal(){
		return cartaoAmareloTotal;
	}

	public int getCartaoVermelhoTotal(){
		return cartaoVermelhoTotal;
	}
	

	public int getPosicao(){
		return posicao;
	}



	public int getHorasTrabalhadas(){
		return super.getHorasTrabalhadas();
	}

	public int getID(){
		return super.getID();
	}
}
