cmake_minimum_required(VERSION 3.10)
project(TemplateLibrary CXX)

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

# Code coverage settings
if(CMAKE_BUILD_TYPE MATCHES Debug)
    # Enable coverage flags
    set(COVERAGE_FLAGS "--coverage")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COVERAGE_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${COVERAGE_FLAGS}")
    
    # Add custom target for code coverage
    add_custom_target(coverage
        COMMAND lcov --ignore-errors inconsistent --capture --directory . --output-file coverage.info
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Generating code coverage report"
        VERBATIM
    )
endif()