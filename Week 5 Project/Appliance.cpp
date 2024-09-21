// Appliance.cpp
#include "Appliance.h"

// Constructor
Appliance::Appliance(const std::string& brand, int powerUsage)
    : brand(brand), powerUsage(powerUsage) {}

// Virtual destructor
Appliance::~Appliance() {
    std::cout << "Appliance destroyed" << std::endl;
}
