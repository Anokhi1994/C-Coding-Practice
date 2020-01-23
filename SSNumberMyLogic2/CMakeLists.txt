cmake_minimum_required(VERSION 3.2.3) 
project(SOCIAL_SECURITY2 CXX)
enable_testing()
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-g -std=c++11 -lpthread")
add_executable(result.out  main.cpp)


