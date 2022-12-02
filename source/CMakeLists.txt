cmake_minimum_required(VERSION 3.10.2)

project(EPR)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EPR_SOURCE_HEADERS  ${CMAKE_CURRENT_SOURCE_DIR}/include/Application.hpp)

set(EPR_SOURCE_SRCS     ${CMAKE_CURRENT_SOURCE_DIR}/src/Application.cpp)

set(EPR_SOURCES ${EPR_SOURCE_HEADERS} ${EPR_SOURCE_SRCS})

add_executable(${PROJECT_NAME} WIN32 ${EPR_SOURCES})
link_libraries(wx::net wx::core wx::base)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

if (MSVC)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
endif()