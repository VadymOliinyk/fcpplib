cmake_minimum_required(VERSION 3.10.1)

project(demo)
find_package(CURL REQUIRED)
set(CURL_LIBRARY "-lcurl")


add_executable(demo main.cpp)
target_link_libraries(demo fcpp ${CURL_LIBRARIES})
target_include_directories(demo PRIVATE ../include/)



