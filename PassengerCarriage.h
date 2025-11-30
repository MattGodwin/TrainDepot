//
// Created by matth on 30/11/2025.
//

#ifndef TRAINDEPOT_PASSENGERCARRIAGE_H
#define TRAINDEPOT_PASSENGERCARRIAGE_H

#include "Carriage.h"
#include <iostream>
using namespace std;

class PassengerCarriage : public Carriage {
public:
    PassengerCarriage(string id, int seatCount)
        : Carriage(id), seats(seatCount) {} // Call base constructor

    // Override the print function
    void printStatus() const override {
        Carriage::printStatus(); // Print the ID and maintenance status first
        cout << "Type: Passenger | Seats: " << seats << endl;
    }

private:
    int seats;
};


#endif //TRAINDEPOT_PASSENGERCARRIAGE_H