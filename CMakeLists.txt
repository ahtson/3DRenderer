cmake_minimum_required(VERSION 3.31)

project(3DRenderer_from_scratch)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

#find_package(Eigen3 REQUIRED)
#include_directories(${EIGEN3_INCLUDE_DIR})

include_directories(${CMAKE_SOURCE_DIR}/Eigen)

file(GLOB_RECURSE HEADERS src/*.h)
file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(3DRenderer_from_scratch ${SOURCES})

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)
target_link_libraries(3DRenderer_from_scratch sfml-system sfml-graphics sfml-window)

# enable_testing()
# add_subdirectory(tests)

install(TARGETS 3DRenderer_from_scratch DESTINATION bin)