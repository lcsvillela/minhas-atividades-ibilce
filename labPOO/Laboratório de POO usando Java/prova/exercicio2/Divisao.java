public class Divisao{

	private float resultado;

	//Método que determina o resultado da divisao	
	public int setDivisao(int numero1, int numero2, int numero3){

		try{
			this.resultado = (numero1 / numero2) / numero3;
		}
		catch(ArithmeticException e){

			return 0; //Nao é recomendável que exista saída de dados nas classes, então retornando um numero posso controlar o erro
			
		}
		return 1;
	}

	//Metodo que retorna o resultado da divisao
	public float getResultado(){
		return this.resultado;
	}


}
