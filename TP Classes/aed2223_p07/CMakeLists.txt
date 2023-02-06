cmake_minimum_required(VERSION 3.10)
project(aed2223_p07)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)
add_subdirectory(lib/benchmark)
include_directories(lib/benchmark/include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Tests")

add_executable(aed2223_p07 main.cpp Tests/tests.cpp Tests/dictionary.cpp Tests/funSetProblem.cpp)

target_link_libraries(aed2223_p07 gtest gtest_main benchmark benchmark_main)
