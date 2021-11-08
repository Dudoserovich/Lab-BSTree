cmake_minimum_required(VERSION 3.19)
project(AVL_tree)

set(CMAKE_CXX_STANDARD 20)

include_directories(src)

add_executable(AVL_tree main.cpp src/BSTree.cpp src/BSTree.h)