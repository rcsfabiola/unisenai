public class Matricula {
  
  //Atributos`
  private String nomeAluno;
  private String disciplina;
  private double primeiraNota;
  private double segundaNota; 
  private double terceiraNota;
  
  // Construtor que recebe Nome do Aluno e Nome da Disciplina
  public Matricula(String nomeAluno, String disciplina) {
    this.nomeAluno = nomeAluno;
    this.disciplina = disciplina;
  }

  // Encapsulamento - getters e setters 
  public String getNomeAluno() {
    return nomeAluno;
  }

  public void setNomeAluno(String nomeAluno) {
    this.nomeAluno = nomeAluno;
  }

  public String getDisciplina() {
    return disciplina;
  }

  public void setDisciplina(String disciplina) {
    this.disciplina = disciplina;
  }

  public double getprimeiraNota() {
    return primeiraNota;
  }

  public void setprimeiraNota(double primeiraNota) {
    this.primeiraNota = primeiraNota;
    if (primeiraNota < 0) this.primeiraNota = 0;
    else if (primeiraNota > 10) this.primeiraNota = 10;
    else this.primeiraNota = primeiraNota;
  }

  public double getsegundaNota() {
    return segundaNota;
  }

  public void setsegundaNota(double segundaNota) {
    this.segundaNota = segundaNota;
    if (segundaNota < 0) this.segundaNota = 0;
    else if (segundaNota > 10) this.segundaNota = 10;
    else this.segundaNota = segundaNota;
  }

  public double getterceiraNota() {
    return terceiraNota;
  }

  public void setterceiraNota(double terceiraNota) {
    this.terceiraNota = terceiraNota;
    if (terceiraNota < 0) this.terceiraNota = 0;
    else if (terceiraNota > 10) this.terceiraNota = 10;
    else this.terceiraNota = terceiraNota;
  }

  //Métodos para calcular médias
  double calcularMedia() {
    return (primeiraNota + segundaNota + terceiraNota) / 3;
  }
  double calcularMediaPonderada(double peso1, double peso2, double peso3) {
    double somaPesos = peso1 + peso2 + peso3;
    return (primeiraNota * peso1 + segundaNota * peso2 + terceiraNota * peso3) / somaPesos;
  }  
  
  //Ação para imprimir os dados
  public void imprimirDados() {
    System.out.println("-------DADOS DA MATRÍCULA-------");
    System.out.println("Nome do Aluno: " + getNomeAluno());
    System.out.println("Nome da Disciplina: " + getDisciplina());
    System.out.printf("Média simples: %.2f%n", calcularMedia());
    System.out.printf("Média ponderada: %.2f%n", calcularMediaPonderada(2, 3, 5));
  }
  
  //
  public static void main(String[] args) {
  // Atribuindo dados do aluno
    Matricula aluno = new Matricula("Maria", "Matemática");
      if (aluno == null || aluno.getNomeAluno().trim().isEmpty()) {
        aluno.setNomeAluno("Preenchimento obrigatório. Informe o nome na linha 86.");
      }
      if (aluno.getDisciplina() == null || aluno.getDisciplina().trim().isEmpty()) {
        aluno.setDisciplina("Preenchimento obrigatório. Informe o nome da disciplina na linha 86.");
      }
      
    aluno.setprimeiraNota(8.3);
    aluno.setsegundaNota(5);
    aluno.setterceiraNota(10);
    aluno.imprimirDados();
  }
}
