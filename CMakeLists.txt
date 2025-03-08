cmake_minimum_required(VERSION 4.0)

project(audio_process_tool)

# get operate system
if(UNIX)
    set(PLATFORM unix)
else()
    set(PLATFORM win)
endif()
# set archtecture
if(NOT CMAKE_CXX_FLAGS)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m64")
endif()
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(ARC x64)
else()
    set(ARC x86)
endif()
# set build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE DEBUG)
endif()

message(STATUS "PLATFORM: ${PLATFORM}")
message(STATUS "ARC: ${ARC}")
message(STATUS "BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

# create output directory
set(OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin_${PLATFORM}_${ARC}/${CMAKE_BUILD_TYPE})

add_subdirectory(${PROJECT_SOURCE_DIR}/wave_muxer)