cmake_minimum_required(VERSION 3.16)

project(Cpp-Data-Stuctures LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(Cpp-Data-Stuctures SHARED
  Cpp-Data-Stuctures_global.h
  datastructures.cpp
  datastructures.h
  node.hpp
  bst.hpp
  array.hpp

)
add_executable(
  bst_test
  datastructures.h
  node.hpp
  bst.hpp
  tests/bst_test.cpp)
add_executable(
  array_test
  datastructures.h
  tests/array_test.cpp
)
target_compile_definitions(Cpp-Data-Stuctures PRIVATE CPP_DATA_STUCTURES_LIBRARY)
