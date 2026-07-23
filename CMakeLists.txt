cmake_minimum_required(VERSION 3.10)

project(linked_list_visualizer VERSION 0.1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(raylib REQUIRED)

# Shared library containing your linked list implementation
add_library(linked_list
    src/node.c
    src/linked_list.c
)

target_include_directories(linked_list
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_options(linked_list PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)

# Visualizer executable
add_executable(linked_list_visualizer
    src/main.c
)

target_link_libraries(linked_list_visualizer
    PRIVATE
        linked_list
        raylib
)

target_compile_options(linked_list_visualizer PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)

# Test executable
add_executable(linked_list_visualizer_test
    test/test.c
)

target_link_libraries(linked_list_visualizer_test
    PRIVATE
        linked_list
)

target_compile_options(linked_list_visualizer_test PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)
