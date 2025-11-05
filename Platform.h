//
// Created by matth on 05/11/2025.
//

#ifndef TRAINDEPOT_PLATFORM_H
#define TRAINDEPOT_PLATFORM_H
#include <string>

class Train;

class Platform {
    public:
    Platform(int id);

    bool isFree() const;
    bool assignTrain(Train* train);
    Train* getTrain() const;
    Train* removeTrain();
    void printStatus() const;

    private:
    int id;
    Train* currentTrain;
};


#endif //TRAINDEPOT_PLATFORM_H