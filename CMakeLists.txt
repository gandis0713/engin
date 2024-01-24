cmake_minimum_required(VERSION 3.22)

project(
    engin
    VERSION 0.0.1
    DESCRIPTION "3D Rendering Engine"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)

find_package(jipu REQUIRED)
find_package(spdlog REQUIRED)

set(source_files
    ${CMAKE_CURRENT_SOURCE_DIR}/engin/main.cpp
)

add_executable(engin ${source_files})

target_link_libraries(engin PRIVATE
    jipu::jipu
    spdlog::spdlog_header_only
)