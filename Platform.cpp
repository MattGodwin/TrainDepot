//
// Created by matth on 05/11/2025.
//

#include "Platform.h"
#include "Train.h"
#include <iostream>

Platform::Platform(int id) : id(id), currentTrain(nullptr) {
}

bool Platform::isFree() const {
    return currentTrain == nullptr;
}

bool Platform::assignTrain(Train* train) {
    if (isFree()) {
        currentTrain = train;
        return true;
    }
    return false;
}

Train* Platform::removeTrain() {
    Train* departingTrain = currentTrain;
    currentTrain = nullptr;
    return departingTrain;
}

Train* Platform::getTrain() const {
    return currentTrain;
}

void Platform::printStatus() const {
    std::cout << "Platform " << id << ": ";
    if (isFree()) {
        std::cout << "[FREE]" << std::endl;
    } else {
        std::cout << "[Occupied by: " << currentTrain->getId() << "]" << std::endl;
    }
}