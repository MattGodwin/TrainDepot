//
// Created by matth on 05/11/2025.
//

#include "Train.h"
#include "PassengerCarriage.h"
#include "FreightCarriage.h"
#include <iostream>
using namespace std;

Train::Train(string id, int numCarriages, string type) : id(id) {
    for (int i = 0; i < numCarriages; ++i) {
        string carriageId = id + "-C" + to_string(i + 1);
        // Logic to create specific types
        if (type == "passenger") {
            // New Passenger carriage with 50 seats
            carriages.push_back(new PassengerCarriage(carriageId, 50));
        }
        else if (type == "freight") {
            // New Freight carriage with 100 ton capacity
            carriages.push_back(new FreightCarriage(carriageId, 100.0));
        }
        else {
            // Default to basic carriage if unknown
            carriages.push_back(new Carriage(carriageId));
        }
    }
}

Train::~Train() {
    for (Carriage* c : carriages) {
        delete c;
    }
    carriages.clear();
}
std::string Train::getId() const {
    return id;
}

int Train::getLength() const {
    return carriages.size();
}

void Train::flagCarriageForRepair(int carriageIndex) {
    if (carriageIndex >= 0 && carriageIndex < carriages.size()) {
        carriages[carriageIndex]->flagRepairsNeeded();
    } else {
        cout << "Error: Invalid carriage index " << carriageIndex << " for train " << id << endl;
    }
}

void Train::repairCarriage(int carriageIndex) {
    if (carriageIndex >= 0 && carriageIndex < carriages.size()) {
        carriages[carriageIndex]->performRepairs();
    } else {
        cout << "Error: Invalid carriage index " << carriageIndex << " for train " << id << endl;
    }
}

void Train::printStatus() const {
    cout << "Train " << id << " (Length: " << getLength() << "):" << endl;
    for (const auto& carriage : carriages) {
        carriage->printStatus();
    }
}