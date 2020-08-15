cmake_minimum_required(VERSION 3.16)
project(GOT)

set(CMAKE_CXX_STANDARD 14)

find_package(restclient-cpp CONFIG REQUIRED)

add_executable(GOT main.cpp src/Huffman.h src/Commands.h src/FileNode.cpp src/FileNode.h src/Repository.cpp src/Repository.h src/Commands.h src/FileManager.h src/RepositoryList.cpp src/RepositoryList.h)

target_link_libraries(GOT PRIVATE restclient-cpp)