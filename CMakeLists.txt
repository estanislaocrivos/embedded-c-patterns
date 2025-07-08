cmake_minimum_required(VERSION 3.13)

project(emb-c-design-patterns C)

include_directories(inc)

set(CMAKE_C_STANDARD 11)

file(GLOB SRC_FILES "src/*.c")

add_executable(emb-c-design-patterns ${SRC_FILES})
