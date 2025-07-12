// Aqui vai a implementacao do heapsort
// Rafael Pascoali
#include <iostream>
#include <vector>
using namespace std;

void max_heapfy(vector<int>& vec, int vec_size, int i) {
    // constroi o max heap usando o esquema que vimos em sala
    // não precisa fazer todo o rolê de transformar em árvore explicitamente
    // apenas verifica se o nó atual é maior que os filhos
    // ou seja, se o nó atual de índice i é maior que os nós de índice 2*i+1 e 2*i+2
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    // verifica se não esta fora do vetor
    // em seguida verifica se atende as condições de max heap
    // se não atender, faz o swap e chama recursivamente
    if (left < vec_size && vec[left] > vec[largest]) {
        largest = left;
    }
    if (right < vec_size && vec[right] > vec[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(vec[i], vec[largest]);
        max_heapfy(vec, vec_size, largest);
    }
}

void build_max_heap(vector<int>& vec) {
    //for pode parecer problemático, mas esse roda apenas uma vez
    for (int i = vec.size() / 2 - 1; i >= 0; i--) {
        max_heapfy(vec, vec.size(), i);
    }
}

void heapsort(vector<int>& vec) {
    // constrói o max heap inicial apenas uma vez, em seguida vai ajustando - 
    // - e fazendo os swaps de elementos
    build_max_heap(vec);
    // vai ajustando o max heap até todos os elementos estarem ordenados
    // primeiro faz o swap do primeiro elemento com o último
    // em seguida ajusta o max heap com o novo tamanho
    // repete até que o vetor esteja ordenado
    for (int i = vec.size() - 1; i > 0; i--) {
        swap(vec[0], vec[i]);
        max_heapfy(vec, i, 0);
    }
}

int main() {
    // ajustar para entrada em linha de comando para fazer os testes
    vector<int> vec = {9, 6, 10, 2, 7, 12, 11, 13, 12};
    heapsort(vec);

    cout << "Lista ordenada: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}