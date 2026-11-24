cmake_minimum_required(VERSION 3.16)

project(TowerDefense LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

set(SFML_STATIC_LIBRARIES FALSE)

set(IMGUI_DIR "${CMAKE_CURRENT_SOURCE_DIR}/third-party/imgui")
add_subdirectory(third-party/imgui-sfml)

add_executable(TowerDefense
    src/main.cpp
    src/Core/Game.cpp
    src/Core/GameWorld.cpp
    src/SFML/Renderer.cpp
    src/SFML/Window.cpp
    src/SFML/InputHandler.cpp
    src/defense/Block.cpp
    src/attack/Block.cpp
    src/sytems/Intelligence.cpp
    src/sytems/Combat.cpp
    src/sytems/Movement.cpp
    src/sytems/Vector.cpp
    src/types/GameObjects.cpp
    src/base/UI/Screen.cpp
    src/base/UI/SceneBuilderUI.cpp
    src/base/SceneCreator.cpp
)

target_link_libraries(TowerDefense PRIVATE
    sfml-graphics
    sfml-window
    sfml-system
    ImGui-SFML::ImGui-SFML
)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(TowerDefense PRIVATE
        -fsanitize=address
        -fno-omit-frame-pointer
        -g
    )

    target_link_options(TowerDefense PRIVATE
        -fsanitize=address
    )
endif()