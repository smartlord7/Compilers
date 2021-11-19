cmake_minimum_required(VERSION 3.19)
project(Compilers C)

set(CMAKE_C_STANDARD 11)

include_directories(src)
include_directories(src/data_structures)
include_directories(src/util)

#[[add_executable(Compilers
        src/data_structures/array_list.c
        src/data_structures/array_list.h
        src/util/error_handling.c
        src/util/error_handling.h
        src/util/token_type.c
        src/util/token_type.h)]]

add_executable(ArrayList.test src/data_structures/array_list.c src/data_structures/array_list.h src/tests/array_list.test.c)
