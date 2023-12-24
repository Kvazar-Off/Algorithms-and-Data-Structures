cmake_minimum_required(VERSION 3.25)
project(saf2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(saf2
        Company.cpp
        Company.hpp
        Kurs.cpp
        Program.hpp
        Storage.cpp
        Storage.hpp
        Tram.cpp
        Tram.hpp
        TramPark.cpp
        TramPark.hpp)
