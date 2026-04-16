#ifndef REQUISICAO_H
#define REQUISICAO_H

// Estrutura que representa uma requisição de atendimento de saúde
typedef struct {
    char nomePaciente[40];       // Nome do paciente (até 40 caracteres)
    int codigoInscricao;         // Código de inscrição no sistema de saúde
    char codigoProcedimento[10]; // Código do procedimento solicitado
} Requisicao;

// Cria uma nova requisição alocada dinamicamente
Requisicao* cria_requisicao(const char* nome, int inscricao, const char* procedimento);

// Getters
const char* get_nome(Requisicao* r);
int         get_inscricao(Requisicao* r);
const char* get_procedimento(Requisicao* r);

// Libera a memória de uma requisição
void libera(Requisicao* r);

#endif