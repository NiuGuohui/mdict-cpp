# Set the minimum required CMake version
CMAKE_MINIMUM_REQUIRED(VERSION 3.10) # for windows XP compatibility

# Set the project name
PROJECT(MDictCpp VERSION 1.0.0)

# C++ standard
set(CMAKE_CXX_STANDARD 17) # for windows XP compatibility
set(CMAKE_CXX_STANDARD_REQUIRED YES)

# Set build type and compilation flags
SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb --std=c++17 ")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall --std=c++17 ")

# Set output directories
SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/lib)

ADD_COMPILE_OPTIONS(-Wno-unused-variable -fpermissive)

# Add include directories
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/deps/ ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Add library search directories
LINK_DIRECTORIES(/usr/local/lib ${CMAKE_CURRENT_BINARY_DIR}/lib)

# Add subdirectories
ADD_SUBDIRECTORY(deps)
ADD_SUBDIRECTORY(tests)

# Library target: mdict
ADD_LIBRARY(mdict STATIC mdict.cc binutils.cc xmlutils.cc ripemd128.c adler32.cc mdict_extern.cc)
target_link_libraries(mdict PRIVATE miniz base64)

# Executable target: mydict (for development/testing purposes only)
ADD_EXECUTABLE(mydict mdict.cc binutils.cc xmlutils.cc ripemd128.c adler32.cc mdict_extern.cc mdict_extern_test.cc)
target_link_libraries(mydict PRIVATE miniz base64)