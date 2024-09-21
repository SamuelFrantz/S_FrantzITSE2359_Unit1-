// Refrigerator.cpp
#include "Refrigerator.h"

// Constructor
Refrigerator::Refrigerator(const std::string& brand, int powerUsage, int capacity)
    : Appliance(brand, powerUsage), capacity(capacity) {}

// Override the pure virtual function
void Refrigerator::displayInfo() const {
    std::cout << "Refrigerator:" << std::endl;
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Power Usage: " << powerUsage << " watts" << std::endl;
    std::cout << "Capacity: " << capacity << " liters" << std::endl;
}

// Destructor
Refrigerator::~Refrigerator() {
    std::cout << "Refrigerator destroyed" << std::endl;
}
