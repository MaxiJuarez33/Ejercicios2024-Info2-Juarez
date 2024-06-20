#include "calCest.h"
#include <algorithm>
#include <numeric>
#include <map>

calculosEstadisticos::calculosEstadisticos(const std::vector<double>& x, const std::vector<double>& y)
    : x(x), y(y) {}

calculosEstadisticos::~calculosEstadisticos() {}

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
        // std::cerr << "Variable no reconocida" << std::endl;
        std::cout << "Variable no reconocida" << std::endl;
        return;
    }

    std::cout << "Que desea calcular sobre la variable " << selectedVarName << std::endl;
    std::cout << "1 : Modo | 2 : Media | 3 : Mediana" << std::endl;
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
        // std::cerr << "Opción no valida" << std::endl;
        std::cout << "Opcion no valida" << std::endl;
        break;
    }
}

void calculosEstadisticos::modo(const std::vector<double>& selectedVar) const {
    std::map<double, int> frequency;
    for (double val : selectedVar) {
        frequency[val]++;
    }
    auto mode = std::max_element(frequency.begin(), frequency.end(),
        [](const std::pair<double, int>& a, const std::pair<double, int>& b) {
            return a.second < b.second;
        });
    std::cout << "La moda es: " << mode->first << " con frecuencia de " << mode->second << std::endl;
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
