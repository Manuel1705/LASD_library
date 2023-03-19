cmake_minimum_required(VERSION 3.24)
project(LASD_library C)

set(CMAKE_C_STANDARD 11)

add_executable(LASD_library main.c heapSort.c insertionSort.c insertionSort/insertionSort.c heapSort/heapSort.c prova/prova.c)
