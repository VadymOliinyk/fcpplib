cmake_minimum_required(VERSION 3.10.1)

project(demo)
add_executable(demo main.cpp)
target_link_libraries(demo fcpp)
target_include_directories(demo PRIVATE ../include/)
