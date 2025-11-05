cmake_minimum_required(VERSION 4.0)
project(TrainDepot)

set(CMAKE_CXX_STANDARD 20)

add_executable(TrainDepot main.cpp
        Carriage.cpp
        Carriage.h
        Train.cpp
        Train.h
        Platform.cpp
        Platform.h
        Depot.cpp
        Depot.h)
