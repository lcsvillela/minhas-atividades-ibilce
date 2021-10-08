public class Disciplina{

	private String nomeProfessor;
	private String id;
	private String nomeDisciplina;
	private double nota1;
	private double nota2;
	private double media;

	public void setDisciplina(String nomeProfessor, String id, String nomeDisciplina, double nota1, double nota2){
		
			this.nomeProfessor = nomeProfessor;
			this.id = id;
			this.nomeDisciplina = nomeDisciplina;
			this.nota1 = nota1;
			this.nota2 = nota2;
		}

	public double getMedia(){
	
		media = ( nota1 + nota2 )/2;
		return media;
	}

	public String getId(){
		return this.id;
	}
	
	public String getNomeDisciplina(){
		return nomeDisciplina;
	}

}

