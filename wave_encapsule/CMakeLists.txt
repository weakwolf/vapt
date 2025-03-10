cmake_minimum_required(VERSION 4.0)

project(wave_muxer)

include_directories(../audio_process/include)
include_directories(../include)
link_directories(${LIB_OUTPUT_PATH})

aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LIST)

add_executable(wave_muxer ${SRC_LIST})

target_link_libraries(wave_muxer audioprocess)