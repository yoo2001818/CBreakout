cmake_minimum_required (VERSION 2.6)
project (CBreakout)
# The version number.
set (CPPTest_VERSION_MAJOR 0)
set (CPPTest_VERSION_MINOR 1)

set (PROJECT_SOURCE_DIR "src")
set (PROJECT_BINARY_DIR "bin")

IF (WIN32)

  #file (WRITE "${CMAKE_CURRENT_LIST_DIR}/compiler" "${CMAKE_CXX_COMPILER}")
  #set (CMAKE_CXX_COMPILER "${CMAKE_CURRENT_LIST_DIR}/mostlyStaticWrap")

  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -I/usr/include/SDL2 -D_REENTRANT")
  set (CMAKE_FIND_LIBRARY_SUFFIXES ".a")
  set (BUILD_SHARED_LIBRARIES OFF)
  set (CMAKE_EXE_LINKER_FLAGS "-lSDL2 -lpthread -lSDL2_image -lSDL2_mixer -static-libgcc -static-libstdc++")
  
  # -static -static-libstdc++ -static-libgcc -lstdc++ -lmingw32 -lSDL2_mixer -lFLAC -lvorbisfile -lvorbis -logg -lsmpeg2 -lmodplug -lpthread -lwinpthread -lSDL2_image -lpng -ljpeg -lz -lSDL2main -lSDL2 -lm -ldinput8 -ldxguid -ldxerr8 -luser32 -lgdi32 -lwinmm -limm32 -lole32 -loleaut32 -lshell32 -lversion -luuid
ELSE()
  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
ENDIF()
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
 
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/*.cpp)
file(MAKE_DIRECTORY "res/")
file(COPY "res/" DESTINATION "res/")
# add the executable
add_executable(CBreakout ${SOURCES})

include(FindPkgConfig)

pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
pkg_search_module(SDL2MIXER REQUIRED SDL2_mixer>=2.0.0)

include_directories(${SDL2_INCLUDE_DIR} ${SDL2IMAGE_INCLUDE_DIRS} ${SDL2MIXER_INCLUDE_DIRS})

target_link_libraries(CBreakout ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2MIXER_LIBRARIES})
