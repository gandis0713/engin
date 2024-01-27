cmake_minimum_required(VERSION 3.22)

find_package(jipu REQUIRED)
find_package(spdlog REQUIRED)

set(source_files
    ${CMAKE_CURRENT_SOURCE_DIR}/camera.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/camera.h
    ${CMAKE_CURRENT_SOURCE_DIR}/engine.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/engine.h
)

set(private_libraries
    jipu::jipu
    spdlog::spdlog_header_only
)

add_library(engin
    ${LIB_TYPE} # SHARED or STATIC
    ${source_files}
)
add_library(engin::engin ALIAS engin)
target_link_libraries(engin PRIVATE
    ${private_libraries}
)

set(source_files_exe
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

add_executable(engin_exe ${source_files_exe})

target_link_libraries(engin_exe PRIVATE
    ${private_libraries}
    engin::engin
)