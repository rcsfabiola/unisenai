public class ContaPoupanca extends Conta {
  //atributos
  private double rendimento;

  //construtor
  public ContaPoupanca(String numero, Cliente cliente, double rendimento) {
    super(numero, cliente);
    this.rendimento = rendimento;
  }

  public double getRendimento() {
    return rendimento;
  }

  public void setRendimento(double rendimento) {
    this.rendimento = rendimento;
  }

  public double calcularRendimento() {
    double calcularRendimento = super.saldo * this.rendimento;
    super.saldo = super.saldo + calcularRendimento;
    return calcularRendimento;
  }
}
