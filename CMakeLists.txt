cmake_minimum_required(VERSION 3.15)

set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 1)

set(PROJECT_VERSION
    "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}"
)

project(WaffleEngine VERSION "${PROJECT_VERSION}")

add_library(Engine)

target_sources(Engine PRIVATE src/engine.cpp)

target_include_directories(Engine PUBLIC include)

find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)

target_link_libraries(Engine PRIVATE glfw glad::glad)

if(CMAKE_EXPORT_COMPILE_COMMANDS)
  add_custom_target(
    copy_compile_commands ALL
    COMMAND
      ${CMAKE_COMMAND} -E create_symlink
      "${CMAKE_BINARY_DIR}/compile_commands.json"
      "${CMAKE_SOURCE_DIR}/compile_commands.json"
    DEPENDS "${CMAKE_BINARY_DIR}/compile_commands.json"
    COMMENT "Creating symlink for compile_commands.json in source dir")
endif()

enable_testing()

add_subdirectory(tests)
