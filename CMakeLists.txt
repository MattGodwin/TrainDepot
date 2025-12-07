cmake_minimum_required(VERSION 3.20)
project(TrainDepot-master+test)


set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "C:/local/boost_1_89_0") # put your boost path in here
SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "C:/local/boost_1_89_0/libs") # put your boost path in here

add_executable(TrainDepot main.cpp
        Carriage.cpp
        Carriage.h
        Train.cpp
        Train.h
        Platform.cpp
        Platform.h
        Depot.cpp
        Depot.h
        PassengerCarriage.h
        FreightCarriage.h
        Platform.h
)

include_directories(.)

find_package(Boost 1.68.0)

if(Boost_FOUND)


    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")


    include_directories(${Boost_INCLUDE_DIRS})


endif()


add_executable(BoostTest tests.cpp
        Carriage.cpp
        Carriage.h
        Train.cpp
        Train.h
        Platform.cpp
        Platform.h
        Depot.cpp
        Depot.h
        PassengerCarriage.h
        FreightCarriage.h
        Platform.h
        tests.cpp
)


if(Boost_FOUND)

    target_link_libraries(BoostTest ${Boost_LIBRARIES})


endif()
