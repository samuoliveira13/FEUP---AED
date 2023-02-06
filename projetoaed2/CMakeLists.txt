cmake_minimum_required(VERSION 3.10)
project(projetoaed2)

set(CMAKE_CXX_STANDARD 14)

add_executable(projetoaed2 main.cpp codigo/include/Flights.h codigo/Flights.cpp codigo/include/Airports.h codigo/Airports.cpp codigo/Menu.cpp codigo/Airlines.cpp codigo/include/Airlines.h)
