cmake_minimum_required(VERSION 3.16)
project(Cpp-Data-Structures LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Header-only files (templates)
set(HEADER_FILES
    bin-tree.hpp
    bst.hpp
    array.hpp
    node.hpp
    utils.h

)

# Compiled library files
set(SOURCE_FILES
    a.c        # if this is your only compiled source
    # add other .cpp/.c files here if needed
)

# Add library (compiled only)
add_library(Cpp-Data-Structures INTERFACE
    ${HEADER_FILES}   # just for IDE visibility, won't be compiled
)

# Add executables
add_executable(bst_test tests/bst_test.cpp)
target_link_libraries(bst_test PRIVATE Cpp-Data-Structures)

add_executable(array_test tests/array_test.cpp)
target_link_libraries(array_test PRIVATE Cpp-Data-Structures)

add_executable(bintree_test tests/bintree_test.cpp)
target_link_libraries(bintree_test PRIVATE Cpp-Data-Structures)

