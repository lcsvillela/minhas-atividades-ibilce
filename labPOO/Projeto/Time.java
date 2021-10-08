public class Time implements InterfaceTime{

	private String nome;
	private int golsFeitos;
	private int golsContra;
	private int vitorias;
	private int derrotas;
	private int empates;
	private double gastos;
	private double receita;
	

	public void setInfos (int golsFeitos, int golsContra, int vitorias, int derrotas, int empates){
		this.golsFeitos = golsFeitos;
		this.golsContra = golsContra;
		this.vitorias = vitorias;
		this.derrotas = derrotas;
		this.empates = empates;
	}


	public int getGolsContra(){
		return golsContra;
	}


	public int getGolsFeitos(){
		return golsFeitos;
	}


}
