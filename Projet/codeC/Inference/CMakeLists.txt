cmake_minimum_required(VERSION 2.8)
project(ProjetSimpleCMake)
include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src
)

file(GLOB SRC_FILES
        ${PROJECT_SOURCE_DIR}/include/*.h
        ${PROJECT_SOURCE_DIR}/src/*.c
    )
add_executable(ProjetIA ${SRC_FILES})