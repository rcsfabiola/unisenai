#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include "requisicao.h"

#define CAPACIDADE_MAXIMA 1000  // Capacidade máxima da fila

// Estrutura da fila (array estático circular)
typedef struct {
    Requisicao* dados[CAPACIDADE_MAXIMA]; // Array de ponteiros para requisições
    int inicio;   // Índice do primeiro elemento
    int fim;      // Índice do próximo espaço livre
    int tamanho;  // Quantidade atual de requisições na fila
} Estrutura;

// Cria e retorna uma nova fila alocada dinamicamente
Estrutura* create();

// Insere uma requisição no final da fila
void inserir(Estrutura* e, Requisicao* r);

// Remove e retorna a requisição do início da fila (FIFO)
Requisicao* remover(Estrutura* e);

// Retorna a quantidade de requisições aguardando na fila
int get_size(Estrutura* e);

// Libera a memória da estrutura (não libera as requisições individualmente)
void libera_estrutura(Estrutura* e);

#endif