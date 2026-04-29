/**
 * cliente.h
 * TAD: Cliente para cadastro orientado a acoes de marketing.
 *
 * Campos:
 *   nome     - string de exatamente 40 caracteres uteis (array de 41 bytes)
 *   bairro   - string de exatamente 40 caracteres uteis (array de 41 bytes)
 *   pessoas  - inteiro: quantidade de pessoas na residencia (1-5; 5=cinco ou mais)
 *   criancas - booleano: possui criancas menores de 5 anos (true/false)
 *   renda    - double: renda familiar bruta em R$
 *
 * Faixas de renda internas (usadas pela estrutura hash):
 *   1 - ate R$ 2.000,00
 *   2 - de R$ 2.000,01 ate R$ 3.000,00
 *   3 - de R$ 3.000,01 ate R$ 5.000,00
 *   4 - acima de R$ 5.000,00
 */
#ifndef CLIENTE_H
#define CLIENTE_H

#include <stdbool.h>

/**
 * Comprimento maximo do conteudo das strings nome e bairro (40 caracteres uteis).
 * Os arrays internos sao declarados com CLIENTE_STR_MAX + 1 para incluir o '\0'.
 */
#define CLIENTE_STR_MAX 40

typedef struct Cliente Cliente;

/**
 * Aloca e inicializa um novo cliente.
 * @param nome     Nome (max 40 chars).
 * @param bairro   Bairro de moradia (max 40 chars).
 * @param pessoas  Qtd de pessoas na residencia; valores > 5 sao normalizados para 5.
 * @param criancas true/1 = tem criancas menores de 5 anos; false/0 = nao tem.
 * @param renda    Renda familiar bruta em R$.
 * @return         Ponteiro para o cliente criado, ou NULL em falha.
 */
Cliente* cria_cliente(const char *nome, const char *bairro,
                      int pessoas, int criancas, double renda);

/** Libera a memoria do cliente. */
void     libera_cliente(Cliente *cliente);

/** Retorna o nome do cliente. */
char*    get_nome(Cliente *cliente);

/** Retorna o bairro do cliente. */
char*    get_bairro(Cliente *cliente);

/** Retorna a quantidade de pessoas na residencia (1-5). */
int      get_pessoas(Cliente *cliente);

/** Retorna true se tem criancas menores de 5 anos, false caso contrario. */
bool     get_criancas(Cliente *cliente);

/** Retorna a renda familiar bruta. */
double   get_renda(Cliente *cliente);

/**
 * Retorna a faixa de renda (1 a 4) conforme os intervalos definidos no TAD.
 * Usada internamente por estrutura.c para indexar o array de listas de renda.
 */
int      get_faixa_renda(Cliente *cliente);

#endif /* CLIENTE_H */
