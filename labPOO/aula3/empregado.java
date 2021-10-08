import java.util.Scanner;

public class empregado {

String nome;
double salario;


public int calcular(){

	
	if ( salario < 1500){
		 salario = salario*1.2;
	}else{
		 salario = salario*1.1;
	}

	if (salario <= 2000 ){
		return 1;
	}else{
	
		if (salario <= 3000){
			return 2;
		} else{
			if (salario <= 4000){
				return 3;
						
			}else {
				if ( salario > 4000)
					return 4;
			}
		}
	
	}


	return 0;
}



public void informacao(){

	Scanner sc = new Scanner(System.in);

	System.out.println("\nDigite o nome do empregado: ");
	nome = sc.nextLine();

	System.out.println("\nDigite o salario do empregado: ");
	salario = sc.nextFloat();

}

public static void main (String[] args){

	int decisao;
	
	empregado Emp = new empregado();
	
	Emp.informacao();
	
	decisao = Emp.calcular();
	
	switch (decisao){
	
		case 1: System.out.println("\nserá promovido em 1 ano: " +Emp.nome); break;
		case 2: System.out.println("\nserá promovido em 2 anos: " +Emp.nome); break;
		case 3: System.out.println("\nserá promovido em 3 anos: " +Emp.nome); break;
		case 4: System.out.println("\nYOU ARE FIRED: " +Emp.nome);break;
	
	}

}


}



