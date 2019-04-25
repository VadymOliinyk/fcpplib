cmake_minimum_required(VERSION 3.10.1)

project(fcpplib)



include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}/include/fcpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    )


add_library(fcpplib STATIC

    ${CMAKE_CURRENT_SOURCE_DIR}/src/testmessanger.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/src/testmessanger.h

    ${CMAKE_CURRENT_SOURCE_DIR}/include/fcpp/fcpp.h
    )

set_target_properties(fcpplib PROPERTIES LINKER_LANGUAGE CXX)


add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/demo)

