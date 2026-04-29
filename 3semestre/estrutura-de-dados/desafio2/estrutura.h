/**
 * estrutura.h
 * TAD: Estrutura de armazenamento e recuperacao de clientes com tabela hash.
 *
 * Mantém CINCO tabelas/indices independentes, cada um otimizado para um
 * criterio de busca diferente:
 *
 *   Criterio 1 - por NOME:
 *     Tabela hash de tamanho HASH_TAMANHO (numero primo) com encadeamento
 *     externo por chave exata (djb2). Cada entrada guarda a chave (nome) e
 *     uma lista de clientes com aquele nome. Colisoes de hash sao resolvidas
 *     encadeando entradas distintas no mesmo bucket. Insercao e busca O(1)
 *     amortizado.
 *
 *   Criterio 2 - por BAIRRO:
 *     Identico ao criterio 1, com chave = bairro.
 *
 *   Criterio 3 - por QUANTIDADE DE PESSOAS (1 a 5):
 *     Array fixo de 5 listas pre-alocadas. Indice = pessoas - 1.
 *     Insercao e recuperacao O(1) exato.
 *
 *   Criterio 4 - por CRIANCAS MENORES DE 5 ANOS (0 = nao, 1 = sim):
 *     Array fixo de 2 listas pre-alocadas. Insercao e recuperacao O(1).
 *
 *   Criterio 5 - por FAIXA DE RENDA (1 a 4):
 *     Array fixo de 4 listas pre-alocadas.
 *     Faixa 1: ate R$2.000  | Faixa 2: R$2.000,01-3.000
 *     Faixa 3: R$3.000,01-5.000 | Faixa 4: acima de R$5.000
 *     Insercao e recuperacao O(1).
 *
 * A estrutura NAO e dona dos objetos Cliente; libera_estrutura() nao os destroi.
 */
#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include "lista.h"
#include "cliente.h"

/** Tamanho da tabela hash (primo para melhor distribuicao de indices). */
#define HASH_TAMANHO 101

typedef struct Estrutura Estrutura;

/**
 * Aloca e inicializa a estrutura com todos os indices vazios.
 * @return  Ponteiro para a estrutura criada, ou NULL em falha.
 */
Estrutura* cria_estrutura(void);

/**
 * Libera toda a memoria interna da estrutura (listas e entradas hash).
 * Os objetos Cliente NAO sao liberados.
 */
void libera_estrutura(Estrutura *estrutura);

/**
 * Insere o cliente no indice identificado pelo criterio.
 *
 * @param estrutura  Estrutura destino.
 * @param criterio   1=nome | 2=bairro | 3=pessoas | 4=criancas | 5=renda
 * @param cliente    Cliente a indexar (apenas o ponteiro e armazenado).
 */
void insere_cliente(Estrutura *estrutura, int criterio, Cliente *cliente);

/**
 * Recupera a lista de clientes conforme o criterio e complemento.
 *
 * @param estrutura   Estrutura de dados.
 * @param criterio    1=nome | 2=bairro | 3=pessoas | 4=criancas | 5=renda
 * @param complemento Para criterios 1 e 2: passar 0 (busca pelo parametro busca).
 *                    Para criterio  3: valor 1-5 (qtd de pessoas).
 *                    Para criterio  4: 0 = sem criancas; 1 = com criancas.
 *                    Para criterio  5: faixa 1-4.
 * @param busca       String de busca para criterios 1 e 2; NULL para os demais.
 *
 * @return  Ponteiro para a Lista interna correspondente (nunca NULL: se a chave
 *          nao existir, retorna uma lista vazia pre-alocada).
 *          O CHAMADOR NAO DEVE LIBERAR a lista retornada.
 */
Lista* recupera_cliente(Estrutura *estrutura, int criterio,
                        int complemento, char *busca);

#endif /* ESTRUTURA_H */
