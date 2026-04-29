/**
 * estrutura.c
 * Implementacao da estrutura hash com cinco indices independentes.
 *
 * ── Indices por string (nome / bairro) ────────────────────────────────────
 * Tabela hash com encadeamento externo por CHAVE EXATA:
 *   - Array de HASH_TAMANHO ponteiros para EntradaHash.
 *   - Cada EntradaHash guarda: chave (string), lista de clientes com
 *     aquela chave, e ponteiro para a proxima entrada do mesmo bucket
 *     (tratamento de colisoes de hash).
 *   - Busca percorre o bucket ate encontrar strcmp(chave, busca)==0.
 *   - Funcao de hash: djb2 (Dan Bernstein), distribuicao uniforme para strings.
 *
 * ── Indices discretos (pessoas / criancas / renda) ────────────────────────
 * Arrays de listas pre-alocadas em tamanho fixo (5, 2 e 4 elementos).
 * O indice e calculado diretamente a partir do valor do campo:
 *   pessoas  : indice = pessoas - 1
 *   criancas : indice = criancas (0 ou 1)
 *   renda    : indice = get_faixa_renda(cliente) - 1
 *
 * ── Gerenciamento de memoria ──────────────────────────────────────────────
 * A estrutura NAO e dona dos Clientes; apenas armazena ponteiros.
 * libera_estrutura() destroi as listas/entradas internas, nao os clientes.
 * Uma lista vazia permanente (lista_vazia) e retornada quando uma busca
 * textual nao encontra a chave, garantindo que recupera_cliente nunca
 * retorne NULL.
 */
#include <stdlib.h>
#include <string.h>
#include "estrutura.h"

/* ── Entrada de bucket para indices textuais ───────────────────────────── */
typedef struct EntradaHash {
    char              chave[CLIENTE_STR_MAX + 1]; /* 40 chars uteis + '\0' */
    Lista            *lista;
    struct EntradaHash *prox;
} EntradaHash;

/* ── Estrutura principal ────────────────────────────────────────────────── */
struct Estrutura {
    /* Indices por string */
    EntradaHash *hash_nome  [HASH_TAMANHO];
    EntradaHash *hash_bairro[HASH_TAMANHO];

    /* Indices discretos */
    Lista *listas_pessoas [5];   /* [0..4] = 1..5 pessoas          */
    Lista *listas_criancas[2];   /* [0]=sem criancas [1]=com        */
    Lista *listas_renda   [4];   /* [0..3] = faixas 1..4           */

    /* Lista vazia retornada quando chave textual nao existe */
    Lista *lista_vazia;
};

/* ── Funcao de hash djb2 ────────────────────────────────────────────────── */
static unsigned int calcular_hash(const char *s) {
    unsigned int h = 5381u;
    int c;
    while ((c = (unsigned char)*s++))
        h = ((h << 5u) + h) + (unsigned int)c; /* h * 33 + c */
    return h % (unsigned int)HASH_TAMANHO;
}

/* ── Gerenciamento de EntradaHash ───────────────────────────────────────── */
static EntradaHash* cria_entrada(const char *chave) {
    EntradaHash *e = (EntradaHash *)malloc(sizeof(EntradaHash));
    if (!e) return NULL;
    strncpy(e->chave, chave, CLIENTE_STR_MAX);
    e->chave[CLIENTE_STR_MAX] = '\0';
    e->lista = cria_lista();
    if (!e->lista) { free(e); return NULL; }
    e->prox = NULL;
    return e;
}

static void libera_entrada(EntradaHash *e) {
    if (!e) return;
    libera_lista(e->lista);
    free(e);
}

/* ── Auxiliares para os indices textuais ───────────────────────────────── */

/**
 * Busca (ou cria) a EntradaHash para 'chave' na tabela.
 * Retorna a Lista interna da entrada, pronta para receber inserção.
 */
static Lista* hash_buscar_ou_criar(EntradaHash **tabela, const char *chave) {
    unsigned int idx = calcular_hash(chave);
    EntradaHash *e   = tabela[idx];

    /* Percorre o bucket procurando a chave exata */
    while (e) {
        if (strncmp(e->chave, chave, CLIENTE_STR_MAX) == 0)
            return e->lista;
        e = e->prox;
    }

    /* Chave nao encontrada: cria nova entrada e encadeia no bucket */
    EntradaHash *nova = cria_entrada(chave);
    if (!nova) return NULL;
    nova->prox   = tabela[idx];   /* insere no inicio do bucket */
    tabela[idx]  = nova;
    return nova->lista;
}

/**
 * Busca a EntradaHash para 'chave'. Retorna NULL se nao existir.
 */
