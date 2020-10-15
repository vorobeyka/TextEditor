cmake_minimum_required(VERSION 3.16.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(NAME utext)
set(SOURCE_EXE main.cpp ./src/resources.qrc ./src/mainwindow.ui ./src/settingsdialog.ui)

project(${NAME})

add_compile_options(
    -Wall
    -Wextra
    -Werror
    -Wpedantic
)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

include_directories(./src)

add_subdirectory(src)
add_executable(${NAME} ${SOURCE_EXE})


target_link_libraries(utext PRIVATE Qt${QT_VERSION_MAJOR}::Widgets app)
