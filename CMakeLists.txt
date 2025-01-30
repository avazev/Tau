cmake_minimum_required(VERSION 3.28)
project(Tau LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(Tau Tau/main.cpp 
                   Tau/canvas/canvas.cpp
                   Tau/brush/brush.cpp
                   Tau/renderer/renderer.cpp
                   Tau/ui/slider/slider.cpp
                   Tau/ui/palette/palette.cpp
                   Tau/fileManager/fileManager.cpp)

target_compile_features(Tau PRIVATE cxx_std_17)
target_link_libraries(Tau PRIVATE SFML::Graphics)
target_link_libraries(Tau PRIVATE SFML::System)