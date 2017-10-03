cmake_minimum_required(VERSION 3.8)
project(Huffman)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES Plot/main.c Plot/LinkedList.c Plot/LinkedList.h Plot/BST.c Plot/BST.h)
add_executable(Huffman ${SOURCE_FILES})