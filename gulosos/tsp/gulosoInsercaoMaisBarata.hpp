#ifndef GULOSOINSERCAOMAISBARATA_H
#define GULOSOINSERCAOMAISBARATA_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class gulosoInsercaoMaisBarata{
private:
    int size;
    vector<int> solucao;
    vector<vector<int>> matrizAdjacencia;

public:
    explicit gulosoInsercaoMaisBarata(string endereco);
    int calculaSolucao(int inicio1, int inicio2, int inicio3);

};

#endif
