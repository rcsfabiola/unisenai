//biblioteca importada para usar data
import java.util.Date;
//classe
public class Pessoa {
//atributos
  private String nome;
  private String cpf;
  private Date dataNascimento;
  private String endereco;
  private String telefone;
//construtor
  public Pessoa(String nome, String cpf, Date dataNascimento, String endereco, String telefone) {
    this.nome = nome;
    this.cpf = cpf;
    this.dataNascimento = dataNascimento;
    this.endereco = endereco;
    this.telefone = telefone;
}
//Encapsulamento: definir aceesso fora da classe
public String getNome() {
    return nome;
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

  public String getCpf() {
    return cpf;
  }

  public Date getDataNascimento() {
    return dataNascimento;
  }

  public void setDataNascimento(Date dataNascimento) {
    this.dataNascimento = dataNascimento;
  }

  public String getEndereco() {
    return endereco;
  }

  public void setEndereco(String endereco) {
    this.endereco = endereco;
  }

  public String getTelefone() {
    return telefone;
  }

  public void setTelefone(String telefone) {
    this.telefone = telefone;
  }
}
