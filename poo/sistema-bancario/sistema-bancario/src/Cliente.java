import java.util.Date;

public class Cliente extends Pessoa {

  private double renda;

  public Cliente(String nome, String cpf, Date dataNascimento, String endereco, String telefone, double renda) {
    super(nome, cpf, dataNascimento, endereco, telefone);
    this.renda = renda;
  }

  public double getRenda() {
    return renda;
  }

  public void setRenda(double renda) {
    this.renda = renda;
  }
}
