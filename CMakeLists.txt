cmake_minimum_required(VERSION 3.28)
project(mipt_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)            # -std=c++23, а не -std=gnu++23
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-Wall -Wextra -Wpedantic)

add_compile_options($<$<CONFIG:Debug>:-fsanitize=address,undefined>)
add_link_options($<$<CONFIG:Debug>:-fsanitize=address,undefined>)

file(GLOB task_dirs LIST_DIRECTORIES true CONFIGURE_DEPENDS
     ${CMAKE_CURRENT_SOURCE_DIR}/[0-9][0-9]/[0-9][0-9])

foreach(dir IN LISTS task_dirs)
    if(EXISTS ${dir}/CMakeLists.txt)
        add_subdirectory(${dir})
        continue()
    endif()

    file(GLOB sources CONFIGURE_DEPENDS ${dir}/*.cpp)
    if(NOT sources)
        continue()
    endif()

    cmake_path(GET dir FILENAME task)
    cmake_path(GET dir PARENT_PATH module_dir)
    cmake_path(GET module_dir FILENAME module)
    add_executable(${module}.${task} ${sources})
endforeach()
