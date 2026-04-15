public class ContaCorrente extends Conta {
  //atributos
  private double tarifa;
  private double limite;

  //construtores
  public ContaCorrente(String numero, Cliente cliente, double tarifa) {
    super(numero, cliente);
    this.tarifa = tarifa;
  }
  //sobrecargare do construtor
  public ContaCorrente(String numero, Cliente cliente, double tarifa, double limite) {
    super(numero, cliente);
    this.tarifa = tarifa;
    this.limite = limite;
  }
  
  //sobrescrita do métido validar saldo
  @Override
  protected boolean validarSaldo(double valor) {
    if(valor <= super.saldo + this.limite) {
      return true;
    } else {
      return false;
    }
  }

  public double getTarifa() {
    return tarifa;
  }
  public void setTarifa(double tarifa) {
    this.tarifa = tarifa;
  }
  public double getLimite() {
    return limite;
  }
  public void setLimite(double limite) {
    this.limite = limite;
  }
  
}
