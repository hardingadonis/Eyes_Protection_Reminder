# Set all file .hpp
set(EPR_HEADER  ${CMAKE_CURRENT_SOURCE_DIR}/application.hpp)

# Set all file .cpp
set(EPR_SRC     ${CMAKE_CURRENT_SOURCE_DIR}/application.cpp)

# Set for all source code of EPR
set(Eyes_Protection_Reminder_SOURCE ${EPR_HEADER} ${EPR_SRC})

# Set icon for EPR
set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_SOURCE_DIR}/assets/EPR_icon.rc")

add_executable(EPR WIN32 ${Eyes_Protection_Reminder_SOURCE} ${APP_ICON_RESOURCE_WINDOWS})
target_link_libraries(EPR wx::net wx::core wx::base)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT EPR)