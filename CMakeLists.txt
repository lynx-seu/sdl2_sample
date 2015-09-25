project(sample)
cmake_minimum_required(VERSION 2.6)

if (WIN32)
    add_definitions("-mwindows")
endif(WIN32)

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# module
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

# package
## SDL2base
find_package(SDL2 REQUIRED)
set(3rd_header ${SDL2_INCLUDE_DIR})
set(3rd_lib ${SDL2_LIBRARY})
set(3rd_dll ${SDL2_DLL_PATH})
## other SDL2 external library


file(COPY ${3rd_dll} DESTINATION ${EXECUTABLE_OUTPUT_PATH})
# source / include / lib
include_directories(${3rd_header})

aux_source_directory(src SRC_LIST)

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} ${3rd_lib})
