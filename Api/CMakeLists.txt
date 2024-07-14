cmake_minimum_required(VERSION 3.28.0)

project(Api)

include_directories(${PROJECT_SOURCE_DIR}/include)
find_package(glfw3 CONFIG REQUIRED)

add_definitions(-DENGINE_EXPORTS)
file(GLOB_RECURSE SOURCE_FILES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)
add_library(engine SHARED src/WindowApi.cpp "src/RenderMapApi.cpp")

target_include_directories(engine PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(engine PUBLIC Core glfw glad)