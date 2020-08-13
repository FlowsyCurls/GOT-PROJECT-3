cmake_minimum_required(VERSION 3.17)
project(Cliente)

set(CMAKE_CXX_STANDARD 14)

find_package(restclient-cpp CONFIG REQUIRED)

add_executable(Cliente main.cpp)

target_link_libraries(Cliente PRIVATE restclient-cpp)