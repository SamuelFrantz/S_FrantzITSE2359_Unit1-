// USA.h
#ifndef USA_H
#define USA_H

#include "Country.h"

class USA : public Country {
public:
    void displayInfo() const override;
    ~USA();
};

#endif
