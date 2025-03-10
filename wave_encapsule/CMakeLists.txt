cmake_minimum_required(VERSION 4.0)

project(wave_encapsule)

include_directories(../audio_process/include)
include_directories(../include)
link_directories(${LIB_OUTPUT_PATH})

aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LIST)

add_executable(wavcaps ${SRC_LIST})

target_link_libraries(wavcaps audioproc)