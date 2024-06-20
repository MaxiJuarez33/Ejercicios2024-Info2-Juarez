#include "calCest.h"
#include <algorithm>
#include <numeric>
#include <map>

calculosEstadisticos::calculosEstadisticos(const std::vector<double>& x, const std::vector<double>& y)
    : x(x), y(y) {}

void calculosEstadisticos::menu() {
    std::string selectedVarName;
    int choice = 0;

    std::cout << "Sobre que variable desea realizar calculos estadisticos? (x/y)" << std::endl;
    std::cin >> selectedVarName;

    const std::vector<double>* selectedVar = nullptr;
    if (selectedVarName == "x") {
        selectedVar = &x;
    }
    else if (selectedVarName == "y") {
        selectedVar = &y;
    }
    else {
        std::cout << "Variable no reconocida" << std::endl;
        return;
    }

    std::cout << "Que desea calcular sobre la variable " << selectedVarName << std::endl;
    std::cout << "1 : Moda | 2 : Media | 3 : Mediana" << std::endl;
    std::cin >> choice;

    switch (choice) {
    case 1:
        modo(*selectedVar);
        break;
    case 2:
        promedio(*selectedVar);
        break;
    case 3:
        mediana(*selectedVar);
        break;
    default:
        std::cout << "Opcion no valida" << std::endl;
        break;
    }
}

void calculosEstadisticos::modo(const std::vector<double>& selectedVar) const {
    std::map<double, int> frequency;

    for (double val : selectedVar) {
        frequency[val]++;
    }

    int maxFrequency = 0;
    double valorModa = 0.0;
    for (const auto& pair : frequency) {  // BUSCAR ALTERNATIVA PARA NIVEL NOVATO
        if (pair.second > maxFrequency) {
            maxFrequency = pair.second;
            valorModa = pair.first;
        }
    }

    std::cout << "La moda es: " << valorModa << " con frecuencia de " << maxFrequency << std::endl;
}


void calculosEstadisticos::promedio(const std::vector<double>& selectedVar) const {
    double sum = std::accumulate(selectedVar.begin(), selectedVar.end(), 0.0);
    double mean = sum / selectedVar.size();
    std::cout << "El promedio es: " << mean << std::endl;
}

void calculosEstadisticos::mediana(const std::vector<double>& selectedVar) const {
    std::vector<double> sortedVar = selectedVar;
    std::sort(sortedVar.begin(), sortedVar.end());
    double median;
    size_t size = sortedVar.size();
    if (size % 2 == 0) {
        median = (sortedVar[size / 2 - 1] + sortedVar[size / 2]) / 2;
    }
    else {
        median = sortedVar[size / 2];
    }
    std::cout << "La mediana es: " << median << std::endl;
}
