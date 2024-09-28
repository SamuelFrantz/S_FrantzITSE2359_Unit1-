// Country.h
#ifndef COUNTRY_H
#define COUNTRY_H

#include <iostream>

class Country {
public:
    virtual void displayInfo() const = 0;  // Pure virtual function
    virtual ~Country();  // Virtual destructor
};

#endif
