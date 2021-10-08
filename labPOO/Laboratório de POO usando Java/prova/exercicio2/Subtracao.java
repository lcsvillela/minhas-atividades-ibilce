public class Subtracao{

	private float resultado;
	
	//Metodo que calcula a subtracao dos elemtnsos passados
	public void setSubtracao(int numero1, int numero2, int numero3){
		this.resultado = numero1 - numero2 - numero3;
	}

	//Metodos que retorna o subtracao dos elementos passados
	public float getResultado(){
		return this.resultado;
	}


}
