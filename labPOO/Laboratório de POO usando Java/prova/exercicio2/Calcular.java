/* O programa a seguir simula uma calculadura simples em java, onde realiza as 4 operações básicas de uma calculadora
 * Prova de Laboratório de Programação Orientada a Objetos
 * Aluno: Lucas Villela Canôas
 * Professor: Allan Contessoto
 * */

import java.util.*;

//A classe calcular é a responsável por abrigar o método principal da função
public class Calcular {


	public static void main (String args[]){
	
		int escolha;
		int numero1, numero2, numero3, erro = 1;
		double resultado = 0;
		Scanner sc = new Scanner(System.in);
		System.out.println ("\nDigite 3 numeros inteiros: ");

		numero1 = sc.nextInt();
		numero2 = sc.nextInt();
		numero3 = sc.nextInt();


		System.out.println("\n\nQual operação você gostaria de realizar?");
		System.out.println("\n1) Somar os tres numeros");
		System.out.println("\n2) Dividir os tres numeros");
		System.out.println("\n3) Multiplicar os tres numeros");
		System.out.println("\n4)Subtrair os tres numeros");
	
		escolha = sc.nextInt();
		
		//Usando o switch podemos restringir a alocação de memória
		switch (escolha){
		
			case 1: 
				Soma somar = new Soma();
				somar.setSoma(numero1 ,numero2, numero3);
				resultado = somar.getResultado();
				break;

			case 2: 
				Divisao dividir = new Divisao(); 
				erro = dividir.setDivisao(numero1, numero2, numero3);
				if (erro == 0 ){
					System.out.println("Erro: Nao pode dividir por zero");
					System.exit(0);
				}
				resultado = dividir.getResultado();	
				break;

			case 3: 
				Multiplicacao multiplicar = new Multiplicacao();
				multiplicar.setMultiplicacao(numero1, numero2, numero3);
				resultado = multiplicar.getResultado();
				break;

			case 4: Subtracao subtrair = new Subtracao(); 
				subtrair.setSubtracao(numero1, numero2, numero3);
				resultado = subtrair.getResultado();
				break;
		}


		System.out.println("\nRESULTADO: " +resultado);


	}

}
