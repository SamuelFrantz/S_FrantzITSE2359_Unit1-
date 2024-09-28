// Germany.h
#ifndef GERMANY_H
#define GERMANY_H

#include "Country.h"

class Germany : public Country {
public:
    void displayInfo() const override;
    ~Germany();
};

#endif
