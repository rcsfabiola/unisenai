public class Casa extends Imovel {
    private int qtdadeAndares;

    public Casa(int codigo, String endereco, double valorLocacao,
                int vagasGaragem, int quartos, int banheiros,
                int qtdadeAndares, Proprietario proprietario) {

        super(codigo, endereco, valorLocacao, vagasGaragem, quartos, banheiros, proprietario);

        this.qtdadeAndares = qtdadeAndares;
    }

    public int getQtdadeAndares() { return qtdadeAndares; }
    public void setQtdadeAndares(int qtdadeAndares) { this.qtdadeAndares = qtdadeAndares; }

    @Override
    public double calcularAluguel() {
        return this.getValorLocacao();
    }
}