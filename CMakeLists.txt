cmake_minimum_required(VERSION 3.6)

project(FerrisFileIndexer)

#include(build/conanbuildinfo.cmake)
#conan_basic_setup()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES main.cpp)

add_executable(FerrisFileIndexer src/${SOURCE_FILES})

#target_link_libraries(FerrisFileIndexer ${CONAN_LIBS})