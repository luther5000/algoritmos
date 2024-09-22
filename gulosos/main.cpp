#include <iostream>
#include <fstream>
#include <vector>

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

int main() {
    string endereco;
    int inicio;

    cin >> endereco;
    cin >> inicio;

    guloso_menor_caminho guloso1(endereco);

    cout << guloso1.calculaSolucao(inicio);
    return 0;
}
