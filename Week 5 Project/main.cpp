// main.cpp
#include "WashingMachine.h"
#include "Refrigerator.h"

int main() {
    // Create objects of the derived classes
    WashingMachine wm("LG", 500, 7);
    Refrigerator rf("Samsung", 150, 300);

    // Demonstrate polymorphism
    Appliance* appliances[2];
    appliances[0] = &wm;
    appliances[1] = &rf;

    for (int i = 0; i < 2; ++i) {
        appliances[i]->displayInfo();
        std::cout << std::endl;
    }

    return 0;
}
