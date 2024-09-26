#ifndef GULOSOMENORCAMINHO_H
#define GULOSOMENORCAMINHO_H

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class gulosoMenorCaminho {
private:
    int size;
    vector<vector<int>> matrizAdjacencia;
    vector<int> solucao;

public:
    explicit gulosoMenorCaminho(const string& endereco);

    int calculaSolucao(const int inicio);

    vector<int> *getSolucao();
};

#endif