cmake_minimum_required(VERSION 3.8)
project(Huffman)

set(CMAKE_C_STANDARD 99)
INCLUDE_DIRECTORIES(C:/cunit/include)
LINK_DIRECTORIES(C:/cunit/lib)

set(PLOT Plot/mainPlot.c Plot/LinkedList.c Plot/LinkedList.h Plot/BST.c Plot/BST.h)
set(HUFF Huff/BinaryTree.c Huff/BinaryTree.h Huff/mainHuff.c Huff/Compress.c Huff/Compress.h Huff/Compress.c Huff/Compress.h Huff/Decompress.c Huff/Decompress.h Huff/Helpful.c Huff/Helpful.h)
set(TEST "Test - CUnit/TesteFila.c" "Test - CUnit/BinaryTree.c" "Test - CUnit/BinaryTree.h")

add_executable(Plotagem ${PLOT})
add_executable(Huffman ${HUFF})
add_executable(Testes ${TEST})
target_link_libraries(Testes cunit)