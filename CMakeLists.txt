cmake_minimum_required(VERSION 3.6)

project(FerrisFileIndexer)

#include(build/conanbuildinfo.cmake)
#conan_basic_setup()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(SOURCE_FILES main.cpp)

SET(BUILD_SHARED_LIBRARIES OFF)
# Link the libraries static to make a executable which can run on non-dev machines
SET(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(FerrisFileIndexer src/${SOURCE_FILES})

#target_link_libraries(FerrisFileIndexer ${CONAN_LIBS})