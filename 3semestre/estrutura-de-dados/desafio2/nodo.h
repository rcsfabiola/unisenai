/**
 * nodo.h
 * TAD: Nodo generico para lista encadeada simples.
 *
 * Armazena um ponteiro void* como dado e referencia ao proximo nodo.
 * O nodo NAO e dono do dado apontado.
 */
#ifndef NODO_H
#define NODO_H

typedef struct Nodo Nodo;

/** Cria um nodo com o dado informado. Retorna NULL se falhar a alocacao. */
Nodo* cria_nodo(void *dado);

/** Libera apenas o nodo (NAO libera o dado). */
void  libera_nodo(Nodo *nodo);

/** Retorna o dado armazenado no nodo. */
void* get_data(Nodo *nodo);

/** Retorna o ponteiro para o proximo nodo. */
Nodo* get_next(Nodo *nodo);

/** Define o ponteiro para o proximo nodo. */
void  set_next(Nodo *nodo, Nodo *proximo);

#endif /* NODO_H */
