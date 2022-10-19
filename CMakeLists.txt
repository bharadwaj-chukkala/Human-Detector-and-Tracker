cmake_minimum_required(VERSION 3.2.1)
project (scratch)

# Add project cmake modules to path.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

# # We probably don't want this to run on every build.
# option(COVERAGE "Generate Coverage Data" OFF)

# if (COVERAGE)
#     include(CodeCoverage)
#     set(LCOV_REMOVE_EXTRA "'vendor/*'")
#     #<target executable foldeofcoverage>
#     setup_target_for_coverage(code_coverage test/cpp-test coverage)
#     set(COVERAGE_SRCS app/main.cpp include/lib.hpp)

#     # compiler flags to turn off optimization and enable coverage
#     SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
#     SET(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
#     SET(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")
# else()
#     set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -g")
# endif()

include(CMakeToolsHelpers OPTIONAL)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 14)

### Uncomment the line below and specify the path to OpenCV directory i.e. the path to the OpenCVConfig.cmake file. Check the examples given below.
###SET PATH TO OPENCV CMAKE CONFIG FILES
SET(OpenCV_DIR /home/sairamp/installation/OpenCV/installation/OpenCV/lib/cmake/opencv4)

# MAKE SURE OPENCV IS INSTALLED CORRECTLY
find_package( OpenCV REQUIRED )

# # INCLUDE OPENCV DIRECTORIES
# include_directories( ${OpenCV_INCLUDE_DIRS})

# INCLUDE OPENCV DIRECTORIES
include_directories( 
    ${OpenCV_INCLUDE_DIRS})

add_subdirectory(app)
add_subdirectory(test)
add_subdirectory(vendor/googletest/googletest)