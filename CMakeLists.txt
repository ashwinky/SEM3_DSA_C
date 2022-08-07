cmake_minimum_required(VERSION 3.23)
project(SEM3_DSA_C C)

set(CMAKE_C_STANDARD 23)

add_executable(SEM3_DSA_C main.c lib)

add_executable(tests tests.c lib)
add_test(tests tests)

enable_testing()
