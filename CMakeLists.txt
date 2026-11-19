cmake_minimum_required(VERSION 3.16)
project(TowerDefense)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

add_executable(TowerDefense
    src/main.cpp
    src/Core/Game.cpp
    src/SFML/Window.cpp
    src/SFML/Renderer.cpp
    src/SFML/InputHandler.cpp
)

target_link_libraries(TowerDefense
    sfml-graphics
    sfml-window
    sfml-system
)