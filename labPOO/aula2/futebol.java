
import java.util.Scanner;

public class futebol {

public static void main(String args[]) {

	int gol, gol1;
	String time, time1;

	System.out.println("Digite o nome do primeiro time: ");
	Scanner sc = new Scanner(System.in);
	
	time = sc.next().nextLine;


	System.out.println("\nDigite o numero de gols: ");
	gol = sc.nextInt();
	
	System.out.println("\nDigite o nome do primeiro time: ");
	time1 = sc.next().nextLine();

	System.out.println("\nDigite o numero de gols: ");
	gol1 = sc.netxInt();
	
	if ( gol > gol1 )
		System.out.println("time ganhador: " +time);

	if ( gol1 > gol)
		System.out.println("time ganhador: " +time1);

	if (gol == gol1)
		System.out.println("Os times empataram!");



}

}
