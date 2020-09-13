cmake_minimum_required (VERSION 3.8)
include(Project.cmake)
project(${CMAKE_PROJECT_NAME} VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}.${PROJECT_VERSION_TWEAK})

# set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

SET(NDEBUG false CACHE STRING "Set to true to disable debug related items such as assertions")
add_definitions(-DNDEBUG=${NDEBUG})
message("NDEBUG=${NDEBUG}")

set(source_dir "${PROJECT_SOURCE_DIR}")

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(MACOSX TRUE)
endif()

if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

if (WIN32)
    message("CMAKE DETECTED WINDOWS")
    set(CMAKE_CXX_STANDARD 20)
    set_directory_properties(PROPERTIES
        VS_STARTUP_PROJECT ${PROJECT_NAME}
    )
elseif(LINUX)
    set(CMAKE_C_COMPILER "/usr/bin/gcc-10")
    set(CMAKE_CXX_COMPILER "/usr/bin/g++-10")
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
elseif(MACOSX)
    message("CMAKE DETECTED MACOSX")
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a")
endif()

#must remember to regenerate the project on adding files
file(GLOB_RECURSE SRCS *.cc)
file(GLOB_RECURSE HDRS *.h)

add_executable (${CMAKE_PROJECT_NAME} "main.cc" "main.h" ${SRCS} ${HDRS})

find_package(Threads REQUIRED)
set(THREADS_PREFER_PTHREAD_FLAG ON)

target_link_libraries(
    ${CMAKE_PROJECT_NAME}
    Threads::Threads
)

include_directories(${CMAKE_SOURCE_DIR})

set(BUILD_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/project)
set(CMAKE_BUILD_FILES_DIRECTORY ${BUILD_DIRECTORY})
set(CMAKE_BUILD_DIRECTORY ${BUILD_DIRECTORY})
