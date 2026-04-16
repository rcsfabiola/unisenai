# 🅿️ ParkControl — Sistema de Controle de Estacionamento

Projeto desenvolvido para a disciplina de **Desenvolvimento Web**, com foco na construção de um front-end funcional utilizando exclusivamente **HTML, CSS e JavaScript puro** — sem frameworks ou bibliotecas externas.

---

## 📋 Funcionalidades

### Tela 1 — Cadastro de Reserva
- Formulário completo com os campos: placa do veículo, nome do proprietário, número e bloco do apartamento, modelo, cor e número da vaga
- Validação de todos os campos antes de salvar, com mensagens de erro inline
- Validação de placa nos formatos **antigo** (`ABC-1234`) e **Mercosul** (`ABC1D23`) via expressão regular
- Verificação se a vaga selecionada existe e está disponível
- Ao salvar: exibe `console.log` com os dados, abre pop-up de confirmação e persiste as informações no `localStorage`

### Tela 2 — Listagem de Vagas
- Exibe todas as **30 vagas** do estacionamento, organizadas por andar (Térreo, 1º Subsolo, 2º Subsolo)
- Cards de estatísticas em tempo real: total, disponíveis e ocupadas
- Vagas coloridas por status: 🟢 livre / 🔴 ocupada
- Vagas ocupadas exibem a placa e um tooltip com os dados completos da reserva ao passar o mouse
- **Liberar vaga:** clique em uma vaga ocupada e confirme a liberação — a vaga volta a ficar disponível
- **Transferir reserva:** mova um veículo para outra vaga disponível diretamente pelo modal, sem precisar recadastrar

---

## 📖 Como Usar

### 1 — Cadastrar Veículo

1. No menu superior, clique em **Cadastrar**
2. Preencha os dados do veículo:
   - **Placa** — formato antigo (`ABC-1234`) ou Mercosul (`ABC1D23`)
   - **Modelo** — ex: Honda Civic
   - **Cor** — selecione na lista
3. Preencha os dados do proprietário:
   - **Nome completo**
   - **Número do apartamento** — ex: 301
   - **Bloco** — selecione na lista (A a E)
4. Selecione a **vaga de estacionamento** desejada entre as disponíveis
5. Clique em **Salvar Reserva**
   - Se algum campo estiver incorreto, uma mensagem de erro aparece abaixo do campo
   - Se tudo estiver certo, um pop-up confirma o cadastro com um resumo das informações

> A vaga escolhida passa imediatamente a aparecer como **ocupada** na tela de listagem.

---

### 2 — Manutenção de Vagas

1. No menu superior, clique em **Listar Vagas**
2. Localize a vaga desejada no mapa — vagas ocupadas aparecem em **vermelho**
3. Clique sobre a vaga ocupada para abrir o painel de ações
4. O painel exibe os dados completos da reserva (proprietário, veículo, placa, apartamento e data)
5. Escolha uma das ações disponíveis:

**Liberar vaga**
- Clique em **✕ Liberar esta vaga**
- Confirme a ação na janela de confirmação
- A vaga volta a ficar **disponível** (verde) imediatamente

**Transferir para outra vaga**
- Clique em **⇄ Transferir para outra vaga**
- Um campo aparece listando todas as vagas livres disponíveis
- Selecione a vaga de destino e clique em **✔ Confirmar Transferência**
- A vaga antiga é liberada e a nova fica ocupada com os mesmos dados da reserva

> Em ambos os casos, uma mensagem de confirmação aparece na parte inferior da tela e as alterações são salvas automaticamente.

---

## 🗂️ Estrutura do Projeto

```
estacionamento.html   ← arquivo único com HTML, CSS e JavaScript
README.md
```

O projeto é composto por um único arquivo HTML, mantendo toda a lógica, estilos e marcação centralizada — conforme exigido pela proposta (sem frameworks).

---

## 🛠️ Tecnologias Utilizadas

| Tecnologia | Uso |
|---|---|
| HTML5 | Estrutura e semântica das telas |
| CSS3 | Estilização, animações e layout responsivo |
| JavaScript (ES6+) | Lógica, validação, manipulação do DOM e persistência |
| LocalStorage | Armazenamento dos dados no navegador |
| Google Fonts | Tipografia (Bebas Neue, DM Sans, DM Mono) |

Nenhum framework de JavaScript (React, Vue, Angular) ou CSS (Bootstrap, Tailwind) foi utilizado — trata-se de **Vanilla JS/CSS** puro.

---

## 💾 Persistência de Dados (LocalStorage)

Os dados são salvos em duas chaves no `localStorage` do navegador:

- `parkcontrol_vagas` — objeto com o estado de todas as 30 vagas (status e dados da reserva)
- `parkcontrol_reservas` — array com o histórico de todas as reservas cadastradas

Os dados persistem entre sessões: ao recarregar a página, o mapa de vagas reflete o último estado salvo.

---

## 🅿️ Vagas Disponíveis

As vagas são definidas de forma estática no código, totalizando **30 vagas** distribuídas em 3 andares:

| Andar | Vagas |
|---|---|
| Térreo | 1 a 10 |
| 1º Subsolo | 11 a 20 |
| 2º Subsolo | 21 a 30 |

---

## ▶️ Como Executar

Basta abrir o arquivo `estacionamento.html` diretamente no navegador — não é necessário servidor, instalação ou configuração.

```bash
# Opção 1: abrir direto pelo explorador de arquivos
# Clique duplo em estacionamento.html

# Opção 2: via terminal
open estacionamento.html        # macOS
start estacionamento.html       # Windows
xdg-open estacionamento.html    # Linux
```

---

## 📐 Conceitos de JavaScript Demonstrados

- **Manipulação do DOM** — `getElementById`, `querySelector`, `createElement`, `innerHTML`
- **Eventos** — `addEventListener` para submit, click e interações do usuário
- **Validação com Regex** — verificação de formato de placa veicular
- **LocalStorage API** — `getItem`, `setItem` e `JSON.parse` / `JSON.stringify`
- **Funções puras e separação de responsabilidades** — cada função tem uma única responsabilidade
- **Template literals** — geração dinâmica de HTML via strings interpoladas
- **Spread operator e array methods** — `filter`, `forEach`, `findIndex`, `flat`

---

## 🎨 Decisões de Design

- Tema escuro com paleta de alto contraste para facilitar a leitura do mapa de vagas
- Código de cores consistente: amarelo para destaques, verde para livre, vermelho para ocupado
- Layout responsivo adaptado para telas menores via media queries
- Feedback visual em todas as interações: bordas de erro, toasts de confirmação e animações de entrada