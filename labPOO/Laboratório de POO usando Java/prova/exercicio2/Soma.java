public class Soma{

	private double resultado;
	
	//Metodo que realiza a soma dos elementos passados e armazena no resultado
	public void setSoma(int numero1, int numero2, int numero3){
		this.resultado = numero1 + numero2 + numero3;
	}

	//Metodo que retorna o resultado da soma dos elementos passados
	public double getResultado(){
		return this.resultado;
	}


}
