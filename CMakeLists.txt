cmake_minimum_required(VERSION 3.10.2)

project(Eyes_Protection_Reminder VERSION 4.0.0)

set(EPR_SRC src/about_dialog.cpp
			src/about_dialog.hpp
			src/application.cpp
			src/application.hpp
			src/main_frame.cpp
			src/main_frame.hpp)

set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_CURRENT_SOURCE_DIR}/assets/EPR_icon.rc")
			
add_subdirectory(libs/wxWidgets)
add_executable(EPR WIN32 ${EPR_SRC} ${APP_ICON_RESOURCE_WINDOWS})
target_link_libraries(EPR wx::net wx::core wx::base)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT EPR)