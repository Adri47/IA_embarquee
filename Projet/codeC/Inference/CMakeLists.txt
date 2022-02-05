cmake_minimum_required(VERSION 2.8)
project(ProjetIA)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")
include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src
)

file(GLOB SRC_FILES
        ${PROJECT_SOURCE_DIR}/include/*.h
        ${PROJECT_SOURCE_DIR}/src/*.c
    )
add_executable(ProjetIA ${SRC_FILES})
target_link_libraries(ProjetIA PRIVATE m)