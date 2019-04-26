set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Declare the library
add_library(${PROJECT_NAME} STATIC
    markets.cpp
    )

target_include_directories(${PROJECT_NAME}
    PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${FCPP_INCLUDE_DIRS}>
#    ${FCPP_INCLUDE_DIRS})
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CPR_INCLUDE_DIRS}
    )


set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER
    "${PROJECT_SOURCE_DIR}/include/fcpp/fcpp.h")


set_target_properties(fcpp PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(${PROJECT_NAME} ${CPR_LIBRARIES})

#target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
#target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
