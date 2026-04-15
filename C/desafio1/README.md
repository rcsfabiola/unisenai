# Desafio 1 — TAD Fila de Requisições de Saúde

## Descrição
Este projeto implementa um **Tipo Abstrato de Dados (TAD)** para gerenciar requisições de atendimento de saúde. As requisições chegam em ordem e são atendidas na mesma ordem — comportamento conhecido como **FIFO (First In, First Out)**, implementado por meio de uma **fila circular com array estático**.

## Estrutura do Projeto
desafio1/
├── requisicao.h     # Cabeçalho da estrutura de requisição
├── requisicao.c     # Implementação das funções de requisição
├── estrutura.h      # Cabeçalho do TAD Fila
├── estrutura.c      # Implementação do TAD Fila
└── teste.c          # Arquivo de teste fornecido pelo professor

## Estrutura de Dados
  ### Requisição (`requisicao.h`)
  Representa uma requisição de atendimento de saúde com os campos:
  | Campo                 | Tipo            | Tamanho           | Descrição |
  | `nomePaciente`        | `char[]`        | 40 caracteres     | Nome do paciente |
  | `codigoInscricao`     | `int`           | —                 | Código de inscrição no sistema de saúde |
  | `codigoProcedimento`  | `char[]`        | 10 caracteres     | Código do procedimento solicitado |

  ### Fila (`estrutura.h`)
  Fila circular com array estático de capacidade máxima de **1000 requisições**.
  | Campo     | Tipo            | Descrição |
  | `dados[]` | `Requisicao*[]` | Array de ponteiros para requisições |
  | `inicio`  | `int`           | Índice do primeiro elemento |
  | `fim`     | `int`           | Índice do próximo espaço livre |
  | `tamanho` | `int`           | Quantidade atual de requisições |

## Funções
  ### requisicao.h / requisicao.c
  ```c
  Requisicao* cria_requisicao(const char* nome, int inscricao, const char* procedimento);
  ```
  Cria e retorna uma nova requisição alocada dinamicamente.

  ```c
  const char* get_nome(Requisicao* r);
  int         get_inscricao(Requisicao* r);
  const char* get_procedimento(Requisicao* r);
  ```
  Retornam os dados da requisição.

  ```c
  void libera(Requisicao* r);
  ```
  Libera a memória alocada para a requisição.

  ### estrutura.h / estrutura.c
  ```c
  Estrutura* create();
  ```
  Cria e retorna uma nova fila alocada dinamicamente.

  ```c
  void inserir(Estrutura* e, Requisicao* r);
  ```
  Insere uma requisição no final da fila.

  ```c
  Requisicao* remover(Estrutura* e);
  ```
  Remove e retorna a requisição do início da fila (FIFO).

  ```c
  int get_size(Estrutura* e);
  ```
  Retorna a quantidade de requisições aguardando na fila.

  ```c
  void libera_estrutura(Estrutura* e);
  ```
  Libera a memória da fila e de todas as requisições ainda presentes nela.

---

## Compilação e Execução
bash

# 1. Compilar os módulos
gcc -c requisicao.c -o requisicao.o
gcc -c estrutura.c -o estrutura.o

# 2. Compilar e linkar com o arquivo de teste
gcc teste.c requisicao.o estrutura.o -o teste

# 3. Executar
./teste

---

## Complexidade
| Operação            | Complexidade |
| Inserção            |     O(1)     |
| Remoção             |     O(1)     |
| Consulta de tamanho |     O(1)     |

A fila circular com array garante que inserção e remoção sejam sempre realizadas em tempo constante, independentemente do número de requisições na fila — tornando esta a implementação de menor complexidade possível para o caso.

---

## Gerenciamento de Memória
- Cada requisição é alocada dinamicamente via `malloc` em `cria_requisicao`
- A fila armazena **ponteiros** para as requisições, evitando cópias desnecessárias
- `libera(r)` deve ser chamada após processar cada requisição removida
- `libera_estrutura(e)` libera automaticamente as requisições remanescentes na fila antes de liberar a própria estrutura