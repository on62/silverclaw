cmake_minimum_required(VERSION 3.13)
project(silverclaw
        VERSION 0.1.0
        DESCRIPTION "gtkmm example app"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

# copy to build dir
configure_file(resources/silverclaw.glade resources/silverclaw.glade COPYONLY)
configure_file(resources/sc_menu.ui resources/sc_menu.ui COPYONLY)

find_package(PkgConfig)
pkg_check_modules(SIGCPP REQUIRED sigc++-2.0)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)
pkg_check_modules(GLIB REQUIRED glib-2.0)

include_directories(
    ${GLIB_INCLUDE_DIRS}
    ${SIGCPP_INCLUDE_DIRS}
    ${GTKMM_INCLUDE_DIRS}
    )

add_executable(silverclaw
        SilverClawApp.cpp
        SilverClawApp.h
        main.cpp)

target_link_libraries(silverclaw
        ${SIGCPP_LIBRARIES}
        ${GTKMM_LIBRARIES}
        ${GLIB_LDFLAGS}
        )

