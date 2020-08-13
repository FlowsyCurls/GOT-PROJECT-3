cmake_minimum_required(VERSION 3.16)
project(GOT)

set(CMAKE_CXX_STANDARD 14)

find_package(restclient-cpp CONFIG REQUIRED)

add_executable(GOT main.cpp)

target_link_libraries(GOT PRIVATE restclient-cpp)