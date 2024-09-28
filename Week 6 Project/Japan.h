// Japan.h
#ifndef JAPAN_H
#define JAPAN_H

#include "Country.h"

class Japan : public Country {
public:
    void displayInfo() const override;
    ~Japan();
};

#endif
