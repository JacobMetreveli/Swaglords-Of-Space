cmake_minimum_required(VERSION 3.1)

project(SFML_G3)

find_package(SFML COMPONENTS system audio graphics network window REQUIRED)

include_directories(include)

set(SOURCES
    src/Game.cpp
    src/main.cpp
    src/Player.cpp
)

add_executable(SFML_G2 ${SOURCES})

target_link_libraries(SFML_G2 sfml-system sfml-window sfml-graphics sfml-audio sfml-network)