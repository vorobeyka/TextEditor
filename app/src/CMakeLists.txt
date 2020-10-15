cmake_minimum_required(VERSION 3.16.1)

set(NAME app)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)
file(GLOB SOURCE *.cpp)#settingsdialog.ui mainwindow.ui)

add_library(${NAME} STATIC ${SOURCE})
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
target_link_libraries(${NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
