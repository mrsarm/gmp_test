cmake_minimum_required(VERSION 2.8.4)
project(gmp_test)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMake/Modules)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/out")

find_package(GMP REQUIRED)

INCLUDE_DIRECTORIES(
    "${GMP_INCLUDES}"
    "${CMAKE_SOURCE_DIR}/src"
)

set(SOURCE_FILES src/main.c)
add_executable(gmp_test ${SOURCE_FILES} src/date.h src/date.c)

target_link_libraries(gmp_test ${GMP_LIBRARIES})


add_custom_target(clean-all
  make clean && rm -fR ${CMAKE_BINARY_DIR}/CMakeCache.txt
                       ${CMAKE_BINARY_DIR}/cmake_install.cmake
                       ${CMAKE_BINARY_DIR}/Makefile
                       ${CMAKE_BINARY_DIR}/CMakeFiles
             && rmdir  ${CMAKE_BINARY_DIR}/out
)
