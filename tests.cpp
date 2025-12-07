//
// Created by matth on 07/12/2025.
//

#define BOOST_TEST_MODULE TrainTests
#include <boost/test/included/unit_test.hpp>
#include <iostream>
#include "Depot.h"
#include "Platform.h"
#include "Train.h"
#include "Carriage.h"
#include "PassengerCarriage.h"
#include "FreightCarriage.h"
using namespace std;

//Platorm class testing ->

// Test1: tests if that the platform starts out free and that gettrain() is empty
BOOST_AUTO_TEST_CASE(platform_initial_state)
{
    Platform platform(1);
    BOOST_CHECK(platform.isFree());
    BOOST_CHECK(platform.getTrain() == nullptr);
}


// Test2: checks if train is assigned and platform is free the train is assigned to the free slot
// and checks if the free slot is actually taken by the train
BOOST_AUTO_TEST_CASE(platform_assignment)
{
    Platform platform(1);
    Train* a = new Train("Software_train", 2, "freight");

    BOOST_CHECK(platform.assignTrain(a));
    BOOST_CHECK(!platform.isFree());
    BOOST_CHECK(platform.getTrain()->getId() == "Software_train");

}


//Test3: checks that train can't be assigned to already occupied platform must return false
BOOST_AUTO_TEST_CASE(platform_assign_2)
{
    Platform platform(1);
    Train* b = new Train("TrainA", 4, "passenger");
    Train* c = new Train("TrainB", 1, "freight");

    platform.assignTrain(b);
    BOOST_CHECK(!platform.assignTrain(c));

}


// Test4: checks when assigned train is removed removetrain gives us the same train we romvoed
// and then gets if the train was actually removed from platform
BOOST_AUTO_TEST_CASE(platform_remove)
{
    Platform platform(1);
    Train* d = new Train("Train", 5, "passenger");

    platform.assignTrain(d);
    Train* extract = platform.removeTrain();

    BOOST_CHECK(extract == d);
    BOOST_CHECK(platform.isFree());
    BOOST_CHECK(platform.getTrain() == nullptr);
}
//carriage testing ->

//test5: checks carriage ID  is store and that carriage is flagged for repairs correctly
// and when it doesn't need repairs system tells us it doesn't
BOOST_AUTO_TEST_CASE(carriage_functionality)
{
    Carriage carriage("abc");

    BOOST_CHECK(carriage.getId() == "abc");
    BOOST_CHECK(carriage.needsRepairs() == false);

    carriage.flagRepairsNeeded();
    BOOST_CHECK(carriage.needsRepairs() == true);

    carriage.performRepairs();
    BOOST_CHECK(carriage.needsRepairs() == false);
}

// Test6: checks when multiple carriage types declared corectly and inherits repair behaviour properly
BOOST_AUTO_TEST_CASE(multiple_carriages)
{
    Carriage c1("a");
    PassengerCarriage c2("b", 20);
    FreightCarriage c3("c", 200.0);

    BOOST_CHECK(c1.getId() == "a");
    BOOST_CHECK(c2.getId() == "b");
    BOOST_CHECK(c3.getId() == "c");

    c2.flagRepairsNeeded();                   // Passenger carriage flag repair
    BOOST_CHECK(c2.needsRepairs());

    c3.flagRepairsNeeded();                   // Freight carriage flag repair
    BOOST_CHECK(c3.needsRepairs());
}


//Train unit testing ->

// Test5: make sure getlength() returns the correct amount of carriages
BOOST_AUTO_TEST_CASE(train_length)
{
    Train t("ABC", 5, "freight");
    BOOST_CHECK(t.getLength() == 5);
}

// Test6: Train ID is returned correctly as declared
BOOST_AUTO_TEST_CASE(test_train_id)
{
    Train train("Train", 3, "passenger");
    BOOST_CHECK(train.getId() == "Train");
}

//depot testing ->

// Teat8: checks the train register at the depot store  the train correctly
BOOST_AUTO_TEST_CASE(depot_register_and_receive)
{
    Depot depot;

    depot.registerTrain("train", 3, "freight");

    BOOST_CHECK(depot.receiveTrain("train"));
}

// Test9: Depot rejects receiving non registered trains
BOOST_AUTO_TEST_CASE(depot_receive_nonregistered)
{
    Depot depot;
    BOOST_CHECK(!depot.receiveTrain("No_train"));
}

// Test10:checks if depot dispatch removes train from platform
BOOST_AUTO_TEST_CASE(depot_dispatch)
{
    Depot depot;
    depot.registerTrain("departing", 2, "passenger");

    BOOST_CHECK(depot.receiveTrain("departing"));  // puts train on platform 1

    depot.dispatchTrain(1);

    // details of train in platforms is private therefore we just check if we can receive the dispatched train
    BOOST_CHECK(depot.receiveTrain("departing"));
}

//freight + passenger  carriage testing ->

// Test11: tests passenger carriage basic functionality
BOOST_AUTO_TEST_CASE(passenger_carriage_functionality)
{
    PassengerCarriage pasca("pc", 60);

    BOOST_CHECK(pasca.getId() == "pc");
    BOOST_CHECK(!pasca.needsRepairs());

    pasca.flagRepairsNeeded();
    BOOST_CHECK(pasca.needsRepairs());
}

// Test12: tests freight carriage basic functionality
BOOST_AUTO_TEST_CASE(freight_carriage_functionality)
{
    FreightCarriage freca("fc", 105.0);

    BOOST_CHECK(freca.getId() == "fc");
    BOOST_CHECK(!freca.needsRepairs());

    freca.flagRepairsNeeded();
    BOOST_CHECK(freca.needsRepairs());
}

//test13: check the base class pointer carriage works with the derived carriage classes
BOOST_AUTO_TEST_CASE(carriage_polymorphism)
{
    Carriage* carriage1 = new PassengerCarriage("pass", 34);
    Carriage* carriage2 = new FreightCarriage("freight", 86.0);

    BOOST_CHECK(carriage1->getId() == "pass");
    BOOST_CHECK(carriage2->getId() == "freight");

    carriage1->flagRepairsNeeded();
    BOOST_CHECK(carriage1->needsRepairs());

    carriage2->flagRepairsNeeded();
    BOOST_CHECK(carriage2->needsRepairs());

}