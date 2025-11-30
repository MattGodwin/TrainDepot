//
// Created by matth on 05/11/2025.
//

#ifndef TRAINDEPOT_CARRIAGE_H
#define TRAINDEPOT_CARRIAGE_H
#include <string>
using namespace std;


class Carriage {
    public:
    Carriage(string id);

    virtual ~Carriage() {}

    bool needsRepairs() const;
    void flagRepairsNeeded();
    void performRepairs();
    virtual void printStatus() const;
    string getId() const;

    protected:
    string id;
    bool repairsNeeded;
};


#endif //TRAINDEPOT_CARRIAGE_H