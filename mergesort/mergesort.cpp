#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> v, int left, int right){
    // transfere os elementos entre left e right para um array auxiliar
    int rightHelper = right - left;
    vector<int> helper(rightHelper + 1);
    for(int i = 0; i<= rightHelper; i++){
        helper[i] = v[left + i];
    }

    int middleHelper = rightHelper / 2;

    int i = 0, j = middleHelper + 1, k = left;

    while(i <= middleHelper && j <= rightHelper){
        if(helper[i] <= helper[j]){
            v[k] = helper[i];
            i++;
        } else {
            v[k] = helper[j];
            j++;
        }
        k++;
    }
    // se a metade inicial nao foi toda consumida, faz o append
    while(i <= middleHelper){
        v[k] = helper[i];
        i++;
        k++;
    }
}

void mergeSort(vector<int> v, int left, int right){
    if(left >= right){
        return;
    }else{
        int middle = (left + right) / 2;
        mergeSort(v, left, middle);
        mergeSort(v, middle + 1, right);
        merge(v, left, right);
    }
}

int main(){
    cout<< "Mergesort implementation" << endl;
    return 0;
}