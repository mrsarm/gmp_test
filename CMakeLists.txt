cmake_minimum_required(VERSION 3.1)
project(gmp_test C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")   # Add more flags here

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMake/Modules)
find_package(GMP REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/out")


INCLUDE_DIRECTORIES(
    "${GMP_INCLUDES}"
    "${CMAKE_SOURCE_DIR}/src"
)

set(SOURCE_FILES src/main.c)
add_executable(gmp_test ${SOURCE_FILES} src/date.h src/date.c)

target_link_libraries(gmp_test ${GMP_LIBRARIES})

install(TARGETS gmp_test
        DESTINATION ${CMAKE_INSTALL_PREFIX}/bin/)


add_custom_target(clean-all
  make clean && rm -fR ${CMAKE_BINARY_DIR}/CMakeCache.txt
                       ${CMAKE_BINARY_DIR}/cmake_install.cmake
                       ${CMAKE_BINARY_DIR}/Makefile
                       ${CMAKE_BINARY_DIR}/CMakeFiles
             && rmdir  ${CMAKE_BINARY_DIR}/out
)
