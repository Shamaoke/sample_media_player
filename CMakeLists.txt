
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
    Multimedia
    Qml
)

qt_standard_project_setup(REQUIRES 6.4)

set(
  SOURCES
    main.cpp
)

add_executable(sample_media_player ${SOURCES})

set_source_files_properties(Style.qml PROPERTIES QT_QML_SINGLETON_TYPE TRUE)

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
  RESOURCE_PREFIX "/"
  PLUGIN_TARGET sample_player_plugin
  OUTPUT_DIRECTORY SamplePlayer
  SOURCES
    sample_player.hpp
    sample_player.cpp
  STATIC
)

qt_add_qml_module(
  styles
  VERSION 1.0
  URI Styles
  RESOURCE_PREFIX "/"
  PLUGIN_TARGET styles_plugin
  OUTPUT_DIRECTORY Styles
  QML_FILES
    Style.qml
  STATIC
)

target_link_libraries(
  sample_player

  PRIVATE
    Qt::Multimedia
    Qt::Qml
)

target_link_libraries(
  sample_media_player

  PRIVATE
    Qt::Core
    Qt::Gui
    Qt::Qml

    sample_player_plugin
    styles_plugin
)

