# Set the name and the supported language of the project
set( PROJECT_NAME "twm-session-logout" )
## Set our project name
project(${PROJECT_NAME})
# Set the minimum version of cmake required to build this project
cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++11")

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)

include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

# PROJECT FILES
set(SOURCE_FILES
    main.cpp src/MainWindow.cpp src/MainWindow.h)


add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${CMAKE_PROJECT_NAME} ${GTKMM_LIBRARIES})


install(TARGETS ${PROJECT_NAME} DESTINATION /usr/bin)