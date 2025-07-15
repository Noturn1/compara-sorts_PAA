# Merge Sort em C++

Implementação do algoritmo de ordenação **Merge Sort** utilizando C++ e o paradigma **dividir e conquistar**.

---

## Sumário

- [Merge Sort em C++](#merge-sort-em-c)
  - [Sumário](#sumário)
  - [Visão geral](#visão-geral)
  - [Funcionamento do `merge`](#funcionamento-do-merge)

---

## Visão geral

- O **Merge Sort** é um algoritmo de **ordenação por comparação**, com complexidade de tempo **Θ(n log n)** nos casos **melhor**, **médio** e **pior**, pois sempre divide o vetor em duas partes recursivamente.
- Segue o princípio de **"dividir e conquistar"**:
  1. Divide o vetor original em subvetores menores até que cada subvetor tenha apenas um elemento.
  2. Conquista: utiliza a função `merge` para combinar os subvetores ordenados de forma eficiente.

---

## Funcionamento do `merge`

A função `merge` combina duas metades ordenadas de um vetor em uma única sequência ordenada.

Passos:

1. Os elementos do intervalo `[left..right]` são copiados para um vetor auxiliar `helper`.
2. Índices são definidos:
   - `i = 0` (início da primeira metade)
   - `j = middleHelper + 1` (início da segunda metade)
   - `k = left` (posição de escrita no vetor original)
3. Os elementos das duas metades são comparados e inseridos ordenadamente no vetor original.
4. Se restarem elementos na primeira metade, eles são copiados.

Trecho da implementação em C++:
```cpp
void merge(vector<int>* v, int left, int right){
    int rightHelper = right - left;
    vector<int> helper(rightHelper + 1);
    for(int i = 0; i<= rightHelper; i++){
        helper[i] = (*v)[left + i];
    }
    int middleHelper = rightHelper / 2;
    int i = 0, j = middleHelper + 1, k = left;
    while(i <= middleHelper && j <= rightHelper){
        if(helper[i] <= helper[j]){
            (*v)[k] = helper[i];
            i++;
        } else {
            (*v)[k] = helper[j];
            j++;
        }
        k++;
    }
    while(i <= middleHelper){
        (*v)[k] = helper[i];
        i++;
        k++;
    }
}

void mergeSort(vector<int>* v, int left, int right){
    if(left >= right){
        return;
    }else{
        int middle = (left + right) / 2;
        mergeSort(v, left, middle);
        mergeSort(v, middle + 1, right);
        merge(v, left, right);
    }
}
```