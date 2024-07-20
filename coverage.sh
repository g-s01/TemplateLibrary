#!/bin/sh

PROJECT_ROOT=$(pwd)

# Set the build directory
BUILD_DIR="build"

# Create the build directory if it does not exist
if [ ! -d "$BUILD_DIR" ]; then
  mkdir $BUILD_DIR
fi

# Navigate to the build directory
cd $BUILD_DIR

# Run CMake to configure the project
cmake -DCMAKE_BUILD_TYPE=Debug ..

# Build the project
make

# Run the tests
./tests

# make coverage
make coverage

lcov --remove coverage.info "/opt/homebrew/include/gtest/*" "/v1/*" "test/*" --output-file coverage.cleaned.info

# Generate HTML report
genhtml coverage.cleaned.info --output-directory out

# Navigate back to the project root
cd ..

# Print message on completion
echo "Code coverage report generated in the 'out' directory."

# Open the coverage report in the default browser
open build/out/index.html