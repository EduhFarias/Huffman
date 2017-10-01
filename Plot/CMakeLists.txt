cmake_minimum_required(VERSION 3.8)
project(Plot)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c LinkedList.c LinkedList.h BinaryTree.c BinaryTree.h)
add_executable(Plot ${SOURCE_FILES})