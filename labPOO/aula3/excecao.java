public class excecao{

	int numero = 10;
	int divisor = 0;
	double resultado;

	public double calcular(){
	
		try{
		
			resultado = numero/divisor;
		
		} catch (ArithimeticException e){
		
			System.out.println("Nao pode dividir por zero");
		
		}
		finally{
			System.out.println("");
		}
	
	}


}
