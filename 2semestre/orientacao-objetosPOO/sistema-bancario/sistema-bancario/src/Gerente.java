import java.util.Date;

public class Gerente extends Pessoa {

  private double salario;
  private Date dataAdmissao;

  public Gerente(String nome, String cpf, Date dataNascimento, String endereco, String telefone, double salario, Date dataAdmissao) {
    super(nome, cpf, dataNascimento, endereco, telefone);
    this.salario = salario;
    this.dataAdmissao = dataAdmissao;
  }

  public double getSalario() {
    return salario;
  }

  public void setSalario(double salario) {
    this.salario = salario;
  }

  public Date getDataAdmissao() {
    return dataAdmissao;
  }  
}