#include <iostream>
#include "Depot.h"
using namespace std;

// Demonstration of depot system working
void depotDemo() {
    cout << "Initialising Train Depot System..." << endl;
    Depot myDepot;

    // 1. Create trains of different lengths
    myDepot.registerTrain("Train-01", 5, "passenger"); // 5 carriages passenger
    myDepot.registerTrain("Train-02", 3 , "passenger"); // 3 carriages passenger
    myDepot.registerTrain("Train-03", 8, "freight"); // 8 carriages freight

    // 2. Check initial status
    myDepot.printStatus();

    // 3. Receive trains into the depot
    myDepot.receiveTrain("Train-01"); // Goes to Platform 1
    myDepot.receiveTrain("Train-03"); // Goes to Platform 2

    myDepot.printStatus();

    // 4. Flag a specific carriage for maintenance
    // Flag carriage index 2 (the 3rd carriage) on platform 1
    cout << "--- Performing Maintenance Check ---" << endl;
    myDepot.flagCarriageForRepairOnPlatform(1, 2);
    myDepot.printStatus();

    // 5. Perform maintenance
    cout << "--- Repairing Carriage ---" << endl;
    myDepot.serviceCarriageOnPlatform(1, 2);
    myDepot.printStatus();

    // 6. Dispatch a train
    cout << "--- Dispatching Train ---" << endl;
    myDepot.dispatchTrain(2); // Dispatch train from Platform 2
    myDepot.printStatus();

    // 7. Receive another train
    cout << "--- Receiving New Train ---" << endl;
    myDepot.receiveTrain("Train-02"); // Should go to Platform 2 (now free)
    myDepot.printStatus();

    cout << "Depot simulation complete." << endl;
}

void registerTrains(Depot* depot) {
    cout << "How many trains would you like to register? (max: 4)" << endl;
    int numTrains = 0;
    cin >> numTrains;

    for (int i = 0; i < numTrains; i++) {
        cout << "Enter train " << i << " name: ";
        string name;
        cin >> name;
        cout << "Enter train " << i << " length in carriages: ";
        int length;
        cin >> length;
        cout << "Enter train " << i << " type (freight, passenger): ";
        string type;
        cin >> type;
        depot->registerTrain(name, length, type);
    }
}

void receiveTrain(Depot* depot) {
    cout << "What is the name of the train you would like to receive:" << endl;
    string trainName;
    cin >> trainName;
    depot->receiveTrain(trainName);

}

void newSimulation() {
    cout << "Initialising Train Depot System..." << endl;
    Depot myDepot;

    int menuChoice = 0;

    while (menuChoice == 0) {
        cout << "Train Depot Simulation Menu" << endl;
        cout << "-----------------------" << endl;
        cout << "1. Show Depot Status" << endl;
        cout << "2. Register Trains" << endl;
        cout << "3. Receive Train - Puts train on first free platform in the depot." << endl;
        cout << "7. Exit Program" << endl;
        cout << "-----------------------" << endl;
        cout << "Enter your choice (1,2,3):" << endl;
        cin >> menuChoice;

        if (menuChoice == 1) {
            myDepot.printStatus();
            menuChoice = 0;
        } else if (menuChoice == 2) {
            registerTrains(&myDepot);
            menuChoice = 0;
        } else if (menuChoice == 3) {
            receiveTrain(&myDepot);
            menuChoice = 0;

        } else if (menuChoice == 7) {
            cout << "Exiting Simulation" << endl;
        } else {
            cout << "Invalid choice." << endl;
            menuChoice = 0;
        }
    }

}

int main() {
    int menuChoice = 0;

    while (menuChoice == 0) {
        cout << "Main Menu" << endl;
        cout << "-----------------------" << endl;
        cout << "1. Run Demo Simulation" << endl;
        cout << "2. Start New Depot Simulation" << endl;
        cout << "3. Exit Program" << endl;
        cout << "-----------------------" << endl;
        cout << "Enter your choice (1,2,3):" << endl;
        cin >> menuChoice;

        if (menuChoice == 1) {
            depotDemo();
            menuChoice = 0;

        } else if (menuChoice == 2) {
            newSimulation();
            menuChoice = 0;
        } else if (menuChoice == 3) {
            return 0;
        } else {
            cout << "Invalid choice." << endl;
            menuChoice = 0;
        }
    }
}