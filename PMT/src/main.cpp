#include "dataReader.h"
#include <iostream>
#include <vector>

void simpleLinearRegression(const double* x, const double* y, size_t size, double& m, double& b) {
    if (size == 0) {
        // std::cerr << "No se ingresaron datos" << std::endl;
        std::cout << "No se ingresaron datos" << std::endl;
        return;
    }

    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

    for (size_t i = 0; i < size; ++i) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    double meanX = sumX / size;
    double meanY = sumY / size;

    m = (sumXY - size * meanX * meanY) / (sumX2 - size * meanX * meanX);
    b = meanY - m * meanX;
}


int main() {
    std::string filePath = "csv/testData.csv";
    readData readData(filePath);
    readData.openFile();

    std::vector<dataStruct> data;
    readData.read(data);

    size_t dataSize = data.size();
    double* xValues = new double[dataSize];
    double* yValues = new double[dataSize];

    for (size_t i = 0; i < dataSize; ++i) {
        xValues[i] = data[i].x;
        yValues[i] = data[i].y;
    }

    // ------------------------------- REGRESION

    double m = 0, b = 0;
    double predValue = 0;

    simpleLinearRegression(xValues, yValues, dataSize, m, b);

    std::cout << "m: " << m << "\nb: " << b << std::endl;

    std::cout << "\nIngrese un valor de x para predecir: " << std::endl;
    std::cin >> predValue;

    double yPred = m * predValue + b;

    std::cout << "El valor de Y predicho es: " << yPred << std::endl;

    // for (const auto& dataStruct : data) {
    //     std::cout << "X: " << dataStruct.x << ", Y: " << dataStruct.y << std::endl;
    // }

    system("pause");

    return 0;
}
