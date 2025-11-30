//
// Created by matth on 05/11/2025.
//

#include "Carriage.h"
#include <iostream>
#include <string>
using namespace std;

Carriage::Carriage(string id) : id(id), repairsNeeded(false) {}

string Carriage::getId() const {
    return id;
}

bool Carriage::needsRepairs() const {
    return repairsNeeded;
}

void Carriage::flagRepairsNeeded() {
    repairsNeeded = true;
    cout << "  -> Carriage " << id << " has been flagged for repairs." << endl;
}

void Carriage::performRepairs() {
    repairsNeeded = false;
    cout << "  -> Repairs complete on carriage " << id << "." << endl;
}

void Carriage::printStatus() const {
    cout << "  - Carriage: " << id << " (Status: " << (repairsNeeded ? "Needs Repairs" : "OK") << ") ";
}