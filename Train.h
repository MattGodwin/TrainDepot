//
// Created by matth on 05/11/2025.
//

#ifndef TRAINDEPOT_TRAIN_H
#define TRAINDEPOT_TRAIN_H
#include "Carriage.h"
#include <vector>
#include <string>
using namespace std;

class Train {
    Train(string id, int numCarriages);

    public:
    int getLength() const;
    string getId() const;
    void repairCarriage(int carriageIndex);
    void flagCarriageForRepair(int carriageIndex);
    void printStatus() const;

    private:
    string id;
    vector<Carriage> carriages;
};


#endif //TRAINDEPOT_TRAIN_H