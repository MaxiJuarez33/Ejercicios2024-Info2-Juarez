#include "dataReader.h"
#include <iostream>
#include <vector>

// struct dataStruct {
//     double x;
//     double y;
// };

int main() {
    std::string filePath = "csv/testData.csv";
    readData readData(filePath);
    readData.openFile();

    std::vector<dataStruct> data;
    readData.read(data);

    system("pause");

    return 0;
}
