cmake_minimum_required(VERSION 3.28.0)

project(Engine)

set (CMAKE_CXX_STANDARD 17)

add_subdirectory(Core)
add_subdirectory(Api)
add_subdirectory(Console)
add_subdirectory(External)
add_subdirectory(Resources)

set(ASSETS_DIR "${CMAKE_SOURCE_DIR}/Resources/assets")
set(BINARY_DIR "${CMAKE_BINARY_DIR}/Console")
file(COPY ${ASSETS_DIR} DESTINATION ${BINARY_DIR})
