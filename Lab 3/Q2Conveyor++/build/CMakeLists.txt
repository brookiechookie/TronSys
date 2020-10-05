cmake_minimum_required(VERSION 3.10)
project(Q2Conveyor++)
set(CMAKE_CXX_FLAGS "-Wall")

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

include_directories(
    "${PROJECT_SOURCE_DIR}/src"
    "${PROJECT_SOURCE_DIR}/include"
)

add_executable(Conv
    ${PROJECT_SOURCE_DIR}/src/main.cpp
    ${PROJECT_SOURCE_DIR}/src/Conveyor.cpp
    ${PROJECT_SOURCE_DIR}/src/LoadingRobot.cpp
    ${PROJECT_SOURCE_DIR}/src/ProcessingRobot.cpp
    ${PROJECT_SOURCE_DIR}/src/Item.cpp
    ${PROJECT_SOURCE_DIR}/src/IndiItem.cpp
)
