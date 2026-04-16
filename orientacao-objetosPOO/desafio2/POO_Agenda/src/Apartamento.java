public class Apartamento extends Imovel {
    private int andar;
    private int numero;
    private double condominio;
    private double fundoReserva;
    private double investimentos;

    public Apartamento(int codigo, String endereco, double valorLocacao,
                       int vagasGaragem, int quartos, int banheiros,
                       int andar, int numero,
                       double condominio, double fundoReserva, double investimentos,
                       Proprietario proprietario) {

        super(codigo, endereco, valorLocacao, vagasGaragem, quartos, banheiros, proprietario);

        this.andar = andar;
        this.numero = numero;
        this.condominio = condominio;
        this.fundoReserva = fundoReserva;
        this.investimentos = investimentos;
    }

    public int getAndar() { return andar; }
    public void setAndar(int andar) { this.andar = andar; }

    public int getNumero() { return numero; }
    public void setNumero(int numero) { this.numero = numero; }

    public double getCondominio() { return condominio; }
    public void setCondominio(double condominio) { this.condominio = condominio; }

    public double getFundoReserva() { return fundoReserva; }
    public void setFundoReserva(double fundoReserva) { this.fundoReserva = fundoReserva; }

    public double getInvestimentos() { return investimentos; }
    public void setInvestimentos(double investimentos) { this.investimentos = investimentos; }

    @Override
    public double calcularAluguel() {
        return this.getValorLocacao() + this.condominio - this.fundoReserva - this.investimentos;
    }
}