cmake_minimum_required(VERSION 3.16)

project(Lab14_GUI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

add_executable(Lab14_GUI
    main.cpp
    MainWindow.cpp
    MainWindow.h
    MainWindow.ui
    FilesLogic.cpp
    FilesLogic.h
)

target_link_libraries(Lab14_GUI PRIVATE Qt6::Widgets)
