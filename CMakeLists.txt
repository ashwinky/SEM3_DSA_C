project(SEM3_DSA_C C)
set(CMAKE_C_STANDARD 23)
cmake_minimum_required(VERSION 3.23)


# Add libraries
file(GLOB LIB_SOURCES lib/*.c)
file(GLOB LIB_HEADERS lib/*.h)
add_library(LIB ${LIB_SOURCES} ${LIB_HEADERS})
target_include_directories(LIB PUBLIC ${PROJECT_SOURCE_DIR}/lib)


# Add executables
add_executable(main main.c)
file(GLOB SOURCE_FILES RELATIVE ${PROJECT_SOURCE_DIR}/examples examples/*.c)
foreach (SOURCE ${SOURCE_FILES})
    string(REPLACE ".c" "" BIN ${SOURCE})
    add_executable(${BIN} examples/${SOURCE})
    target_link_libraries(${BIN} LIB)
endforeach ()


# Add tests
add_executable(tests tests.c)
target_link_libraries(tests LIB)
add_test(tests tests)
enable_testing()
