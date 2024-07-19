cmake_minimum_required(VERSION 3.10)
project(TrieProject CXX)

# Locate Google Test package
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
message(STATUS "GTEST_INCLUDE_DIRS: ${GTEST_INCLUDE_DIRS}")

# Source files for main program and tests
set(SOURCE_FILES 
    src/Trie/trie.cpp
)

# Main executable
add_executable(tests test/trie-test.cpp ${SOURCE_FILES})

# Link Google Test to the test executable
target_link_libraries(tests ${GTEST_LIBRARIES} pthread)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
