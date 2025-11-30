//
// Created by matth on 05/11/2025.
//

#include "Depot.h"
#include <iostream>
#include <string>
using namespace std;

Depot::Depot()
    : platforms({Platform(1), Platform(2), Platform(3), Platform(4)}) {
}
Depot::~Depot() {
    for (Train* t : trains) {
        delete t;
    }
    trains.clear();
}

void Depot::registerTrain(string id, int numCarriages, string type) {
    Train* newTrain = new Train(id, numCarriages, type);
    trains.push_back(newTrain);
    cout << "Created new " << type << " train: '" << id << "' with " << numCarriages << " carriages." << endl;
}

bool Depot::receiveTrain(string trainId) {
    Train* train = findTrain(trainId);
    if (!train) {
        cout << "Error: Train " << trainId << " not found." << endl;
        return false;
    }

    Platform* platform = findPlatform();
    if (!platform) {
        cout << "System: No free platforms available for train " << trainId << "." << endl;
        return false;
    }

    platform->assignTrain(train);
    cout << "System: Train " << trainId << " assigned to platform " << platform->getTrain()->getId() << "." << endl;
    return true;
}

void Depot::dispatchTrain(int platformId) {
    if (platformId < 1 || platformId > 4) {
        cout << "Error: Invalid platform ID " << platformId << "." << endl;
        return;
    }

    Platform& platform = platforms[platformId - 1];
    if (platform.isFree()) {
        cout << "System: Platform " << platformId << " is already empty." << endl;
    } else {
        string trainId = platform.getTrain()->getId();
        platform.removeTrain();
        cout << "System: Train " << trainId << " dispatched from platform " << platformId << "." << endl;
    }
}

void Depot::serviceCarriageOnPlatform(int platformId, int carriageIndex) {
    if (platformId < 1 || platformId > 4) {
        cout << "Error: Invalid platform ID " << platformId << "." << endl;
        return;
    }

    Train* train = platforms[platformId - 1].getTrain();
    if (train) {
        train->repairCarriage(carriageIndex);
    } else {
        cout << "Error: No train on platform " << platformId << " to service." << endl;
    }
}

void Depot::flagCarriageForRepairOnPlatform(int platformId, int carriageIndex) {
    if (platformId < 1 || platformId > 4) {
        cout << "Error: Invalid platform ID " << platformId << "." << endl;
        return;
    }

    Train* train = platforms[platformId - 1].getTrain();
    if (train) {
        train->flagCarriageForRepair(carriageIndex);
    } else {
        cout << "Error: No train on platform " << platformId << " to flag." << endl;
    }
}

void Depot::printStatus() const {
    cout << "\n--- DEPOT STATUS ---" << endl;
    for (const auto& platform : platforms) {
        platform.printStatus();
        if (!platform.isFree()) {
            // If platform is not free, print the status of the train on it
            platform.getTrain()->printStatus();
        }
    }
    cout << "----------------------\n" << endl;
}


Train* Depot::findTrain(string trainId) {
    for (Train* train : trains) {
        if (train->getId() == trainId) {
            return train;
        }
    }
    return nullptr;
}

Platform* Depot::findPlatform() {
    for (Platform& platform : platforms) {
        if (platform.isFree()) {
            return &platform; // Return a pointer to the platform
        }
    }
    return nullptr;
}