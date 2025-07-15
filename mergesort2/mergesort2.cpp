#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

int escreve_csv(int numero_entradas, double tempo_ms,char* arquivo_csv) {
    // escreve os dados no arquivo csv
    cout<< "Escrevendo no arquivo CSV: " << arquivo_csv << endl;
    FILE* file = fopen(arquivo_csv, "a");
    if (!file) {
        cout << "Erro ao abrir o arquivo CSV." << endl;
        return 1;
    }
    fprintf(file, "%d,%.2f\n", numero_entradas, tempo_ms);
    fclose(file);
    return 0;
}



void printVector(const vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void merge(vector<int>* v, int left, int right){
    // transfere os elementos entre left e right para um array auxiliar
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
    // se a metade inicial nao foi toda consumida, faz o append
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

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Uso: " << argv[0] << " <caminho_arquivo_teste> <arquivo_csv>" << endl;
        return 1;
    }
    vector<int> vec;
    int valor;
    char* nome_arquivo_entradas = argv[1];
    char* arquivo_csv = argv[2];
    int numero_entradas = 0;
    FILE* arquivo_entradas = fopen(nome_arquivo_entradas, "r");
    if (!arquivo_entradas) {
        cout << "Erro ao abrir o arquivo: " << nome_arquivo_entradas << endl;
        return 1;
    }
    while (fscanf(arquivo_entradas, "%d", &valor) != EOF) {
        numero_entradas++;
        vec.push_back(valor);
    }
    fclose(arquivo_entradas);
    //mergeSort(&vec, 0, vec.size() -1);
    //cout << "Lista ordenada: ";
    //printVector(vec);
    clock_t start = clock();
    mergeSort(&vec, 0, vec.size() -1);
    clock_t end = clock();
    double tempo_ms = 1000.0 * double(end - start) / CLOCKS_PER_SEC;
    escreve_csv(numero_entradas, tempo_ms, arquivo_csv);
    return 0;

    /*
    fs::path path = "../dados";

    cout << "Current path: " << path << endl;
    for (const auto& entry : fs::recursive_directory_iterator(path)) {
        if(fs::is_directory(entry)){
            cout << "Directory: " << entry.path() << endl;
            ofstream outputFile(fs::current_path() /(entry.path().filename().string() + "_output.csv"));
            if (!outputFile) {
                cerr << "Error creating output file." << endl;
                return 1;
            }
            outputFile << entry.path().filename().string() <<"\n"<<"File\tTime\n";
            for(const auto& file : fs::directory_iterator(entry.path())) {
                if(fs::is_regular_file(file)) {
                    cout << "File: " << file.path() << endl;
                    ifstream inputFile(file.path());
                    if (inputFile.is_open()) {
                        cout << "Reading file: " << file.path() << endl;
                        vector<int> vec;
                        string line;
                        while (getline(inputFile, line)) {
                            numero_entradas++;
                            vec.push_back(stoi(line));
                        }
                        inputFile.close();
                        auto startTime = chrono::high_resolution_clock::now();
                        //cout << "starttime: " << startTime << endl;
                        mergeSort(&vec, 0, vec.size() - 1);
                        auto endTime = chrono::high_resolution_clock::now();
                        //cout << "endtime: " << endTime << endl;
                        chrono::duration<double> duration = endTime - startTime;
                        outputFile << file.path().stem()<<"\t"<< duration.count() <<"\n";
                    } else {
                        cout << "Failed to open file: " << file.path() << endl;
                    }
                }
                // Este break impede a iterações sobre os arquivos dos subdiretórios.
                //break;
            }
            outputFile.close();
        }
        // Este break impede a iterações sobre os subdiretórios. 
        //break;
    }*/

}