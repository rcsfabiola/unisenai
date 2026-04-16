-----------------------------------------------------
1 - Gerenciamento de permissões de diretórios
-----------------------------------------------------
Script manage_permissions.sh:
• Ficará armazenado no diretório /shared.
• Valida se foram passados no mínimo dois argumentos: PROJETO (nome); USUARIO (obrigatóriamente 1 ou mais usuários). Do contrário, exibirá mensagem de erro e não executará o processamento.
• Cria um GRUPO de usuários com o mesmo nome do PROJETO. Este grupo terá um ID próprio gerado automaticamente utilizando timestamp.
• Permite a integração de novos usuários. 
• Configura as permissões de acesso do grupo de cada projeto.
• Lista todos os usuários de cada grupo.

1.1 Estrutura de retorno do script:
➜  desafio git:(main) ✗ ./manage_permissions.sh Fabiola4 Pedro Maria Carolina               -----Entrada de dados
4650                                                                                        -----ID gerado automaticamente
projeto: Fabiola4                                                                           -----primeiro argumento = nome do projeto
usuarios: Pedro Maria Carolina                                                              -----segundo arhumento: usuários do grupo
Password:                                                                                   -----senha do sistema
dsAttrTypeNative:record_daemon_version: 9480000                                             
AppleMetaNodeLocation: /Local/Default
GeneratedUID: 2E9AD215-BABE-4C92-8617-D0881C863548
PrimaryGroupID: 4650                                                                        -----ID
RecordName: Fabiola4
RecordType: dsRecTypeStandard:Groups
Pedro
Maria
Carolina
GroupMembership: Pedro Maria Carolina                                                       -----Usuários do grupo
Permissões definidas para o diretório Fabiola4                                              -----Diretório de permissões
drwxr-S---  2 fabiolasilva  Fabiola4  64  4 out 18:50 ./Fabiola4                            -----Permissões do grupo

----------------------------------------------------
2 - Relatório diário de arquivos modificados
----------------------------------------------------
Script daily_report.sh:
• Gera relatório com a lista de todos os arquivos do diretório /shared que foram criados ou modificados nas últimas 24 horas.
• Verifica se o diretório /shared existe, se não existir, é criado.
• Cria e salva o arquivo com o nome report_YYYY-MM-DD.txt no diretório /var/reports, onde YYYY-MM-DD corresponde à data atual.
• O relatório contém cabeçalho com data e hora, lista o arquivo e seu projeto e finaliza com o total de arquivos.

2.1 Estrutura de retorno do script:
========================================
RELATÓRIO DIÁRIO DE ARQUIVOS MODIFICADOS
Data: 2025-10-04 20:08:55
========================================

Arquivos criados ou modificados nas últimas 24 horas:

Projeto: fabiola34
Arquivo: /Users/fabiolasilva/workspace/sistemas-computacionais/desafio/shared/fabiola34/wilson.txt
---
Projeto: fabiola35
Arquivo: /Users/fabiolasilva/workspace/sistemas-computacionais/desafio/shared/fabiola35/ola.txt
---
Projeto: fabiola35
Arquivo: /Users/fabiolasilva/workspace/sistemas-computacionais/desafio/shared/fabiola35/oi.txt
---

========================================
RESUMO
========================================  
Total de arquivos modificados: 3

-----------------------------------------------------
3 - Estrutura de Diretórios
-----------------------------------------------------
~/workspace/sistemas-computacionais/desafio/
├── shared/                   # Diretório compartilhado dos projetos
│   ├── fabiola/              # Projeto fabiola
│   ├── fabiola1/             # Projeto fabiola1
│   └── fabiola2/             # Projeto fabiola2
│       └── [arquivos]
├── var/
│   └── reports/              # Diretório de relatórios
│       ├── report_2025-10-04.txt
│       └── report_2025-10-05.txt
├── manage_permissions.sh     # Script de gerenciamento de grupos
└── daily_report.sh           # Script de relatório diário

-----------------------------------------------------
4 - Requisitos do Sistema
-----------------------------------------------------
• Sistema Operacional macOS (testado em versões recentes)
• Bash (pré-instalado no macOS)
• dscl - Directory Service Command Line (pré-instalado) - equivalente ao dseditgroup no Linux

📄 Licença
Scripts criados para fins educacionais - Sistema Computacionais

✍️ Autor
Fabiola Silva - Projeto de Sistemas Computacionais
Última atualização: 04/10/2025