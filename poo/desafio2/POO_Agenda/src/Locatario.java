public class Locatario extends Pessoa {
    private String email;
    private String salario; // conforme diagrama: salario : String

    public Locatario(String nome, String telefone, String endereco, String cpf,
                     String email, String salario) {
        super(nome, telefone, endereco, cpf);
        this.email = email;
        this.salario = salario;
    }

    public String getEmail() { return email; }
    public void setEmail(String email) { this.email = email; }

    public String getSalario() { return salario; }
    public void setSalario(String salario) { this.salario = salario; }
}



