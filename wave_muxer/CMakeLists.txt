cmake_minimum_required(VERSION 4.0)

project(wave_muxer)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "DEBUG")
endif()


set(CMAKE_CXX_STANDARD 11)

aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LIST)

add_executable(wave_muxer ${SRC_LIST})