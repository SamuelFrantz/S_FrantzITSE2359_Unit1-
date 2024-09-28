// USA.cpp
#include "USA.h"

void USA::displayInfo() const {
    std::cout << "Country Name: USA\nCapital: Washington, D.C.\nPopulation: 331 million\n";
}

USA::~USA() {
    std::cout << "USA object destroyed." << std::endl;
}
