#include <iostream>
#include <fstream>
#include <vector>
#include <list>

using namespace std;

class guloso_menor_caminho {
private:
    int size;
    vector<vector<int>> matrizAdjacencia;
    vector<int> solucao;

public:
     explicit guloso_menor_caminho(const string& endereco) {
        ifstream file(endereco);

         if (!file.is_open()) {
             std::cerr << "Erro ao abrir o arquivo." << std::endl;
             return;
         }

        file >> size;
        matrizAdjacencia.resize(size);
        solucao.resize(size + 1);

        for (int i = 0; i < size; ++i) {
            matrizAdjacencia[i].resize(size);

            for (int j = 0; j < size; ++j) {
                file >> matrizAdjacencia[i][j];
            }
        }
        file.close();
    }

    int calculaSolucao(const int inicio) {
         int i = inicio;
         solucao[0] = inicio;
         int custo = 0;

         vector<bool> visitou(size);
         for (int k = 0; k < size; ++k)
             visitou[k] = false;

        for (int k = 0; k < size; ++k) {
            int j = 0;
            int indiceMenorValor = -1;
            while (j < size) {
                if (indiceMenorValor < 0 || !visitou[j] &&
                    matrizAdjacencia[i][j] < matrizAdjacencia[i][indiceMenorValor]) {
                    indiceMenorValor = j;
                }
                ++j;
            }
            solucao[k + 1] = indiceMenorValor;
            custo += matrizAdjacencia[i][indiceMenorValor];

            i = indiceMenorValor;
        }
         return custo;
    }

    vector<int> *getSolucao() {
         return &solucao;
     }
};

class gulosoInsercaoMaisBarata{
private:
    int size;
    list<int> solucao;
    vector<vector<int>> matrizAdjacencia;

public:

    gulosoInsercaoMaisBarata(string endereco){
        ifstream file(endereco);
         if (!file.is_open()) {
             std::cerr << "Erro ao abrir o arquivo." << std::endl;
             return;
         }

        file >> size;
        matrizAdjacencia.resize(size);

        for (int i = 0; i < size; ++i) {
            matrizAdjacencia[i].resize(size);

            for (int j = 0; j < size; ++j) {
                file >> matrizAdjacencia[i][j];
            }
        }
        file.close();
    }

    int calculaSolucao(int inicio1, int inicio2, int inicio3){
        solucao.push_back(inicio1);
        solucao.push_back(inicio2);
        solucao.push_back(inicio3);

        vector<bool> visitou(size);
        for (int i = 0; i < size; ++i){
            visitou[i] = false;
        }
        visitou[inicio1] = true;
        visitou[inicio2] = true;
        visitou[inicio3] = true;

        for (int i = 0; i < size - 3; ++i){
            int i_menorCusto = -1;
            int j_menorCusto = -1;
            for (int j : solucao){
                
                if (j != solucao.size() - 1){
                    for (int k = 0; k < size; ++k){
                        if (i_menorCusto == -1 || !visitou[k] &&
                                matrizAdjacencia[])
                    }
                }
            }
        }
    }
    
};


int main() {
    string endereco;
    int inicio;

    cin >> endereco;
    cin >> inicio;

    guloso_menor_caminho guloso1(endereco);

    cout << guloso1.calculaSolucao(inicio);
    return 0;
}
