// Japan.cpp
#include "Japan.h"

void Japan::displayInfo() const {
    std::cout << "Country Name: Japan\nCapital: Tokyo\nPopulation: 126 million\n";
}

Japan::~Japan() {
    std::cout << "Japan object destroyed." << std::endl;
}
