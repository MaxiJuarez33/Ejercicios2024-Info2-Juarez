/**
 * @file dataReader.cpp
 * @author Juarez
 * @brief Declaracion de la clase y metodos de la cabecera
 * @version 0.1
 * @date 2024-06-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "dataReader.h"

#include <iostream>

 /**
  * @brief Se crea el objeto readData
  *
  * @param fileName sera almacenado como variable privada de la clase
  */

readData::readData(const std::string& fileName) : fileName(fileName) {}

readData::~readData() {
    if (fileStream.is_open()) {
        fileStream.close();
    }
}

/**
 * @brief Se declara la funcion del metodo openFile. Este metodo debe abrir el archivo e indicar el resultado de la operacion
 *
 */

void readData::openFile() {
    fileStream.open(fileName);
    if (!fileStream.is_open()) {
        std::cout << "Error al abrir el archivo: " + fileName << std::endl;
    }
    else {
        std::cout << "Archivo abierto exitosamente: " + fileName << std::endl;
    }
}

/**
 * @brief Se declara la funcion del metodo read. Este metodo debe leer los datos del archivo indicado, en caso de estar vacio se indicará en otra funcion dentro del main.cpp
 *
 * @param data se establece como una estructura vectorial (equivalente a array)
 */

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
    }

    std::cout << "Archivo leido exitosamente" << std::endl;
}
