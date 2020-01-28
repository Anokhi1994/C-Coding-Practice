cmake_minimum_required(VERSION 3.2.3) 
project(Observable CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -g -std=c++17")
list(APPEND flags_ "-std=c++17" "-Wall" "-Wpedantic" "-Werror" "-g")
add_executable(result.out  main.cpp)
target_compile_options(result.out
                      PRIVATE
                      ${flags_})
