cmake_minimum_required(VERSION 4.0)

project(video_process)

# export flags
add_definitions(-DVIDEO_PROCESS_EXPORT)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=hidden -fPIC")

aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LIST)

add_library(videoproc SHARED ${SRC_LIST})