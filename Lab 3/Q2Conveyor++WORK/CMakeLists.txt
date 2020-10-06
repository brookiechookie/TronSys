cmake_minimum_required(VERSION 3.10)
project(Q2Conveyor++WORK)
set(CMAKE_CXX_FLAGS "-Wall")

add_executable(HelpMe main.cpp Conveyor.cpp LoadingRobot.cpp ProcessingRobot.cpp Item.cpp)
