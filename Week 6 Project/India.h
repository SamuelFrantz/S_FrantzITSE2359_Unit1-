// India.h
#ifndef INDIA_H
#define INDIA_H

#include "Country.h"

class India : public Country {
public:
    void displayInfo() const override;
    ~India();
};

#endif
