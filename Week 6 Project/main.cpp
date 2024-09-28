// main.cpp
#include <iostream>
#include <vector>
#include "USA.h"
#include "Japan.h"
#include "Germany.h"
#include "India.h"

int main() {
    int numCountries;

    std::cout << "Enter the number of countries: ";
    std::cin >> numCountries;

    std::vector<Country*> countries;

    for (int i = 0; i < numCountries; ++i) {
        if (i % 4 == 0) {
            countries.push_back(new USA());
        } else if (i % 4 == 1) {
            countries.push_back(new Japan());
        } else if (i % 4 == 2) {
            countries.push_back(new Germany());
        } else if (i % 4 == 3) {
            countries.push_back(new India());
        }
    }

    for (const Country* country : countries) {
        country->displayInfo();
        std::cout << "-------------------\n";
    }

    for (Country* country : countries) {
        delete country;
    }

    return 0;
}
