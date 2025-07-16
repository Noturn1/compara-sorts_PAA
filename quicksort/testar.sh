
#Mudar aqui os diretorios onde estão os CSV e o executável do sort
#Assume que os arquivos CSV ja existem no diretório especificado
DIRETORIO_PAI_DADOS="/Users/arthur-silva/faculdade/paa/compara-sorts_PAA/dados"
DIRETORIO_CSV="/Users/arthur-silva/faculdade/paa/compara-sorts_PAA/quicksort/CSV"
EXECUTAVEL="/Users/arthur-silva/faculdade/paa/compara-sorts_PAA/quicksort/quicksort"

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

echo "Testes do Quicksort finalizados. Resultados em: $DIRETORIO_CSV"
