project(SEM3_DSA_C C)
set(CMAKE_C_STANDARD 23)
cmake_minimum_required(VERSION 3.23)


# Add libraries
set(LIBS "LIBBIN" "LIBTEST")
file(GLOB LIB_SOURCES lib/*.c)
file(GLOB LIB_HEADERS lib/*.h)
foreach (LIB ${LIBS})
    add_library(${LIB} ${LIB_SOURCES} ${LIB_HEADERS})
    target_include_directories(${LIB} PUBLIC ${PROJECT_SOURCE_DIR}/lib)
endforeach ()

# Add executables
add_executable(main main.c)
file(GLOB SOURCE_FILES RELATIVE ${PROJECT_SOURCE_DIR}/examples examples/*.c)
foreach (SOURCE ${SOURCE_FILES})
    string(REPLACE ".c" "" BIN ${SOURCE})
    target_compile_definitions(LIBBIN PRIVATE DEBUG)
    add_executable(${BIN} examples/${SOURCE})
    target_link_libraries(${BIN} LIBBIN)
endforeach ()


# Add tests
file(GLOB TEST_FILES RELATIVE ${PROJECT_SOURCE_DIR}/lib lib/*.test.c)
foreach (TEST_SOURCE ${TEST_FILES})
    string(REPLACE ".test.c" "" TEST ${TEST_SOURCE})
    add_executable(test_${TEST} EXCLUDE_FROM_ALL lib/${TEST_SOURCE})
    target_link_libraries(test_${TEST} LIBTEST)
    add_test(${TEST} test_${TEST})
endforeach ()
enable_testing()
