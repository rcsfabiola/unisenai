/**
 * lista.h
 * TAD: Lista encadeada simples e generica (insercao no final, O(1)).
 *
 * A lista NAO e dona dos dados: destruir a lista libera apenas os nodos,
 * nunca os objetos apontados por eles.
 */
#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"

typedef struct Lista Lista;

/** Cria e retorna uma lista vazia. Retorna NULL se falhar a alocacao. */
Lista* cria_lista(void);

/** Libera a lista e todos os seus nodos (NAO libera os dados). */
void   libera_lista(Lista *lista);

/** Insere um elemento no final da lista em O(1). */
void   insere_lista(Lista *lista, void *dado);

/** Retorna o primeiro nodo da lista (NULL se vazia). */
Nodo*  get_inicio(Lista *lista);

/** Retorna a quantidade de elementos da lista. */
int    get_quantidade(Lista *lista);

#endif /* LISTA_H */
