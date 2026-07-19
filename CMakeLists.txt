cmake_minimum_required(VERSION 3.10.0)
project(linked_list_visualizer VERSION 0.1.0 LANGUAGES C)

add_executable(linked_list_visualizer 
    src/main.c
    src/node.c
    src/linked_list.c
)

add_executable(linked_list_visualizer_test 
    test/test.c
    src/node.c
    src/linked_list.c
)

target_include_directories(linked_list_visualizer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(linked_list_visualizer_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

