cmake_minimum_required(VERSION 3.10.2)

project(EPR)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EPR_SOURCE_HEADERS  ${CMAKE_CURRENT_SOURCE_DIR}/include/UI/EPR_icon_64.xpm
                        ${CMAKE_CURRENT_SOURCE_DIR}/include/UI/EPR_icon_512.xpm
                        ${CMAKE_CURRENT_SOURCE_DIR}/include/UI/MainFrame.hpp
                        ${CMAKE_CURRENT_SOURCE_DIR}/include/UI/MainPanel.hpp
                        ${CMAKE_CURRENT_SOURCE_DIR}/include/UI/SettingsDialog.hpp
                        ${CMAKE_CURRENT_SOURCE_DIR}/include/UI/TaskBarIcon.hpp
                        ${CMAKE_CURRENT_SOURCE_DIR}/include/Application.hpp)

set(EPR_SOURCE_SRCS     ${CMAKE_CURRENT_SOURCE_DIR}/src/UI/MainFrame.cpp
                        ${CMAKE_CURRENT_SOURCE_DIR}/src/UI/MainPanel.cpp
                        ${CMAKE_CURRENT_SOURCE_DIR}/src/UI/SettingsDialog.cpp
                        ${CMAKE_CURRENT_SOURCE_DIR}/src/UI/TaskBarIcon.cpp
                        ${CMAKE_CURRENT_SOURCE_DIR}/src/Application.cpp)

set(EPR_SOURCES ${EPR_SOURCE_HEADERS} ${EPR_SOURCE_SRCS})

add_executable(${PROJECT_NAME} WIN32 ${EPR_SOURCES})
target_link_libraries(${PROJECT_NAME} PUBLIC wx::core wx::base wx::net)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "Eyes_Protection_Reminder_v4.1.0")