cmake_minimum_required(VERSION 3.9.0)

if (POLICY CMP0025)
  cmake_policy(SET CMP0025 NEW)
endif ()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS ON)

project(KardBattle)

add_executable(${PROJECT_NAME} kardbattle.cpp)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)

set(LIB_CORE kb_core)

add_library(
    ${LIB_CORE}
    STATIC
    board.cpp
    card.cpp
    deck.cpp
    display.cpp
    player.cpp
    rules.cpp
    )

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    ${LIB_CORE}
    Qt5::Core
    Qt5::Gui
    )

set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES
    CMAKE_CXX_STANDARD
    CMAKE_CXX_EXTENSIONS
    CXX_STANDARD_REQUIRED YES
    )
