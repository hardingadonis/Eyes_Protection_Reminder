cmake_minimum_required(VERSION 3.10.2)

project(EPR)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (WIN32)
    set(EPR_OS Windows)
elseif(UNIX AND NOT APPLE)
    set(EPR_OS Linux)
elseif(APPLE)
    set(EPR_OS macOS)
endif()

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(EPR_ARCH x64)
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    set(EPR_ARCH x86)
endif()

set(EPR_SOURCE_HEADERS  ${CMAKE_CURRENT_SOURCE_DIR}/include/UI/EPR_icon_64.xpm
                        ${CMAKE_CURRENT_SOURCE_DIR}/include/UI/EPR_icon_512.xpm
                        ${CMAKE_CURRENT_SOURCE_DIR}/include/UI/MainFrame.hpp
                        ${CMAKE_CURRENT_SOURCE_DIR}/include/UI/MainPanel.hpp
                        ${CMAKE_CURRENT_SOURCE_DIR}/include/UI/SettingsDialog.hpp
                        ${CMAKE_CURRENT_SOURCE_DIR}/include/UI/TaskBarIcon.hpp
                        ${CMAKE_CURRENT_SOURCE_DIR}/include/Utils/Config.hpp
                        ${CMAKE_CURRENT_SOURCE_DIR}/include/Utils/Singleton.hpp
                        ${CMAKE_CURRENT_SOURCE_DIR}/include/Application.hpp)

set(EPR_SOURCE_SRCS     ${CMAKE_CURRENT_SOURCE_DIR}/src/UI/MainFrame.cpp
                        ${CMAKE_CURRENT_SOURCE_DIR}/src/UI/MainPanel.cpp
                        ${CMAKE_CURRENT_SOURCE_DIR}/src/UI/SettingsDialog.cpp
                        ${CMAKE_CURRENT_SOURCE_DIR}/src/UI/TaskBarIcon.cpp
                        ${CMAKE_CURRENT_SOURCE_DIR}/src/Utils/Config.cpp
                        ${CMAKE_CURRENT_SOURCE_DIR}/src/Application.cpp)

set(EPR_SOURCES ${EPR_SOURCE_HEADERS} ${EPR_SOURCE_SRCS})

set(EPR_ICON ${CMAKE_SOURCE_DIR}/assets/EPR_icon.rc)

add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${EPR_SOURCES} ${EPR_ICON})
target_link_libraries(${PROJECT_NAME} PUBLIC wx::core wx::base)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME Eyes_Protection_Reminder_v4.1.0.${EPR_OS}.${EPR_ARCH})