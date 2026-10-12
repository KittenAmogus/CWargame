cmake_minimum_required(VERSION 3.15)

project(Wargame VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDART 11)
set(CMAKE_C_STANDART_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SDL2 REQUIRED)

file(GLOB SRC_FILES "src/*.c")
add_executable(wargame ${SRC_FILES})

target_include_directories(wargame PRIVATE include)

target_link_libraries(wargame PRIVATE SDL2::SDL2)

if (NOT MSVC)
  target_link_libraries(wargame PRIVATE m)
endif()

if (MSVC)
  target_compile_options(wargame PRIVATE /W4)
else()
  target_compile_options(wargame PRIVATE -Wall -Wextra -Wpedantic)
endif()

