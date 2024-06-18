#ifndef DATAREADER_H
#define DATAREADER_H 

#include <string>
#include <fstream>
#include <sstream>
#include <vector>
//#include <stdexcept>

struct dataStruct {
    double x;
    double y;
};

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
