/**
 * @file calcEst.cpp
 * @author Juarez
 * @brief Este archivo contiene todas las declaraciones de las funciones de la cabecera calcEst, encargada de ejecutar los calculos estadisticos (moda, media, mediana)
 * calculable para cualquiera de las dos variables (x e y)
 * @version 0.1
 * @date 2024-06-21
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "calCest.h"
#include <algorithm>

 /**
  * @brief Se crea el objeto calculosEstadisticos usando el constructor y se indica el valor de las variables privadas x e y
  *
  * @param x vector que contiene los datos de la izquierda del archivo de datos, variable independiente
  * @param y vector que contiene los datos de la derecha del archivo de datos, variable dependiente
  */

calculosEstadisticos::calculosEstadisticos(const std::vector<double>& x, const std::vector<double>& y)
    : x(x), y(y) {}

/**
 * @brief el metodo menu es el que será llamado en el main, este contiene el procesamiento sobre las posibilidades de calculos y redirige a los metodos privados, encargados de los calculos
 *
 */

void calculosEstadisticos::menu() {
    char continuar = 's';

    while (continuar == 's') {
        char selectedVarName;
        int choice = 0;

        std::cout << "Sobre que variable desea realizar calculos estadisticos? (x/y): ";
        std::cin >> selectedVarName;

        const std::vector<double>* selectedVar = nullptr;
        if (selectedVarName == 'x') {
            selectedVar = &x;
        }
        else if (selectedVarName == 'y') {
            selectedVar = &y;
        }
        else {
            std::cout << "Variable no reconocida" << std::endl;
            return;
        }

        std::cout << "Que desea calcular sobre la variable " << selectedVarName << ":" << std::endl;
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

        do {
            std::cout << "\nDesea realizar otro calculo? (s/n): ";
            std::cin >> continuar;
        } while (continuar != 's' && continuar != 'n');
    }
}


/**
 * @brief metodo encargado de calcular el modo de la variable indicada
 *
 * @param selectedVar variable sobre la cual realizar el calculo, indicado por el usuario en el metodo menu
 */

void calculosEstadisticos::modo(const std::vector<double>& selectedVar) {
    std::vector<int> frecuencia(selectedVar.size(), 0);
    int maxFrecuencia = 0;
    double valorModa = 0.0;

    for (size_t i = 0; i < selectedVar.size(); ++i) {
        for (size_t j = 0; j < selectedVar.size(); ++j) {
            if (selectedVar[i] == selectedVar[j]) {
                frecuencia[i]++;
            }
        }

        if (frecuencia[i] > maxFrecuencia) {
            maxFrecuencia = frecuencia[i];
            valorModa = selectedVar[i];
        }
    }

    std::cout << "La moda es: " << valorModa << " con frecuencia de " << maxFrecuencia << std::endl;
}

/**
 * @brief metodo encargado de realizar el calculo del promedio de los datos, este promedio es el que no tiene en cuenta los pesos, solo la suma de todos los datos sobre la cantidad de datos
 *
 * @param selectedVar variable sobre la cual realizar el calculo, indicado por el usuario en el metodo menu
 */

void calculosEstadisticos::promedio(const std::vector<double>& selectedVar) {
    double suma = 0.0;

    for (double valor : selectedVar) {
        suma += valor;
    }
    double media = suma / selectedVar.size();

    std::cout << "El promedio es: " << media << std::endl;
}

/**
 * @brief metodo encargado de encontrar la mediana de los datos indicados, se utilizo la libreria algorithm para agilizar el calculo, permitiendo usar la funcion de sort()
 *
 * @param selectedVar variable sobre la cual realizar el calculo, indicado por el usuario en el metodo menu
 */

void calculosEstadisticos::mediana(const std::vector<double>& selectedVar) {
    std::vector<double> sortedVar = selectedVar;

    // DEJO ESTE METODO COMENTADO PORQUE ENCONTRE EL SORT Y CONSIDERO QUE ES MEJOR PARA LA OPTIMIZACION QUE UN BUBBLE SORT
    // int n = sortedVar.size();
    // bool flag;

    // for (int i = 0; i < n - 1; ++i) {
    //     flag = false;
    //     for (int j = 0; j < n - i - 1; ++j) {
    //         if (sortedVar[j] > sortedVar[j + 1]) {
    //             double temp = sortedVar[j];
    //             sortedVar[j] = sortedVar[j + 1];
    //             sortedVar[j + 1] = temp;
    //             flag = true;
    //         }
    //     }
    //     if (!flag) break;
    // }

    std::sort(sortedVar.begin(), sortedVar.end()); // Optimizado

    double mediana;
    size_t size = sortedVar.size();

    if (size % 2 == 0) {
        mediana = (sortedVar[size / 2 - 1] + sortedVar[size / 2]) / 2;
    }
    else {
        mediana = sortedVar[size / 2];
    }

    std::cout << "La mediana es: " << mediana << std::endl;
}
