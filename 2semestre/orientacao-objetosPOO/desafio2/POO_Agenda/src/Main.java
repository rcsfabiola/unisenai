import java.util.Date;
import java.util.Calendar;

public class Main {
    public static void main(String[] args) {
        // datas exemplo
        Date hoje = new Date();
        Calendar c = Calendar.getInstance();
        c.setTime(hoje);
        c.add(Calendar.MONTH, 1);
        Date fim = c.getTime();

        // Simulação aluguel Apartamento
        
        // Proprietário
        Proprietario propAp = new Proprietario("João Silva", "11 99999-0000", "Rua X, 100", "111.222.333-44",
                                             "12345-6", "0001");

        // Imóvel: Apartamento
        Imovel ap = new Apartamento(
            1001, "Rua A, 123", 2000.0,
            1, 2, 1,
            5, 101,
            500.0, 100.0, 50.0,
            propAp
        );

        // Corretor
        Corretor corr = new Corretor("Mariana Lima", "11 98888-1111", "Av. Y, 200", "222.333.444-55",
                                     "REG-001", hoje, 0.10); // 10%

        // Locatário
        Locatario loc = new Locatario("Carlos Souza", "11 97777-2222", "Rua Z, 300", "333.444.555-66",
                                      "carlossouza@email.com", "3500.00");

        // Contrato de locação apartamento
        Locacao locacaoAp = new Locacao(hoje, fim, hoje, corr, loc, ap);

        // enviar cobrança
        locacaoAp.enviarCobranca();

        // pagar proprietário e corretor
        locacaoAp.pagarProprietario();

        
        
        // Simulação aluguel Casa

        Proprietario propCasa = new Proprietario("Maria Souza", "11 9988-1234", "Rua bonita, 233", "222.333.444-55",
                                             "234343423-1", "1232");
        // Imóvel: Casa
        Imovel casa = new Casa(1002, "Rua B, 400", 2500.0, 1, 3, 2, 2, propCasa);

        // Locatário
        Locatario locCasa = new Locatario("Paulo Pereira", "11 8823-4535", "Rua das flores, 768", "123.454.566-22",
                                      "paulopereira@email.com", "6000.00");
        // Contrato de locação casa
        Locacao locacaoCasa = new Locacao(hoje, fim, hoje, corr, locCasa, casa);


        // Lançamento de cobranças do apartamento e da casa
        // enviar cobrança
        locacaoCasa.enviarCobranca();

        // pagar proprietário e corretor
        locacaoCasa.pagarProprietario();

        // mostrar total de comissão acumulada
        System.out.println();
        System.out.println(String.format(java.util.Locale.forLanguageTag("pt-BR"),
            "Total de comissão acumulada do corretor: R$%.2f", corr.getTotalComissaoAcumulada()));

        // corretor saca parte da comissão
        corr.sacarComissoes(100.0);
        System.out.println();
        System.out.println(String.format(java.util.Locale.forLanguageTag("pt-BR"),
            "Após saque, comissão acumulada: R$%.2f", corr.getTotalComissaoAcumulada()));
    }
}




