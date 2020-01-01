cmake_minimum_required(VERSION 3.2.3) 
project(ROVER LANGUAGES CXX)
enable_testing()
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-g -std=c++11 -lpthread")

find_package(PkgConfig REQUIRED)
pkg_check_modules(gtest REQUIRED gtest>=1.8.1)
pkg_check_modules(gmock REQUIRED gmock>=1.8.1)

include_directories(${gtest_INCLUDE_DIRS} ${gmock_INCLUDE_DIRS})
add_subdirectory(TEST)
add_executable(rover.out  main.cpp)

target_link_libraries(rover.out ${gtest_LIBRARIES} ${gmock_LIBRARIES})
