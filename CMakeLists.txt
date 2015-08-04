cmake_minimum_required (VERSION 2.6)
project (CBreakout)
# The version number.
set (CPPTest_VERSION_MAJOR 0)
set (CPPTest_VERSION_MINOR 1)

set (PROJECT_SOURCE_DIR "src")
set (PROJECT_BINARY_DIR "bin")
 
# configure a header file to pass some of the CMake settings
# to the source code
# configure_file (
#  "${PROJECT_SOURCE_DIR}/CBreakoutConfig.h.in"
#  "${PROJECT_BINARY_DIR}/CBreakoutConfig.h"
#  )
 
# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")
 
file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/*.cpp)
# add the executable
add_executable(CBreakout ${SOURCES})

include(FindPkgConfig)

pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

include_directories(${SDL2_INCLUDE_DIR} ${SDL2IMAGE_INCLUDE_DIRS})

target_link_libraries(CBreakout ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
