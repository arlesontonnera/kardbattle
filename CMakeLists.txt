cmake_minimum_required(VERSION 3.9.0)
project(KardBattle)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS ON)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui Qml)

add_executable(${PROJECT_NAME} "kardbattle.cpp")

include_directories(${CMAKE_INCLUDE_CURRENT_DIR})


set(LIB_CORE kbCore)

add_library(
    ${LIB_CORE}
    STATIC
    board.cpp
    card.cpp
    deck.cpp
    display.cpp
    player.cpp
    rules.cpp
    game.cpp
    )

target_link_libraries(
    ${LIB_CORE}
    PRIVATE
    Qt5::Core
    )
target_compile_features(${LIB_CORE} PRIVATE cxx_std_14)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    ${LIB_CORE}
    Qt5::Core
    )
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_14)
