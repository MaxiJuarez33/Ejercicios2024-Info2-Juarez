hasta ahora, con una libreria tirada en inc

g++ -Iinc -o PMT src/main.cpp inc/dataReader.cpp

con calcEst

g++ -Iinc -o PMT src/main.cpp inc/dataReader.cpp inc/calcEst.cpp

########################################################################

// bool logs(std::string fileName) {
// std::ifstream inputLogs("csv/logs.csv");
// std::string line;
// bool foundState = false;

// if (!inputLogs.is_open()) {
// std::cout << "Error al abrir el archivo " << fileName << " para la lectura" << std::endl;
// }
// else {
// std::cout << fileName << " abierto exitosamente para la lectura" << std::endl;
// while (getline(inputLogs, line)) {
// if (line.find(fileName) != std::string::npos) {
// std::cout << "Linea encontrada" << std::endl;
// foundState = true;
// break;
// }
// }

// inputLogs.close();
// }

// if (foundState == false) {
// std::ofstream outputLogs("csv/logs.csv", std::ios_base::app);

// if (!outputLogs.is_open()) {
// std::cout << "Error al abrir el archivo " << fileName << " para escritura" << std::endl;
// return;
// }

// outputLogs.seekp(0, std::ios_base::end);
// outputLogs << fileName << std::endl;
// outputLogs.close();
// }

// return foundState;
// }
