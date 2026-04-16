#include <stdio.h>
#include <stdlib.h>
#include "estrutura.h"

// Cria e retorna uma nova fila alocada dinamicamente
Estrutura* create() {
    Estrutura* e = (Estrutura*) malloc(sizeof(Estrutura));
    if (e == NULL) {
        printf("Erro: memória insuficiente.\n");
        return NULL;
    }
    e->inicio = 0;
    e->fim = 0;
    e->tamanho = 0;
    return e;
}

// Insere uma requisição no final da fila (circular)
void inserir(Estrutura* e, Requisicao* r) {
    if (e->tamanho == CAPACIDADE_MAXIMA) {
        printf("Fila cheia! Não é possível inserir nova requisição.\n");
        return;
    }
    e->dados[e->fim] = r;
    e->fim = (e->fim + 1) % CAPACIDADE_MAXIMA;
    e->tamanho++;
}

// Remove e retorna a requisição do início da fila (FIFO)
Requisicao* remover(Estrutura* e) {
    if (e->tamanho == 0) {
        printf("Fila vazia! Não há requisições para remover.\n");
        return NULL;
    }
    Requisicao* r = e->dados[e->inicio];
    e->inicio = (e->inicio + 1) % CAPACIDADE_MAXIMA;
    e->tamanho--;
    return r;
}

// Retorna a quantidade de requisições na fila
int get_size(Estrutura* e) {
    return e->tamanho;
}

// Libera a memória da estrutura e de todas as requisições ainda na fila
void libera_estrutura(Estrutura* e) {
    while (e->tamanho > 0) {
        Requisicao* r = remover(e);
        free(r);
    }
    free(e);
}