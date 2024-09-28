// Germany.cpp
#include "Germany.h"

void Germany::displayInfo() const {
    std::cout << "Country Name: Germany\nCapital: Berlin\nPopulation: 83 million\n";
}

Germany::~Germany() {
    std::cout << "Germany object destroyed." << std::endl;
}
