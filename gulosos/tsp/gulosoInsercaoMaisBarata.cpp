#include "gulosoInsercaoMaisBarata.hpp"

    gulosoInsercaoMaisBarata::gulosoInsercaoMaisBarata(string endereco){
        ifstream file(endereco);
         if (!file.is_open()) {
             std::cerr << "Erro ao abrir o arquivo." << std::endl;
             return;
         }

        file >> size;
        matrizAdjacencia.resize(size);
        solucao.resize(size);

        for (int i = 0; i < size; ++i) {
            matrizAdjacencia[i].resize(size);

            for (int j = 0; j < size; ++j) {
                file >> matrizAdjacencia[i][j];
            }
        }
        file.close();
    }

    int gulosoInsercaoMaisBarata::calculaSolucao(int inicio1, int inicio2, int inicio3){
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
            int i_atual = -1;
            int j_atual = -1;
            int indexNovo = -1;

            int menorValor = -1;

            for (int j = 0; j < solucao.size(); ++j){ 
                for (int k = 0; k < size; ++k){
                    if (!visitou[k]){
                        if (j != solucao.size() - 1) {
                            int valorAtual = matrizAdjacencia[solucao[j]][k] + matrizAdjacencia[k][solucao[j+1]] - 
                                matrizAdjacencia[solucao[j]][solucao[j+1]];

                            if (i_atual == -1 ||
                                valorAtual < menorValor) {
                                i_atual = solucao[j];
                                j_atual = solucao[j+1];
                                indexNovo = k;
                                menorValor = valorAtual;
                            }
                        } else{
                                int valorAtual = matrizAdjacencia[solucao[j]][k] + matrizAdjacencia[k][solucao[0]] - 
                                matrizAdjacencia[solucao[j]][solucao[0]];

                            if (i_atual == -1 || !visitou[k] &&
                                valorAtual < menorValor) {
                                i_atual = solucao[j];
                                j_atual = solucao[0];
                                indexNovo = k;
                                menorValor = valorAtual;
                            }
                        }
                    }
                }
            }

            if (i_atual > j_atual){
                solucao.insert(solucao.begin() + i_atual+ 1, indexNovo);
            } else
                solucao.push_back(indexNovo);

            visitou[indexNovo] = true;
        }

        int valorSolucao = 0;
        for (int i = 0; i < size; ++i){
            if (i != size - 1){
                valorSolucao += matrizAdjacencia[solucao[i]][solucao[i+1]];
            } else{
                valorSolucao += matrizAdjacencia[solucao[i]][solucao[0]];
            }
        }
        return valorSolucao;

    }