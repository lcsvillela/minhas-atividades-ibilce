public class  Professor extends Pessoa{

	protected String salario;
	protected String horaAula;
	protected String matricula;


	public void setProfessor(String salario, String horaAula, String matricula){
		super(nome, sexo, cpf);
		this.salario = salario;
		this.horaAula = horaAula;
		this.matricula = matricula;
	}	
}
