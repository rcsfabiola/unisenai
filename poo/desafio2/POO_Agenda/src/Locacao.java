import java.util.Date;
import java.util.Locale;

public class Locacao {
    private Date dataInicio;
    private Date dataTermino;
    private Date dataPagamento;

    // associações
    private Corretor corretor;
    private Locatario locatario;
    private Imovel imovel;

    // construtor
    public Locacao(Date dataInicio, Date dataTermino, Date dataPagamento,
                   Corretor corretor, Locatario locatario, Imovel imovel) {
        this.dataInicio = dataInicio;
        this.dataTermino = dataTermino;
        this.dataPagamento = dataPagamento;
        this.corretor = corretor;
        this.locatario = locatario;
        this.imovel = imovel;
    }

    // + enviarCobranca() : void
    public void enviarCobranca() {
        double valor = imovel.calcularAluguel();
        System.out.println();
        System.out.println("E-mail: " + locatario.getEmail());
        System.out.println(String.format(Locale.forLanguageTag("pt-BR"),
            "O valor referente ao seu aluguel neste mês foi de R$%.2f", valor));
    }

    // + pagarProprietario() : void
    public void pagarProprietario() {
        double aluguel = imovel.calcularAluguel();

        double percentualComissao = corretor.getComissao();
        double valorComissao = aluguel * percentualComissao;
        double valorLiquidoProprietario = aluguel - valorComissao;

        // obtém o proprietário a partir do imóvel
        Proprietario proprietario = imovel.getProprietario();
        if (proprietario == null) {
            throw new IllegalStateException("Imóvel sem proprietário definido.");
        }

        // chama receber() do proprietário com o valor líquido
        proprietario.receber(valorLiquidoProprietario);

        // chama receber() do corretor com o valor da comissão
        corretor.receber(valorComissao);
    }

    // getters
    public Date getDataInicio() { return dataInicio; }
    public Date getDataTermino() { return dataTermino; }
    public Date getDataPagamento() { return dataPagamento; }

    public Corretor getCorretor() { return corretor; }
    public Locatario getLocatario() { return locatario; }
    public Imovel getImovel() { return imovel; }
}