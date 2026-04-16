#!/bin/bash 

# Configurações
SHARED_DIR="$HOME/workspace/sistemas-computacionais/desafio/shared"
REPORTS_DIR="$HOME/workspace/sistemas-computacionais/desafio/var/reports"
DATE=$(date +%Y-%m-%d)
REPORT_FILE="$REPORTS_DIR/report_$DATE.txt"

# Verificar se o diretório shared existe
if [ ! -d "$SHARED_DIR" ]; then
    echo "Erro: Diretório $SHARED_DIR não existe"
    exit 1
fi

# Criar diretório de relatórios se não existir
if [ ! -d "$REPORTS_DIR" ]; then
 echo "Criando diretório $REPORTS_DIR..."
 sudo mkdir -p "$REPORTS_DIR"
 sudo chmod 755 "$REPORTS_DIR"
fi

# Criar o cabeçalho do relatório
echo "========================================" > "$REPORT_FILE"
echo "RELATÓRIO DIÁRIO DE ARQUIVOS MODIFICADOS" >> "$REPORT_FILE"
echo "Data: $(date '+%Y-%m-%d %H:%M:%S')" >> "$REPORT_FILE"
echo "========================================" >> "$REPORT_FILE"
echo "" >> "$REPORT_FILE"

# Contador de arquivos
count=0

# Buscar arquivos modificados ou criados nas últimas 24 horas
echo "Arquivos criados ou modificados nas últimas 24 horas:" >> "$REPORT_FILE"
echo "" >> "$REPORT_FILE"

# Na linha 54 usei o find para buscar arquivos modificados nas últimas 24 horas
# No macOS, -mtime -1 significa "menos de 24 horas atrás" (utilizado na linha 54)
while IFS= read -r filepath; do
    # Obter o subdiretório do projeto (primeiro nível dentro de /shared)
    projeto=$(basename "$(dirname "$filepath")")
    
    # Pular se não houver projeto (arquivo direto em /shared)
    if [ "$projeto" = "$(basename "$filepath")" ]; then
        projeto="[raiz]"
    fi
    
    # Adicionar ao relatório
    echo "Projeto: $projeto" >> "$REPORT_FILE"
    echo "Arquivo: $filepath" >> "$REPORT_FILE"
    echo "---" >> "$REPORT_FILE"
    
    ((count++))
done < <(find "$SHARED_DIR" -type f -mtime -1 2>/dev/null)

# Adicionar resumo
echo "" >> "$REPORT_FILE"
echo "========================================" >> "$REPORT_FILE"
echo "RESUMO" >> "$REPORT_FILE"
echo "========================================" >> "$REPORT_FILE"
echo "Total de arquivos modificados: $count" >> "$REPORT_FILE"
echo "" >> "$REPORT_FILE"

# Exibir mensagem de sucesso
echo "Relatório gerado com sucesso!"
echo "Arquivo: $REPORT_FILE"
echo "Total de arquivos encontrados: $count"

# Ajustar permissões do relatório
chmod 770 "$REPORT_FILE"

# Fim do script