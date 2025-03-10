cmake_minimum_required(VERSION 4.0)

project(audio_process)

# export flags
add_definitions(-DAUDIO_PROCESS_EXPORT)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_BASIC_FLAGS} -fvisibility=hidden -fPIC")

aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LIST)

add_library(audioprocess SHARED ${SRC_LIST})