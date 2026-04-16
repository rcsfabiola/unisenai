/* -- Criação do banco de dados
CREATE DATABASE empresa;
USE empresa;
-- Criação da tabela de funcionários
CREATE TABLE funcionarios (
id INT PRIMARY KEY,
nome VARCHAR(100) NOT NULL,
cargo VARCHAR(100),
salario DECIMAL(10, 2)
);
-- Criação da tabela de auditoria
CREATE TABLE auditoria_funcionarios (
auditoria_id INT AUTO_INCREMENT PRIMARY KEY,
operacao CHAR(1), -- 'I' para inserção, 'U' para atualização, 'D' para exclusão
data_operacao TIMESTAMP NOT NULL,
id INT,
nome VARCHAR(100),
cargo VARCHAR(100),
salario DECIMAL(10, 2)
);
*/

-- drop schaema empresa; deleta todo banco do dados sem recuperação
-- drop table funcionarios; deleta toda a tabela sem recuperação
-- alter table funcionarios modify column nome varchar(100) not null;
-- alter table funcionarios add i_tipo; adiciona mais uma coluna com o i_tipo;
-- alter table funcionarios drop column i_tipo; deleta a coluna i_tipo;
