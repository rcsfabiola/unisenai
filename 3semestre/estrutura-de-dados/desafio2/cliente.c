/**
 * cliente.c
 * Implementacao do TAD Cliente.
 */
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "cliente.h"

struct Cliente {
    char   nome   [CLIENTE_STR_MAX + 1]; /* 40 caracteres uteis + '\0' */
    char   bairro [CLIENTE_STR_MAX + 1]; /* 40 caracteres uteis + '\0' */
    int    pessoas;                       /* inteiro: 1-5 (5=cinco ou mais) */
    bool   criancas;                      /* booleano: criancas < 5 anos    */
    double renda;                         /* renda familiar bruta em R$     */
};

Cliente* cria_cliente(const char *nome, const char *bairro,
                      int pessoas, int criancas, double renda) {
    if (!nome || !bairro) return NULL;

    Cliente *c = (Cliente *)malloc(sizeof(Cliente));
    if (!c) return NULL;

    strncpy(c->nome,   nome,   CLIENTE_STR_MAX);
    c->nome  [CLIENTE_STR_MAX] = '\0';

    strncpy(c->bairro, bairro, CLIENTE_STR_MAX);
    c->bairro[CLIENTE_STR_MAX] = '\0';

    /* Normaliza pessoas: minimo 1, maximo 5 (5 = cinco ou mais) */
    if      (pessoas < 1) c->pessoas = 1;
    else if (pessoas > 5) c->pessoas = 5;
    else                  c->pessoas = pessoas;

    c->criancas = criancas ? true : false;
    c->renda    = renda;
    return c;
}

void libera_cliente(Cliente *c) {
    free(c);
}

char* get_nome(Cliente *c) {
    return c ? c->nome : NULL;
}

char* get_bairro(Cliente *c) {
    return c ? c->bairro : NULL;
}

int get_pessoas(Cliente *c) {
    return c ? c->pessoas : 0;
}

bool get_criancas(Cliente *c) {
    return c ? c->criancas : false;
}

double get_renda(Cliente *c) {
    return c ? c->renda : 0.0;
}

int get_faixa_renda(Cliente *c) {
    if (!c) return 0;
    if (c->renda <= 2000.0) return 1;
    if (c->renda <= 3000.0) return 2;
    if (c->renda <= 5000.0) return 3;
    return 4;
}
