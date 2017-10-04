cmake_minimum_required(VERSION 3.8)
project(Huffman)

set(CMAKE_C_STANDARD 99)

set(PLOT Plot/mainPlot.c Plot/LinkedList.c Plot/LinkedList.h Plot/BST.c Plot/BST.h)
set(HUFF Huff/BinaryTree.c Huff/BinaryTree.h Huff/mainHuff.c Huff/Compress.c Huff/Compress.h Huff/Compress.c Huff/Compress.h Huff/Decompress.c Huff/Decompress.h)
add_executable(Plotagem ${PLOT})
add_executable(Huffman ${HUFF})