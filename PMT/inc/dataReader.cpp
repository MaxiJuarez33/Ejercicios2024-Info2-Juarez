#include "../inc/dataReader.h"

#include <iostream>
#include <sstream>

// Constructor
readData::readData(const std::string& fileName) : fileName(fileName) {}

// Destructor
readData::~readData() {
    if (fileStream.is_open()) {
        fileStream.close();
    }
}

// Método para abrir el archivo
void readData::openFile() {
    fileStream.open(fileName);
    if (!fileStream.is_open()) {
        std::cout << "Error al abrir el archivo: " + fileName << std::endl;
    }
    else {
        std::cout << "Archivo abierto exitosamente: " + fileName << std::endl;
    }
}

// Método para leer el archivo
void readData::read(std::vector<dataStruct>& data) {
    if (!fileStream.is_open()) {
        std::cout << "El archivo no esta abierto" << std::endl;
        return;
    }

    std::string linea;
    while (getline(fileStream, linea)) {
        std::stringstream ss(linea);
        dataStruct ds;
        std::string x, y;
        getline(ss, x, ',');
        getline(ss, y, ',');
        ds.x = std::stod(x);
        ds.y = std::stod(y);

        data.push_back(ds);

        // std::cout << "X: " << ds.x << ", Y: " << ds.y << std::endl;
    }

    std::cout << "Archivo leido exitosamente" << std::endl;
}
