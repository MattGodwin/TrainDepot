//
// Created by matth on 30/11/2025.
//

#ifndef TRAINDEPOT_FREIGHTCARRIAGE_H
#define TRAINDEPOT_FREIGHTCARRIAGE_H

#include "Carriage.h"
#include <iostream>
using namespace std;

class FreightCarriage : public Carriage {
public:
    FreightCarriage(string id, double capacityTons)
        : Carriage(id), capacity(capacityTons) {} // Call base constructor

    // Override the print function
    void printStatus() const override {
        Carriage::printStatus();
        cout << "Type: Freight   | Capacity: " << capacity << " tons" << endl;
    }

private:
    double capacity;
};


#endif //TRAINDEPOT_FREIGHTCARRIAGE_H