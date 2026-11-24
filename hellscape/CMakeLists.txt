cmake_minimum_required(VERSION 3.16)

project(Hellscape LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

add_library(glad STATIC
    third-party/glad/src/gl.c
)

target_include_directories(glad PUBLIC
    third-party/glad/include
)

add_executable(Hellscape
    src/main.cpp
)

target_link_libraries(Hellscape PRIVATE
    glfw
    OpenGL::GL
    glad
)
