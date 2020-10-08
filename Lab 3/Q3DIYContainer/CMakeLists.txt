cmake_minimum_required(VERSION 3.10)
project(Q3DIYContainer)
set(CMAKE_CXX_FLAGS "-Wall")

add_executable(OuiOui main.cpp Conveyor.cpp LoadingRobot.cpp ProcessingRobot.cpp Item.cpp DoublyLinkedList.cpp)
