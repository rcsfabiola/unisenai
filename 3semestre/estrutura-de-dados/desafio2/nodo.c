/**
 * nodo.c
 * Implementacao do TAD Nodo generico.
 */
#include <stdlib.h>
#include "nodo.h"

struct Nodo {
    void  *dado;
    Nodo  *proximo;
};

Nodo* cria_nodo(void *dado) {
    Nodo *n = (Nodo *)malloc(sizeof(Nodo));
    if (n) {
        n->dado    = dado;
        n->proximo = NULL;
    }
    return n;
}

void libera_nodo(Nodo *nodo) {
    free(nodo);
}

void* get_data(Nodo *nodo) {
    return nodo ? nodo->dado : NULL;
}

Nodo* get_next(Nodo *nodo) {
    return nodo ? nodo->proximo : NULL;
}

void set_next(Nodo *nodo, Nodo *proximo) {
    if (nodo) nodo->proximo = proximo;
}
