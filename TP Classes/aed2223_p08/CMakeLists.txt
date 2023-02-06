cmake_minimum_required(VERSION 3.10)
project(aed2223_p08)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(aed2223_p08 main.cpp Tests/tests.cpp Tests/box.cpp Tests/packagingMachine.cpp Tests/funPQProblem.cpp)

target_link_libraries(aed2223_p08 gtest gtest_main)
