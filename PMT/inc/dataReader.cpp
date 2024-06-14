#include "../inc/dataReader.h"

#include <iostream>
#include <sstream>

readData::readData(const std::string& fileName) : fileName(fileName) {}

readData::~readData() {
    if (fileStream.is_open()) {
        fileStream.close();
    }
}

void readData::openFile() {
    fileStream.open(fileName);
    if (!fileStream.is_open()) {
        std::cout << "Error al abrir el archivo: " + fileName << std::endl;
    }
    else {
        std::cout << "Archivo abierto exitosamente: " + fileName << std::endl;
    }
}

void readData::read(std::vector<dataStruct>& data) {
    if (!fileStream.is_open()) {
        std::cout << "El archivo no esta abierto" << std::endl;
        return;
    }

    std::string linea;
    while (getline(fileStream, linea)) {
        std::stringstream ss(linea);
        dataStruct dataStruct;
        std::string x, y;
        getline(ss, x, ',');
        getline(ss, y, ',');
        dataStruct.x = std::stod(x);
        dataStruct.y = std::stod(y);

        data.push_back(dataStruct);

        // std::cout << "X: " << dataStruct.x << ", Y: " << dataStruct.y << std::endl;
    }

    std::cout << "Archivo leido exitosamente" << std::endl;
}
