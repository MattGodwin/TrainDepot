//
// Created by matth on 05/11/2025.
//

#ifndef TRAINDEPOT_DEPOT_H
#define TRAINDEPOT_DEPOT_H
#include <string>
#include <array>
#include "Platform.h"
#include "Train.h"
using namespace std;


class Depot {
    public:
    Depot();
    ~Depot();

    void registerTrain(string id, int numCarriages, string type);
    bool receiveTrain(string trainId);
    void dispatchTrain(int platformId);
    void serviceCarriageOnPlatform(int platformId, int carriage);
    void flagCarriageForRepairOnPlatform(int platformId, int carriage);
    void printStatus() const;

    private:
    Train* findTrain(string trainId);
    Platform* findPlatform();

    vector<Train*> trains;
    array<Platform, 4> platforms;
};


#endif //TRAINDEPOT_DEPOT_H