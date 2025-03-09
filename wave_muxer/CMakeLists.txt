cmake_minimum_required(VERSION 4.0)

project(wave_muxer)

aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LIST)

add_executable(wave_muxer ${SRC_LIST})