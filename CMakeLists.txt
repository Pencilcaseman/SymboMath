cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
cmake_policy(SET CMP0077 NEW)

file(GLOB_RECURSE SYMBO_SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
        )

add_library(symbomath STATIC ${SYMBO_SOURCES})
target_include_directories(symbomath PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
