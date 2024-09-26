#include "gulosoMenorCaminho.hpp"
#include "gulosoInsercaoMaisBarata.hpp"

#include <iostream>

using namespace std;

int main() {
    string endereco;
    int inicio;

    cin >> endereco;
    cin >> inicio;

    gulosoMenorCaminho guloso1(endereco);
    int valGuloso1 = guloso1.calculaSolucao(inicio);
    
    gulosoInsercaoMaisBarata guloso2(endereco);
    int valGuloso2 = guloso2.calculaSolucao(0, 1, 2);

    cout << "Guloso menor caminho: " << valGuloso1 << endl;
    cout << "Guloso inserção mais barata: " << valGuloso2 << endl;

    return 0;
}
