README – Desafio 2: Sistema de Gestão Imobiliária

Disciplina: Programação Orientada a Objetos
Data de entrega: 16/11/2025
Aluno: Daiane Olete da Silva e Fabiola Reginaldo da Silva

------------------------------------------------------------
1. Descrição do Projeto
------------------------------------------------------------
Este projeto foi desenvolvido como parte do Desafio 2 da disciplina de Programação Orientada a Objetos.
O objetivo é implementar um sistema para gerenciamento de uma imobiliária, aplicando os conceitos de
herança, abstração, encapsulamento, interface e polimorfismo.

O código segue o diagrama de classes fornecido no enunciado, contendo as classes Pessoa, Corretor,
Proprietario, Locatario, Imovel, Casa, Apartamento e Locacao, além da interface RecebeValor.

------------------------------------------------------------
2. Estrutura do Projeto
------------------------------------------------------------
O projeto é composto pelos seguintes arquivos:

- Main.java .......... Classe principal que executa o sistema e demonstra o funcionamento.
- Pessoa.java ........ Classe abstrata base para Corretor, Locatario e Proprietario.
- Corretor.java ...... Implementa RecebeValor, possui métodos receber() e sacarComissoes().
- Proprietario.java .. Implementa RecebeValor, representa o dono do imóvel.
- Locatario.java ..... Representa o inquilino, contendo e-mail e salário.
- Imovel.java ........ Classe abstrata base para Casa e Apartamento.
- Casa.java .......... Calcula o aluguel com base apenas no valor de locação.
- Apartamento.java ... Calcula o aluguel considerando condomínio, fundo de reserva e investimentos.
- Locacao.java ....... Associa imóvel, corretor e locatário, enviando cobranças e efetuando pagamentos.
- RecebeValor.java ... Interface com o método receber(double valor).

------------------------------------------------------------
3. Como Compilar e Executar
------------------------------------------------------------
1. Abrir o terminal na pasta onde estão os arquivos .java.
2. Compilar todos os arquivos com o comando:
   javac *.java
3. Executar o programa principal com o comando:
   java Main

Durante a execução, o sistema exibirá no console mensagens simulando o envio da cobrança ao locatário,
o pagamento ao proprietário e o recebimento da comissão pelo corretor.

------------------------------------------------------------
4. Observações
------------------------------------------------------------
- O código foi desenvolvido conforme o diagrama UML e os requisitos descritos no enunciado.
- Todos os atributos e métodos seguem os modificadores de acesso indicados no diagrama.
- O projeto compila e executa corretamente, sem erros.
- A classe Main contém um exemplo prático que demonstra o funcionamento completo do sistema,
  simulando uma locação de imóvel.

------------------------------------------------------------