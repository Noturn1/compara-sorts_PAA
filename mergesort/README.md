# Merge Sort

Algoritmo de ordenação eficiente que utiliza o paradigma **dividir e conquistar**.

---

## Sumário

1. [Visão geral](#visão-geral)  
2. [Funcionamento do *merge*](#funcionamento-do-merge)  
3. [Algoritmo completo](#algoritmo-completo)  
4. [Complexidade](#complexidade)  
5. [Uso de memória](#uso-de-memória)  
6. [Propriedades](#propriedades)  

---

## Visão geral

- Merge Sort é um algoritmo de **ordenação por comparação**, com complexidade de tempo **Θ(n log n)** nos casos **melhor**, **pior** e **médio**, pois divide sempre pela metade :contentReference[oaicite:1]{index=1}.
- Utiliza a técnica **"dividir e conquistar"**:  
  1. Divide o array até obter subarrays de tamanho 1  
  2. Conquista: executa o `merge` para juntar subarrays ordenados :contentReference[oaicite:2]{index=2}

---

## Funcionamento do *merge*

O `merge` combina duas metades ordenadas de um mesmo array em uma sequência ordenada:

1. Copia os elementos do segmento `[left..right]` para um **array auxiliar** `helper` :contentReference[oaicite:3]{index=3}.
2. Define índices:
   - `i = 0` (início da primeira metade),
   - `j = middleHelper + 1` (segunda metade),
   - `k = left` (posição no array original).
3. Percorre `helper`, comparando `helper[i]` e `helper[j]`:
   - Insere o menor em `v[k]` e avança `i` ou `j`, além de `k`.
4. Ao término, copia a parte restante da primeira metade, se houver :contentReference[oaicite:4]{index=4}.

### Código em Java (trecho simplificado):
```java
public void merge(int[] v, int left, int right) {
    int rightHelper = right - left;
    int[] helper = new int[rightHelper + 1];
    for (int t = 0; t <= rightHelper; t++) helper[t] = v[left + t];
    int middleHelper = rightHelper / 2;
    int i = 0, j = middleHelper + 1, k = left;
    while (i <= middleHelper && j <= rightHelper)
        v[k++] = (helper[i] <= helper[j]) ? helper[i++] : helper[j++];
    while (i <= middleHelper) v[k++] = helper[i++];
}
```