cmake_minimum_required(VERSION 3.14)
project(bigo_kurmasza)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(matrixSearchMain matrixSearchMain.cpp)
add_executable(matrixSearchTest matrixSearchSampleTest.cpp)

add_executable(maxSubsequenceMain maxSubsequenceMain.cpp)
add_executable(maxSubSequenceTest maxSubsequenceSampleTest.cpp)
