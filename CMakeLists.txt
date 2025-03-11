cmake_minimum_required(VERSION 4.0)

project(audio_process_tool)

set(CMAKE_CXX_STANDARD 11)

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
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE DEBUG)
endif()

message(STATUS "PLATFORM: ${PLATFORM}")
message(STATUS "ARC: ${ARC}")
message(STATUS "C++ VERSION:${CMAKE_CXX_STANDARD}")
message(STATUS "BUILD_TYPE: ${CMAKE_BUILD_TYPE}")

set(BIN_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin_${PLATFORM}_${ARC}/${CMAKE_BUILD_TYPE})
set(LIB_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib_${PLATFORM}_${ARC}/${CMAKE_BUILD_TYPE})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_OUTPUT_PATH})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIB_OUTPUT_PATH})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${LIB_OUTPUT_PATH})

add_subdirectory(${PROJECT_SOURCE_DIR}/wave_encapsule)
add_subdirectory(${PROJECT_SOURCE_DIR}/audio_process)