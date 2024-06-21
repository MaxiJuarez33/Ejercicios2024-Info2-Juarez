/**
 * @file calcEst.h
 * @author Juarez
 * @brief Archivo que contiene la pre-inicializacion de las funciones / metodos que contiene la clase encargada de administrar los calculos estadisticos sobre una variable
 * @version 0.1
 * @date 2024-06-21
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef CALCEST_H
#define CALCEST_H

#include <iostream>
#include <vector>

class calculosEstadisticos {
public:
    calculosEstadisticos(const std::vector<double>& x, const std::vector<double>& y);
    void menu();

private:
    std::vector<double> x;
    std::vector<double> y;

    void modo(const std::vector<double>& selectedVar);
    void promedio(const std::vector<double>& selectedVar);
    void mediana(const std::vector<double>& selectedVar);
};

#endif
