//
// Created by matth on 05/11/2025.
//

#ifndef TRAINDEPOT_CARRIAGE_H
#define TRAINDEPOT_CARRIAGE_H
#include <string>
using namespace std;


class Carriage {
    public:
    Carriage(string id) {};

    bool needsRepairs() const;
    void flagRepairsNeeded();
    void performRepairs();
    void printStatus() const;
    string getId() const;

    private:
    string id;
    bool repairsNeeded;
};


#endif //TRAINDEPOT_CARRIAGE_H