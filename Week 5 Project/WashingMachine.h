// WashingMachine.h
#ifndef WASHINGMACHINE_H
#define WASHINGMACHINE_H

#include "Appliance.h"

// Derived class: WashingMachine
class WashingMachine : public Appliance {
private:
    int drumSize; // Specific attribute

public:
    WashingMachine(const std::string& brand, int powerUsage, int drumSize);

    void displayInfo() const override;

    ~WashingMachine();
};

#endif // WASHINGMACHINE_H
