// WashingMachine.cpp
#include "WashingMachine.h"

// Constructor
WashingMachine::WashingMachine(const std::string& brand, int powerUsage, int drumSize)
    : Appliance(brand, powerUsage), drumSize(drumSize) {}

// Override the pure virtual function
void WashingMachine::displayInfo() const {
    std::cout << "Washing Machine:" << std::endl;
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Power Usage: " << powerUsage << " watts" << std::endl;
    std::cout << "Drum Size: " << drumSize << " liters" << std::endl;
}

// Destructor
WashingMachine::~WashingMachine() {
    std::cout << "WashingMachine destroyed" << std::endl;
}
