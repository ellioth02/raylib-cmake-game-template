# main CMake file

# general configuration
cmake_minimum_required(VERSION 3.0.0)
project(raylib-cmake-game-template VERSION 0.1.0)
set(CMAKE_C_STANDARD 99) # use C99

# --------------------------------------------------------------------------------------------------------------------

# adding source files
file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/src/*.c") # find all .c source files
set(PROJECT_INCLUDE "${PROJECT_SOURCE_DIR}/src/") # get includes for our code

# --------------------------------------------------------------------------------------------------------------------

# importing raylib

# download git submodules
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/raylib/CMakeLists.txt")
    message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

add_subdirectory(external/raylib) # add raylib dependency

# --------------------------------------------------------------------------------------------------------------------

# creating executable
add_executable(${PROJECT_NAME}) # define a executable
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCES}) # add .c sources to compile for the executable
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_INCLUDE}) # add includes for the compiler
target_link_libraries(${PROJECT_NAME} PRIVATE raylib) # link project to raylib

# --------------------------------------------------------------------------------------------------------------------

# setup path to assets
option(RELEASE_BUILD "Compiled binary is a release build" OFF)
if (RELEASE_BUILD)
    # release path
    target_compile_definitions(${PROJECT_NAME} PRIVATE ASSETS_PATH="./assets/")
else()
    # debug path
    target_compile_definitions(${PROJECT_NAME} PRIVATE ASSETS_PATH="${PROJECT_SOURCE_DIR}/assets/")
endif()
