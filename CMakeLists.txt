
##
## ::: Sample media player | Build control file :::
##

cmake_minimum_required(VERSION 3.25)

project(sample_media_player VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

find_package(
  Qt6 6.4

  COMPONENTS
    Core
    Gui
    Qml
    Multimedia
)

qt_standard_project_setup(REQUIRES 6.4)

set(
  SOURCES
    main.cpp
)

add_executable(sample_media_player ${SOURCES})

qt_add_qml_module(
  sample_media_player
  VERSION 1.0
  URI Components
  RESOURCE_PREFIX "/"
  QML_FILES
    Main.qml
)

qt_add_qml_module(
  sample_player
  VERSION 1.0
  URI SamplePlayer
  PLUGIN_TARGET sample_player_plugin
  OUTPUT_DIRECTORY SamplePlayer
  SOURCES
    sample_player.hpp
    sample_player.cpp
  STATIC
)

target_link_libraries(
  sample_media_player

  PRIVATE
    Qt::Core
    Qt::Gui
    Qt::Qml
    Qt::Multimedia

    sample_player_plugin
)
