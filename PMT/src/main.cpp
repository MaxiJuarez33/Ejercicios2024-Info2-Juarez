/**
 * @file main.cpp
 * @author Juarez
 * @brief este archivo contiene todo el desarrollo del programa final, incluyendo las cabeceras hechas.
 * Incluye la funcion del calculo de la regresion lineal simple, guardar y cargar modelos, extraer datos y realizar predicciones
 * @version 0.1
 * @date 2024-06-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "dataReader.h"
#include "calcEst.h"

struct EcVars {
    double m;
    double b;
} ecVars;

std::vector<double> xValues;
std::vector<double> yValues;

/**
 * @brief Funcion para realizar el calculo de los componentes de la ecuacion de la recta (pendiente m y ordenada al origen b) el cual se utiliza para la regresion lineal simple,
 * utilizando el metodo de minimos cuadrados ordinarios.
 *
 * @param x son los valores, almacenados como vector, que se pasan como variables independientes de la tabla de datos extraida de los archivos
 * @param y son los valores, almacenados como vector, que se pasan como variables dependientes de la tabla de datos extraida de los archivos
 * @param size es el tamaño que tienen los vectores que contienen los datos (x e y)
 */

void simpleLinearRegression(const double* x, const double* y, size_t size) {
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

    ecVars.m = (sumXY - size * meanX * meanY) / (sumX2 - size * meanX * meanX);
    ecVars.b = meanY - ecVars.m * meanX;
}

/**
 * @brief Esta funcion es utilizada para guardar los modelos con ciertos datos, se guardan en archivos csv utilizando el formato de
 * Nombre, m, b.
 *
 */

void modelSaver() {
    std::string modelName;
    std::cout << "Ingrese el nombre para guardar su modelo (sin espacios): " << std::endl;
    std::cin >> modelName;

    std::ofstream modelSaver("csv/models.csv", std::ios_base::app);

    if (!modelSaver.is_open()) {
        std::cout << "Error al abrir el archivo models.csv" << std::endl;
    }

    modelSaver.seekp(0, std::ios_base::end);
    modelSaver << modelName << "," << ecVars.m << "," << ecVars.b << std::endl;

    std::cout << "Su modelo " << modelName << " se guardo correctamente" << std::endl;

    modelSaver.close();
}

/**
 * @brief Esta funcion permite cargar modelos guardados, permite no tener que calcular todos los datos de la ecuacion nuevamente, lo que permite no tener que guardar ese archivo de datos para este modelo
 *
 */

void modelLoader() {
    std::ifstream modelLoader("csv/models.csv");
    std::string line;
    std::string modelName;
    bool found = false;

    std::cout << "\nIngrese el nombre del modelo que desea cargar: " << std::endl;
    std::cin >> modelName;

    while (true) {
        while (getline(modelLoader, line)) {
            if (line.find(modelName) != std::string::npos) {
                std::stringstream ss(line);
                std::string temp;

                getline(ss, temp, ','); // Se descarta el nombre
                getline(ss, temp, ',');
                ecVars.m = std::stod(temp);
                getline(ss, temp, ',');
                ecVars.b = std::stod(temp);

                found = true;
                break;
            }
        }

        if (found) {
            std::cout << "Modelo cargado exitosamente" << std::endl;
            break;
        }
        else {
            std::cout << "Modelo no encontrado\nIngrese el nombre nuevamente (o ingrese 'salir' para abortar): " << std::endl;
            std::cin >> modelName;
            if (modelName == "salir") {
                break;
            }

            modelLoader.clear();
            modelLoader.seekg(0, std::ios::beg);
        }
    }

    modelLoader.close();
}


/**
 * @brief Esta funcion es utilizada para realizar predicciones en base a la ecuacion y=mx + b, donde el usuario ingresa x, incluye un bucle por si el usuario desea hacer mas de una prediccion
 *
 */

void predOption() {
    char predRepe = 's';

    while (predRepe == 's') {
        double predValue = 0;
        std::cout << "Ingrese un valor para predecir" << std::endl;
        std::cin >> predValue;
        double yPred = ecVars.m * predValue + ecVars.b;
        std::cout << "El valor predicho para " << predValue << " es " << yPred << std::endl;
        std::cout << "\nDesea realizar otra prediccion? (s/n)" << std::endl;
        std::cin >> predRepe;
    }

    return;
}

/**
 * @brief Esta funcion va complementada con la funcion modelSaver(), ya que esta permite hacer los calculos necesarios para guardar la pendiente y ordenada al origen partiendo de los datos para el modelo a guardar
 *
 */

void dataExtraction() {
    std::string fileName;
    std::cout << "Ingrese el nombre del archivo con datos (incluya el .csv)" << std::endl;
    std::cin >> fileName;
    std::string filePath = "csv/";
    filePath.append(fileName);

    readData readData(filePath);
    readData.openFile();

    std::vector<dataStruct> data;
    readData.read(data);

    for (const auto& entry : data) {
        xValues.push_back(entry.x);
        yValues.push_back(entry.y);
    }

    simpleLinearRegression(xValues.data(), yValues.data(), data.size());

    std::string option;

    std::cout << "Desea realizar algun calculo estadistico sobre estos datos? (s/n)" << std::endl;
    std::cin >> option;

    while (true) {
        if (option == "s") {
            calculosEstadisticos calculosEstadisticos(xValues, yValues);
            calculosEstadisticos.menu();
            break;
        }
        else if (option == "n") {
            return;
            break;
        }
        else {
            std::cout << "Opcion inexistente, intente nuevamente o ingrese 'salir'" << std::endl;
            std::cin >> option;
            if (option == "salir") {
                break;
            }
        }
    }
}

/**
 * @brief La funcion main contiene el procesamiento de todo el programa, genera preguntas para el usuario y gestiona las decisiones redirigiendo a las funciones correspondientes
 *
 * @return int retorna 0 para que finalice el programa
 */

int main() {
    int choice = 0;

    std::cout << "Para cargar un modelo ingrese 1 | Para operar con los datos o crear un modelo ingrese 2" << std::endl;
    std::cin >> choice;

    if (choice == 1) {
        modelLoader();

        char option;
        std::cout << "Desea realizar un calculo de prediccion? (s/n)" << std::endl;
        std::cin >> option;
        if (option == 's') {
            predOption();
        }
    }
    else if (choice == 2) {
        char option;
        dataExtraction();
        std::cout << "Desea guardar el modelo? (s/n)" << std::endl;
        std::cin >> option;
        if (option == 's') {
            modelSaver();
        }
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