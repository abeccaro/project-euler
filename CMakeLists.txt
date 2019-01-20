cmake_minimum_required(VERSION 3.9)
project(project_euler)

set(CMAKE_CXX_STANDARD 11)

# private lib
add_library(lib INTERFACE)
target_include_directories(lib INTERFACE src/utilities)

# boost
set(BOOST_ROOT "/Library/Boost")
find_package(Boost 1.65.1)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
endif()

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
foreach(i RANGE 101 121)
    SET(NAME "problem${i}")
    SET(SRC_PATH "src/problems/101-150/${i}/")
    LIST(APPEND PROBLEMS ${SRC_PATH}${NAME}.cpp ${SRC_PATH}${NAME}.hpp)
    LIST(APPEND TESTS tests/101-150/test_${NAME}.cpp)
endforeach(${i})

add_executable(all_tests tests/all_tests.cpp ${PROBLEMS} ${TESTS})
target_link_libraries(all_tests lib)
