cmake_minimum_required(VERSION 3.6)
project(ThreadTest_QuickSort)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c src/QuickSort.c libs/QuickSort.h src/utils.c libs/utils.h src/benchmark.c libs/benchmark.h src/dynstack.c libs/dynstack.h)
add_executable(ThreadTest_QuickSort ${SOURCE_FILES})

target_link_libraries(ThreadTest_QuickSort pthread)
