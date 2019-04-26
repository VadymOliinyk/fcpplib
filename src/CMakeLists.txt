set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Declare the library
add_library(${PROJECT_NAME} STATIC
    testmessanger.cpp
    markets.cpp

    # Headers for IDE (t.d. remove latter)
    testmessanger.h
    markets.h
    )

target_include_directories(${PROJECT_NAME}
    PRIVATE src
    PUBLIC ${FCPP_INCLUDE_DIRS})

message(STATUS ${FCPPLIB_PROJECT_DIR})


set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER
    "${PROJECT_SOURCE_DIR}/include/fcpp/fcpp.h")


set_target_properties(fcpp PROPERTIES LINKER_LANGUAGE CXX)

#target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
#target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)