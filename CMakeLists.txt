cmake_minimum_required(VERSION 3.31)

project(3DRenderer_from_scratch)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

set(EIGEN3_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/external/eigen")
include_directories(${EIGEN3_INCLUDE_DIR})

file(GLOB_RECURSE HEADERS src/*.h)
file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(3DRenderer_from_scratch ${SOURCES})

# find_package(SFML 3.0 COMPONENTS system window graphics REQUIRED)
target_link_libraries(3DRenderer_from_scratch sfml-system sfml-graphics sfml-window)

install(TARGETS 3DRenderer_from_scratch DESTINATION bin)
