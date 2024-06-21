/**
 * @file dataReader.h
 * @author Juarez
 * @brief Creacion de la cabecera encargada de abrir y leer archivos
 * @version 0.1
 * @date 2024-06-20
 *
 * @copyright Copyright (c) 2024
 *
 */


#ifndef DATAREADER_H
#define DATAREADER_H 

#include <string>
#include <fstream>
#include <sstream>
#include <vector>

struct dataStruct {
    double x;
    double y;
};

/**
 * @brief Esta clase permite un mejor flujo de la funcion que abre y lee los archivos indicados
 *
 * @param fileName es el parametro que se le pasa cuando se hace el constructor en el main.cpp, este contiene que archivo debe abrir
 *
 */

class readData {
private:
    std::string fileName;
    std::ifstream fileStream;

public:
    readData(const std::string& fileName);
    ~readData();
    void openFile();
    void read(std::vector<dataStruct>& data);
};

#endif
