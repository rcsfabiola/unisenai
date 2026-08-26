# API de Gerenciamento de Destinos de Viagem

Desafio da Unidade Curricular **Desenvolvimento de Sistemas Web** (SENAI) —
*Planejamento da arquitetura e desenvolvimento inicial de API REST*.

## 1. Visão geral do problema

Uma agência de viagens quer modernizar seus serviços digitais e disponibilizar
uma **API REST** para gerenciar informações sobre **destinos turísticos**
(nome, localização, descrição, disponibilidade de hotéis, atividades e
avaliações), permitindo que ela seja integrada futuramente a aplicativos de
turismo e parceiros comerciais.

Nesta primeira etapa, o foco é a **arquitetura da solução** e a construção
dos *endpoints* principais. Não há integração com banco de dados real nem
mecanismos avançados de segurança — os dados ficam armazenados em memória
enquanto a aplicação está rodando.

## 2. Arquitetura proposta

A aplicação segue uma **arquitetura em camadas**, com responsabilidades bem
separadas:

Cliente (Postman, curl, app de turismo...)
  -> requisição HTTP ->
Controller — recebe a requisição, valida o formato e devolve a resposta
  -> chama ->
Service — contém as regras de negócio (buscar, filtrar, calcular média de avaliações, etc.)
  -> manipula ->
Model / Entity — representa o "Destino" e guarda os dados em memória

- **`controller/`** — `DestinoController`: expõe os endpoints REST, traduz
  HTTP em chamadas Java e devolve as respostas em JSON.
- **`service/`** — `DestinoService`: contém toda a lógica de negócio e o
  "banco de dados em memória" (um `Map`, já que o desafio não exige
  persistência real).
- **`model/`** — `Destino` (entidade) e `AvaliacaoRequest` (um pequeno DTO
  usado só para receber a nota de uma avaliação).
- **`exception/`** — tratamento de erros centralizado (`404` quando um
  destino não existe, `400` quando os dados enviados são inválidos).

### Por que essa separação?

Manter o Controller "burro" (só traduz HTTP) e o Service "inteligente" (só
regra de negócio) facilita testar, dar manutenção e, no futuro, trocar o
armazenamento em memória por um banco de dados real sem precisar mexer no
Controller.

## 3. Por que Java + Spring Boot?

- **Java** é fortemente tipado e amplamente usado no mercado corporativo,
  com grande comunidade e documentação — reduz erros e facilita manutenção
  em times maiores (útil pensando na integração com parceiros comerciais
  citada no desafio).
- **Spring Boot** foi escolhido porque:
  - Oferece um servidor web embutido (Tomcat), então não é preciso
    configurar infraestrutura para começar a testar a API.
  - Simplifica drasticamente a criação de endpoints REST com anotações
    (`@RestController`, `@GetMapping`, etc.), reduzindo código repetitivo.
  - Usa **Injeção de Dependência**/**Inversão de Controle** nativamente, o
    que deixa as camadas desacopladas (o Controller não cria o Service, ele
    apenas "recebe" um pronto pelo próprio Spring).
  - É o caminho natural de evolução: quando a agência decidir integrar um
    banco de dados de verdade, basta adicionar Spring Data JPA à camada de
    Service/Repository, sem reescrever o Controller.
  - **Spring Validation** foi incluído para validar os dados de entrada
    (ex.: impedir cadastrar um destino sem nome, ou uma avaliação fora da
    faixa de 1 a 5) de forma declarativa, evitando `if`s espalhados pelo
    código.
- O projeto foi gerado com o **Spring Initializr**, a ferramenta oficial
  para criar projetos Spring Boot, garantindo uma estrutura Maven padrão e
  confiável desde o início.

## 4. Endpoints da API

Prefixo base: `/api/destinos`

| Método | Rota | Descrição |
|---|---|---|
| `POST` | `/api/destinos` | Cadastra um novo destino |
| `GET` | `/api/destinos` | Lista todos os destinos |
| `GET` | `/api/destinos/buscar?nome=&localizacao=` | Pesquisa por nome e/ou localização (parâmetros opcionais) |
| `GET` | `/api/destinos/{id}` | Detalha um destino específico |
| `PUT` | `/api/destinos/{id}` | Atualiza os dados cadastrais de um destino |
| `PATCH` | `/api/destinos/{id}/avaliacoes` | Registra uma nova avaliação (recalcula a média) |
| `DELETE` | `/api/destinos/{id}` | Exclui um destino |

### Exemplo — cadastrar um destino

curl -X POST http://localhost:8080/api/destinos \
  -H "Content-Type: application/json" \
  -d '{
    "nome": "Bonito",
    "localizacao": "Mato Grosso do Sul, Brasil",
    "descricao": "Ecoturismo, rios cristalinos e grutas",
    "hoteisDisponiveis": 8,
    "atividadesTuristicas": ["Flutuação no Rio da Prata", "Gruta do Lago Azul"]
  }'

### Exemplo — registrar uma avaliação

curl -X PATCH http://localhost:8080/api/destinos/3/avaliacoes \
  -H "Content-Type: application/json" \
  -d '{ "nota": 5 }'

A resposta traz a lista de `avaliacoes` atualizada e `mediaAvaliacoes`
recalculada automaticamente.

### Exemplo — pesquisar

curl "http://localhost:8080/api/destinos/buscar?localizacao=santa%20catarina"

### Erros

- Buscar/atualizar/avaliar/excluir um `id` que não existe → `404 Not Found`
  com uma mensagem explicando o problema.
- Enviar dados inválidos (ex.: destino sem nome, nota fora de 1–5) →
  `400 Bad Request` com a lista de campos inválidos.

## 5. Como executar o projeto

Pré-requisitos: **JDK 17+** e **Maven** (o projeto já inclui o Maven
Wrapper, então não é obrigatório ter o Maven instalado separadamente).

cd agencia-viagens-api
./mvnw spring-boot:run

A API sobe em `http://localhost:8080`. A aplicação já nasce com 2 destinos
de exemplo cadastrados (Florianópolis e Gramado), para facilitar os
primeiros testes.

### Testando

Você pode testar com `curl` (como nos exemplos acima) ou com o **Postman**:

curl http://localhost:8080/api/destinos

## 6. Próximos passos (fora do escopo deste desafio)

- Persistir os dados em um banco real com Spring Data JPA.
- Adicionar autenticação/autorização (JWT, Spring Security).
- Adicionar paginação na listagem de destinos, caso a lista cresça muito.