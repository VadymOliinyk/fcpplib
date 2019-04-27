set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(CURL REQUIRED)
set(CURL_LIBRARY "-lcurl")

# Declare the library
add_library(${PROJECT_NAME} STATIC
    request.cpp)

target_include_directories(${PROJECT_NAME}
    PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${FCPP_INCLUDE_DIRS}>
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CURL_INCLUDE_DIRS}
    ${JSON_INCLUDE_DIRS}
    )

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER
    "${PROJECT_SOURCE_DIR}/include/fcpp/fcpp.h")


set_target_properties(fcpp PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(${PROJECT_NAME} ${CURL_LIBRARIES} nlohmann_json::nlohmann_json)
