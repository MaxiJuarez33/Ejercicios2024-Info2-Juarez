#ifndef CALCEST_H
#define CALCEST_H

#include <iostream>
#include <cmath>
#include <vector>

class calculosEstadisticos {
public:
    calculosEstadisticos(const std::vector<double>& x, const std::vector<double>& y);
    ~calculosEstadisticos();
    void menu();
    void modo(const std::vector<double>& selectedVar) const;
    void promedio(const std::vector<double>& selectedVar) const;
    void mediana(const std::vector<double>& selectedVar) const;

private:
    std::vector<double> x;
    std::vector<double> y;
};

#endif
