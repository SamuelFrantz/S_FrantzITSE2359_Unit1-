// Refrigerator.h
#ifndef REFRIGERATOR_H
#define REFRIGERATOR_H

#include "Appliance.h"

// Derived class: Refrigerator
class Refrigerator : public Appliance {
private:
    int capacity; // Specific attribute

public:
    Refrigerator(const std::string& brand, int powerUsage, int capacity);

    void displayInfo() const override;

    ~Refrigerator();
};

#endif // REFRIGERATOR_H
