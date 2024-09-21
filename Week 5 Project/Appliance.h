// Appliance.h
#ifndef APPLIANCE_H
#define APPLIANCE_H

#include <iostream>
#include <string>

// Abstract base class
class Appliance {
protected:
    std::string brand;
    int powerUsage;

public:
    // Constructor to initialize common attributes
    Appliance(const std::string& brand, int powerUsage);

    // Pure virtual function
    virtual void displayInfo() const = 0;

    // Virtual destructor
    virtual ~Appliance();
};

#endif // APPLIANCE_H
