/**
 * lista.c
 * Implementacao da lista encadeada simples e generica.
 *
 * Mantém ponteiros para o inicio e o fim, garantindo insercao O(1).
 */
#include <stdlib.h>
#include "lista.h"

struct Lista {
    Nodo *inicio;
    Nodo *fim;
    int   quantidade;
};

Lista* cria_lista(void) {
    Lista *l = (Lista *)malloc(sizeof(Lista));
    if (l) {
        l->inicio     = NULL;
        l->fim        = NULL;
        l->quantidade = 0;
    }
    return l;
}

void libera_lista(Lista *lista) {
    if (!lista) return;
    Nodo *atual = lista->inicio;
    while (atual) {
        Nodo *prox = get_next(atual);
        libera_nodo(atual);
        atual = prox;
    }
    free(lista);
}

void insere_lista(Lista *lista, void *dado) {
    if (!lista) return;
    Nodo *novo = cria_nodo(dado);
    if (!novo) return;
    if (!lista->fim) {
        lista->inicio = novo;
        lista->fim    = novo;
    } else {
        set_next(lista->fim, novo);
        lista->fim = novo;
    }
    lista->quantidade++;
}

Nodo* get_inicio(Lista *lista) {
    return lista ? lista->inicio : NULL;
}

int get_quantidade(Lista *lista) {
    return lista ? lista->quantidade : 0;
}
