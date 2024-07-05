cmake_minimum_required(VERSION 3.28.0)

project(Console)

find_package(glfw3)

add_executable(${PROJECT_NAME} "main.cpp")
target_link_libraries(${PROJECT_NAME} PRIVATE Core glfw glad)
