import java.util.ArrayList;

public class Conta {
  //atributos
  private String numero;
  protected double saldo;
  //atributos de relacionamento
  private Gerente gerente;
  private Cliente cliente;
  private ArrayList<Transacao> transacoes;

  //construtor
  public Conta(String numero, Cliente cliente) {
    this.numero = numero;
    this.cliente = cliente;
    this.saldo = 0.0;
    this.transacoes = new ArrayList<Transacao>();
  }
  //sobrecarga do construtor
  public Conta(String numero, Gerente gerente, Cliente cliente) {
    this.numero = numero;
    this.gerente = gerente;
    this.cliente = cliente;
    this.saldo = 0.0;
    this.transacoes = new ArrayList<Transacao>();
  }

  //Método Saque
  public void saque(double valor) {
    if(this.validarSaldo(valor)) {
      this.saldo = this.saldo - valor;
      this.criarTransação("saque", valor);
    } 
  }

  public void deposito(double valor) {
    this.saldo = this.saldo + valor;
    this.criarTransação("depósito", valor);
  }

  public void imprimirExtrato() {
    for (Transacao transacao : this.transacoes) {
      System.out.println("Data: " + transacao.getData() + " | Tipo: " + transacao.getTipo() + " | Valor: " + transacao.getValor());
    }
    System.out.println("Saldo atual: " + this.saldo);
  }

  public void transferencia(double valor, ContaCorrente contaCorrente, ContaPoupanca contaPoupanca) {
    if(contaCorrente.validarSaldo(valor)){
      contaCorrente.saque(valor);
      contaPoupanca.deposito(valor);
      this.criarTransação("Transferência", valor);
    }
  }  

  protected void criarTransação(String tipo, double valor) {
    Transacao transacao = new Transacao(new java.util.Date(), tipo, valor);
    this.transacoes.add(transacao);
  }

  protected boolean validarSaldo(double valor) {
    if(valor<=this.saldo) {
      return true;
    } else {
      return false;
    }
  }

  //Getters - permite acesso fora da classe
  public String getNumero() {
    return numero;
  }

  public double getSaldo() {
    return saldo;
  }

  public Gerente getGerente() {
    return gerente;
  }

  public void setGerente(Gerente gerente) {
    this.gerente = gerente;
  }

  public Cliente getCliente() {
    return cliente;
  }
}