cmake_minimum_required(VERSION 3.28.0)

add_subdirectory(glad)

add_library(stb INTERFACE)

target_include_directories(stb INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/stb)