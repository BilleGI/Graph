cmake_minimum_required(VERSION 3.5)

add_executable(1 main.cpp ${MY_INCLUDE_DIR}/igraph.h ${MY_INCLUDE_DIR}/listgraph.h listgraph.cpp
    ${MY_INCLUDE_DIR}/matrixgraph.h matrixgraph.cpp)

target_include_directories(1 PUBLIC ${MY_INCLUDE_DIR})