static Lista* hash_buscar(EntradaHash **tabela, const char *chave) {
    unsigned int idx = calcular_hash(chave);
    EntradaHash *e   = tabela[idx];
    while (e) {
        if (strncmp(e->chave, chave, CLIENTE_STR_MAX) == 0)
            return e->lista;
        e = e->prox;
    }
    return NULL;
}

/* ── API publica ────────────────────────────────────────────────────────── */

Estrutura* cria_estrutura(void) {
    Estrutura *est = (Estrutura *)calloc(1, sizeof(Estrutura));
    if (!est) return NULL;

    /* Pre-aloca as listas dos indices discretos */
    for (int i = 0; i < 5; i++) {
        est->listas_pessoas[i] = cria_lista();
        if (!est->listas_pessoas[i]) goto falha;
    }
    for (int i = 0; i < 2; i++) {
        est->listas_criancas[i] = cria_lista();
        if (!est->listas_criancas[i]) goto falha;
    }
    for (int i = 0; i < 4; i++) {
        est->listas_renda[i] = cria_lista();
        if (!est->listas_renda[i]) goto falha;
    }

    /* Lista vazia permanente para buscas textuais sem resultado */
    est->lista_vazia = cria_lista();
    if (!est->lista_vazia) goto falha;

    /* calloc ja zerou os arrays de hash (todos NULL) */
    return est;

falha:
    libera_estrutura(est);
    return NULL;
}

void libera_estrutura(Estrutura *est) {
    if (!est) return;

    /* Libera entradas do hash de nome */
    for (int i = 0; i < HASH_TAMANHO; i++) {
        EntradaHash *e = est->hash_nome[i];
        while (e) { EntradaHash *prox = e->prox; libera_entrada(e); e = prox; }
    }

    /* Libera entradas do hash de bairro */
    for (int i = 0; i < HASH_TAMANHO; i++) {
        EntradaHash *e = est->hash_bairro[i];
        while (e) { EntradaHash *prox = e->prox; libera_entrada(e); e = prox; }
    }

    /* Libera listas dos indices discretos (NAO os Clientes apontados) */
    for (int i = 0; i < 5; i++) libera_lista(est->listas_pessoas[i]);
    for (int i = 0; i < 2; i++) libera_lista(est->listas_criancas[i]);
    for (int i = 0; i < 4; i++) libera_lista(est->listas_renda[i]);

    libera_lista(est->lista_vazia);
    free(est);
}

void insere_cliente(Estrutura *est, int criterio, Cliente *cliente) {
    if (!est || !cliente) return;

    switch (criterio) {
        case 1: { /* Indice por nome */
            Lista *l = hash_buscar_ou_criar(est->hash_nome, get_nome(cliente));
            if (l) insere_lista(l, cliente);
            break;
        }
        case 2: { /* Indice por bairro */
            Lista *l = hash_buscar_ou_criar(est->hash_bairro, get_bairro(cliente));
            if (l) insere_lista(l, cliente);
            break;
        }
        case 3: { /* Indice por quantidade de pessoas (indice 0-based: pessoas-1) */
            int idx = get_pessoas(cliente) - 1; /* normalizado em cria_cliente */
            insere_lista(est->listas_pessoas[idx], cliente);
            break;
        }
        case 4: { /* Indice por criancas (0 ou 1) */
            insere_lista(est->listas_criancas[get_criancas(cliente)], cliente);
            break;
        }
        case 5: { /* Indice por faixa de renda (faixa 1-4 -> indice 0-3) */
            insere_lista(est->listas_renda[get_faixa_renda(cliente) - 1], cliente);
            break;
        }
        /* criterio invalido: ignora silenciosamente */
    }
}

Lista* recupera_cliente(Estrutura *est, int criterio,
                        int complemento, char *busca) {
    if (!est) return NULL;

    switch (criterio) {
        case 1: { /* Busca textual por nome */
            if (!busca) return est->lista_vazia;
            Lista *l = hash_buscar(est->hash_nome, busca);
            return l ? l : est->lista_vazia;
        }
        case 2: { /* Busca textual por bairro */
            if (!busca) return est->lista_vazia;
            Lista *l = hash_buscar(est->hash_bairro, busca);
            return l ? l : est->lista_vazia;
        }
        case 3: { /* Busca por quantidade de pessoas (complemento = 1-5) */
            if (complemento < 1 || complemento > 5) return est->lista_vazia;
            return est->listas_pessoas[complemento - 1];
        }
        case 4: { /* Busca por criancas (complemento = 0 ou 1) */
            if (complemento < 0 || complemento > 1) return est->lista_vazia;
            return est->listas_criancas[complemento];
        }
        case 5: { /* Busca por faixa de renda (complemento = 1-4) */
            if (complemento < 1 || complemento > 4) return est->lista_vazia;
            return est->listas_renda[complemento - 1];
        }
        default:
            return est->lista_vazia;
    }
}
