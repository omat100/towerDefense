add_executable(Hellscape
    src/main.cpp
    src/Graphics/Shader.cpp
    src/Renderer/triangle.cpp
)

target_include_directories(Hellscape PRIVATE
    include
    src
)