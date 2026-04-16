import java.util.Date;
import java.util.Locale;

public class Corretor extends Pessoa implements RecebeValor {
    private String registro;
    private Date dataAdmissao;
    private double comissao; // conforme diagrama: comissao : double (usado como percentual, ex 0.10 = 10%)
    private double totalComissaoAcumulada;

    public Corretor(String nome, String telefone, String endereco, String cpf,
                    String registro, Date dataAdmissao, double comissao) {
        super(nome, telefone, endereco, cpf);
        this.registro = registro;
        this.dataAdmissao = dataAdmissao;
        this.comissao = comissao;
        this.totalComissaoAcumulada = 0.0;
    }

    // getters / setters
    public String getRegistro() { return registro; }
    public void setRegistro(String registro) { this.registro = registro; }

    public Date getDataAdmissao() { return dataAdmissao; }
    public void setDataAdmissao(Date dataAdmissao) { this.dataAdmissao = dataAdmissao; }

    public double getComissao() { return comissao; }
    public void setComissao(double comissao) { this.comissao = comissao; }

    public double getTotalComissaoAcumulada() { return totalComissaoAcumulada; }

    // + receber(valor : double) : void
    @Override
    public void receber(double valor) {
        // imprime mensagem conforme enunciado e adiciona ao totalComissaoAcumulada
        System.out.println(String.format(Locale.forLanguageTag("pt-BR"),
            "O corretor %s está recebendo o valor de R$%.2f", getNome(), valor));
        this.totalComissaoAcumulada += valor;
    }

    // + sacarComissoes(valor : double) : void
    public void sacarComissoes(double valor) {
        if (valor <= 0) return;
        if (valor > totalComissaoAcumulada) {
            System.out.println("Valor maior que o total de comissão acumulada. Sacando o que for possível.");
            valor = totalComissaoAcumulada;
        }
        totalComissaoAcumulada -= valor;
    }
}




