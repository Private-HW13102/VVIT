cmake_minimum_required(VERSION 3.16)
project(Lab12_Task2_Variant8 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(Lab12_Task2_Variant8
    main.cpp
    mainwindow.h
    mainwindow.cpp
    mainwindow.ui
)

target_link_libraries(Lab12_Task2_Variant8 PRIVATE Qt6::Widgets)

if(WIN32)
    set_target_properties(Lab12_Task2_Variant8 PROPERTIES WIN32_EXECUTABLE TRUE)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
