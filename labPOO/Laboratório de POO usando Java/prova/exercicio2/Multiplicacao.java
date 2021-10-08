public class Multiplicacao{

	private float resultado;
	

	//Metodo que realiza o calculo da multiplicação e armazena no resultado
	public void setMultiplicacao(int numero1, int numero2, int numero3){
		this.resultado = numero1 * numero2 * numero3;
	}

	//Metodo que realiza o retorno do resultado da multiplicacao
	public float getResultado(){
		return this.resultado;
	}


}
