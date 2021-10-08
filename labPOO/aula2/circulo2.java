public class Principal {

	public static void main(String args[]) {

		Circulo umcirc; //declaracao de uma variavel circulo no metodo main.

		umcirc=new Circulo(); //alocacao dessa variavel

		System.out.println("("+umcirc.x+","+umcirc.y+","+umcirc.raio+")");

		umcirc.x=umcirc.x+17;

		System.out.println("("+umcirc.x+","+umcirc.y+","+umcirc.raio+")");
}
}

