cmake_minimum_required(VERSION 3.16)

project(TowerDefense LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

add_executable(TowerDefense
    src/main.cpp
    src/Core/Game.cpp
    src/Core/Renderer.cpp
    src/SFML/Window.cpp
    src/SFML/InputHandler.cpp
    src/defense/Block.cpp
)

target_link_libraries(TowerDefense PRIVATE
    sfml-graphics
    sfml-window
    sfml-system
)