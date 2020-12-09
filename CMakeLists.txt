cmake_minimum_required(VERSION 3.10)
project(project_euler)

set(CMAKE_CXX_STANDARD 11)

# private lib
add_library(lib INTERFACE)
target_include_directories(lib INTERFACE src/utilities)

# boost
if (WIN32)
    find_package (Boost REQUIRED COMPONENTS unit_test_framework)
else()
    find_package(Boost 1.71.0)
endif()
include_directories(${Boost_INCLUDE_DIR})

SET(PROBLEMS "")
SET(TESTS "")

# problems 1-50
foreach(i RANGE 1 50)
    SET(NAME "problem${i}")
    SET(SRC_PATH "src/problems/1-50/${i}/")
    LIST(APPEND PROBLEMS ${SRC_PATH}${NAME}.cpp ${SRC_PATH}${NAME}.hpp)
    LIST(APPEND TESTS tests/1-50/test_${NAME}.cpp)
endforeach(${i})

# problems 51-100
foreach(i RANGE 51 100)
    SET(NAME "problem${i}")
    SET(SRC_PATH "src/problems/51-100/${i}/")
    LIST(APPEND PROBLEMS ${SRC_PATH}${NAME}.cpp ${SRC_PATH}${NAME}.hpp)
    LIST(APPEND TESTS tests/51-100/test_${NAME}.cpp)
endforeach(${i})

# problems 101-150
foreach(i RANGE 101 147)
    SET(NAME "problem${i}")
    SET(SRC_PATH "src/problems/101-150/${i}/")
    LIST(APPEND PROBLEMS ${SRC_PATH}${NAME}.cpp ${SRC_PATH}${NAME}.hpp)
    LIST(APPEND TESTS tests/101-150/test_${NAME}.cpp)
endforeach(${i})

add_executable(all_tests tests/all_tests.cpp ${PROBLEMS} ${TESTS})
target_link_libraries(all_tests lib)
target_link_libraries(all_tests ${Boost_LIBRARIES})
