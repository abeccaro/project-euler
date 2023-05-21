cmake_minimum_required(VERSION 3.25)
project(project_euler)

set(CMAKE_CXX_STANDARD 23)

# private lib
add_library(lib INTERFACE)
target_include_directories(lib INTERFACE src/utilities)

# boost
# set(Boost_USE_STATIC_LIBS OFF)
include_directories(${Boost_INCLUDE_DIR})
find_package (Boost COMPONENTS unit_test_framework REQUIRED)

SET(PROBLEMS "")
SET(TESTS "")

SET(CURRENT_PROBLEM "171")
SET(CURRENT_FILE "src/problems/151-200/${CURRENT_PROBLEM}/problem${CURRENT_PROBLEM}")

# problems 1-50
foreach(i RANGE 1 50)
    SET(NAME "problem${i}")
    SET(SRC_PATH "src/problems/1-50/${i}/")
    LIST(APPEND PROBLEMS ${SRC_PATH}${NAME}.cpp ${SRC_PATH}${NAME}.hpp)
    LIST(APPEND TESTS tests/1-50/test_${NAME}.cpp)
endforeach(i)

# problems 51-100
foreach(i RANGE 51 100)
    SET(NAME "problem${i}")
    SET(SRC_PATH "src/problems/51-100/${i}/")
    LIST(APPEND PROBLEMS ${SRC_PATH}${NAME}.cpp ${SRC_PATH}${NAME}.hpp)
    LIST(APPEND TESTS tests/51-100/test_${NAME}.cpp)
endforeach(i)

# problems 101-150
foreach(i RANGE 101 150)
    SET(NAME "problem${i}")
    SET(SRC_PATH "src/problems/101-150/${i}/")
    LIST(APPEND PROBLEMS ${SRC_PATH}${NAME}.cpp ${SRC_PATH}${NAME}.hpp)
    LIST(APPEND TESTS tests/101-150/test_${NAME}.cpp)
endforeach(i)

# problems 151-200
foreach(i RANGE 151 ${CURRENT_PROBLEM})
    SET(NAME "problem${i}")
    SET(SRC_PATH "src/problems/151-200/${i}/")
    LIST(APPEND PROBLEMS ${SRC_PATH}${NAME}.cpp ${SRC_PATH}${NAME}.hpp)
    LIST(APPEND TESTS tests/151-200/test_${NAME}.cpp)
endforeach(i)

#all tests executable
add_executable(all_tests tests/all_tests.cpp ${PROBLEMS} ${TESTS})
target_link_libraries(all_tests lib ${Boost_LIBRARIES})

#current problem tests executable
add_executable(current tests/all_tests.cpp ${CURRENT_FILE}.cpp ${CURRENT_FILE}.hpp tests/151-200/test_problem${CURRENT_PROBLEM}.cpp)
target_link_libraries(current lib ${Boost_LIBRARIES})
