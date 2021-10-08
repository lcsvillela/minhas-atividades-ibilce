import java.util.*;

public class Banco {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int op = 1;
        Scanner dado = new Scanner(System.in);
        List<Cliente> listaCliente = new ArrayList<>();
        
        do{
            // le as infos do cliente
            System.out.println("Digite o nome do cliente:");
            String nome = dado.nextLine();
            dado = new Scanner(System.in); //limpa o buffer para ler uma nova string
            
            System.out.println("Digite o CPF do cliente:");
            String cpf = dado.nextLine();
            dado = new Scanner(System.in); 
            
            System.out.println("Digite o RG do cliente:");
            String rg = dado.nextLine();
            dado = new Scanner(System.in); 
            
            System.out.println("Digite o endereço do cliente:");
            String endereco = dado.nextLine();
            dado = new Scanner(System.in); 
            
            System.out.println("Digite o telefone do cliente:");
            String fone = dado.nextLine();
            dado = new Scanner(System.in);
            
            Cliente cliente = new Cliente(nome, cpf, rg, endereco, fone); // instancia o objeto de cliente
            
            // le as infos da conta do cliente recém ccriado
            System.out.println("Digite a agência da conta do cliente:");
            String agencia = dado.nextLine();
            dado = new Scanner(System.in);
            
            System.out.println("Digite o número da conta do cliente:");
            String conta = dado.nextLine();
            dado = new Scanner(System.in);
            
            System.out.println("Digite o saldo da conta do cliente:");
            double saldo = dado.nextDouble();
            
            Conta cc = new Conta(agencia, conta, saldo); //instancia o objeto da conta
            
            cliente.setContaCorrente(cc); //seta a conta criado ao cliente instanciado
            
            listaCliente.add(cliente); //adiciona o novo cliente à lista
            
            System.out.println("Digite 1 para cadastrar um novo cliente ou 0 para sair");
            op = dado.nextInt();
            dado = new Scanner(System.in);
        } while (op == 1);
        
        // exibe os clientes cadastrados
        for(int i = 0; i < listaCliente.size(); i++)
        {
            Cliente c = listaCliente.get(i); //recupera o objeto da lista
            
            System.out.println("Cliente #" + i);
            System.out.println("INFORMAÇÕES PESSOAIS");
            System.out.println("Nome: " + c.getNome() + "\nCPF: " + c.getCpf() +
                    "\nRG: " + c.getRg() + "\nEndereço: " + c.getEndereco() + "\nTelefone: " + c.getFone());
            System.out.println("INFORMAÇÕES DA CONTA");
            System.out.println("Agência: " + c.getContaCorrente().getAgencia() + "\nNúmero da conta " +
                    c.getContaCorrente().getConta() + "\nSaldo R$" + c.getContaCorrente().getSaldo());
        }
        
    }
    
}
