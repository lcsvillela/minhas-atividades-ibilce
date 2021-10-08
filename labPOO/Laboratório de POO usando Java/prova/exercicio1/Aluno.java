
public class Aluno {

	String nome;
	String matricula;
	String idade;
	String sexo;
	String cidade;
	String ingresso;


	public void setAluno (String nome, String matricula, String idade, String sexo, String cidade, String ingresso){
	
		this.nome = nome;
		this.idade = idade;
		this.sexo = sexo;
		this.cidade = cidade;
		this.ingresso = ingresso;
	}

	public String getNome(){
		return this.nome;
	}

	public String getMatricula(){
		return this.matricula;
	}

	public String getIdade(){
		return this.idade;
	}

	public String getSexo(){
		return this.sexo;
	}

	public String getCidade(){
		return this.cidade;
	}

	public String getIngresso(){
		return this.ingresso;
	}


}
