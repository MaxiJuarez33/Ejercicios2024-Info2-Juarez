#include "dataReader.h"
#include "calcEst.h"
#include <iostream>
#include <vector>
// #include <stdexcept>
// #include <fstream>

struct EcVars {
    double m;
    double b;
} ecVars;

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

std::string modelSaver(double& m, double& b) {
    std::string modelName;
    std::cout << "Ingrese el nombre para guardar su modelo: " << std::endl;
    std::cin >> modelName;

    std::ofstream modelSaver("csv/models.csv", std::ios_base::app);

    if (!modelSaver.is_open()) {
        std::cout << "Error al abrir el archivo models.csv" << std::endl;
        // throw std::invalid_argument("Error al abrir el archivo models.csv"); // HACER TRY CATCH
    }
    // std::cout << "models.csv abierto exitosamente" << std::endl;

    modelSaver.seekp(0, std::ios_base::end);
    modelSaver << modelName << "," << m << "," << b << std::endl;

    std::cout << "Su modelo " << modelName << " se guardo correctamente" << std::endl;

    modelSaver.close();

    return modelName;
}

void modelLoader() {
    std::ifstream modelLoader("csv/models.csv");
    std::string line;
    std::string modelName;

    std::cout << "\nIngrese el nombre del modelo que desea cargar: " << std::endl;
    std::cin >> modelName;

    while (getline(modelLoader, line)) {
        if (line.find(modelName) != std::string::npos) {
            // std::cout << "Linea encontrada: " << line << std::endl;

            std::stringstream ss(line);
            std::string temp;

            getline(ss, temp, ','); // Se descarta el nombre
            getline(ss, temp, ',');
            ecVars.m = std::stod(temp);
            getline(ss, temp, ',');
            ecVars.b = std::stod(temp);

            // std::cout << "m: " << ecVars.m << ", b: " << ecVars.b << std::endl;
            break;
        }
    }
}

void predOption(double& m, double& b) {
    char option;
    char predRepe = 's';
    std::cout << "Desea realizar una prediccion? (s/n)" << std::endl;
    std::cin >> option;

    if (option == 's') {
        while (predRepe == 's') {
            double predValue = 0;
            std::cout << "Ingrese un valor para predecir" << std::endl;
            std::cin >> predValue;
            double yPred = m * predValue + b;
            std::cout << "El valor predicho para " << predValue << " es " << yPred << std::endl;
            std::cout << "\nDesea realizar otra prediccion? (s/n)" << std::endl;
            std::cin >> predRepe;
        }
    }
}

void modelOption() {
    std::string fileName;
    std::cout << "Ingrese el nombre del archivo con datos (incluya el .csv)" << std::endl;
    std::cin >> fileName;
    std::string filePath = "csv/";
    filePath.append(fileName);

    readData readData(filePath);
    readData.openFile();

    std::vector<dataStruct> data;
    readData.read(data);

    std::vector<double> xValues;
    std::vector<double> yValues;

    for (const auto& entry : data) {
        xValues.push_back(entry.x);
        yValues.push_back(entry.y);
    }

    simpleLinearRegression(xValues.data(), yValues.data(), data.size(), ecVars.m, ecVars.b);

    calculosEstadisticos calculosEstadisticos(xValues, yValues);
    calculosEstadisticos.menu();

    std::cout << "m: " << ecVars.m << " b: " << ecVars.b << std::endl;
}

int main() {
    int choice = 0;

    std::cout << "Para cargar un modelo ingrese 1 | Para crear un nuevo modelo ingrese 2" << std::endl;
    std::cin >> choice;

    if (choice == 1) {
        modelLoader();
        predOption(ecVars.m, ecVars.b);
    }
    else if (choice == 2) {
        modelOption();
        modelSaver(ecVars.m, ecVars.b);
    }
    else {
        while (true) {
            std::cout << "Opcion inexistente, ingrese nuevamente la operacion" << std::endl;
            std::cin >> choice;
            if (choice == 1 || choice == 2) {
                break;
            }
        }
    }

    system("pause");

    return 0;
}
