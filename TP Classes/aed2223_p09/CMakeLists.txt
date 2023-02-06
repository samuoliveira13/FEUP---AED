cmake_minimum_required(VERSION 3.10)
project(aed2223_p09)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)
add_subdirectory(lib/benchmark)
include_directories(lib/benchmark/include)

add_executable(aed2223_p09 main.cpp Tests/tests.cpp Tests/jackpot.cpp Tests/funHashingProblem.cpp)

target_link_libraries(aed2223_p09 gtest gtest_main benchmark benchmark_main)
