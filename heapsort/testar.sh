
#Mudar aqui os diretorios onde estão os CSV e o executável do sort
#Assume que os arquivos CSV ja existem no diretório especificado
DIRETORIO_PAI_DADOS="/home/rafael/Desktop/quarto_ano/PAA/compara-sorts_PAA/dados"
DIRETORIO_CSV="/home/rafael/Desktop/quarto_ano/PAA/compara-sorts_PAA/heapsort/CSV"
EXECUTAVEL="/home/rafael/Desktop/quarto_ano/PAA/compara-sorts_PAA/heapsort/heapsort"

DIRETORIOS_DADOS=(
    "$DIRETORIO_PAI_DADOS/Decrescentes"
    "$DIRETORIO_PAI_DADOS/Ordered Files"
    "$DIRETORIO_PAI_DADOS/Partially Ordered"
    "$DIRETORIO_PAI_DADOS/Random Files"
)
for i in {1..6}; do
    for DIRETORIO in "${DIRETORIOS_DADOS[@]}"; do
        ARQUIVOS=($(ls -v "$DIRETORIO"))
        for FILE in "${ARQUIVOS[@]}"; do
            # basename retorna o nome do diretório sem o caminho
            # tr -d ' ' remove espaços do nome do diretório
            # Bash não gosta de espaços em nomes de arquivos, então é melhor removê-los
            "$EXECUTAVEL" "$DIRETORIO/$FILE" "$DIRETORIO_CSV/$(basename "$DIRETORIO" | tr -d ' ').csv"
        done
    done
done
