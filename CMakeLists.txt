cmake_minimum_required(VERSION 2.8.12)

project(Eyes_Protection_Reminder VERSION 4.0.0)

add_subdirectory(libs/wxWidgets-3.1.6)
add_executable(EPR src/main.cpp)
target_link_libraries(EPR wx::net wx::core wx::base)