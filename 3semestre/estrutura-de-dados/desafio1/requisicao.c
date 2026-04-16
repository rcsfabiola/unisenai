#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "requisicao.h"

Requisicao* cria_requisicao(const char* nome, int inscricao, const char* procedimento) {
    Requisicao* r = (Requisicao*) malloc(sizeof(Requisicao));
    if (r == NULL) {
        printf("Erro: memória insuficiente.\n");
        return NULL;
    }
    strncpy(r->nomePaciente, nome, 39);
    r->nomePaciente[39] = '\0';
    r->codigoInscricao = inscricao;
    strncpy(r->codigoProcedimento, procedimento, 9);
    r->codigoProcedimento[9] = '\0';
    return r;
}

const char* get_nome(Requisicao* r) {
    return r->nomePaciente;
}

int get_inscricao(Requisicao* r) {
    return r->codigoInscricao;
}

const char* get_procedimento(Requisicao* r) {
    return r->codigoProcedimento;
}

void libera(Requisicao* r) {
    free(r);
}