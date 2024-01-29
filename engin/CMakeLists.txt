cmake_minimum_required(VERSION 3.22)

find_package(jipu REQUIRED)
find_package(spdlog REQUIRED)

set(source_files
    ${CMAKE_CURRENT_SOURCE_DIR}/camera.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/camera.h
    ${CMAKE_CURRENT_SOURCE_DIR}/engine.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/engine.h
    ${CMAKE_CURRENT_SOURCE_DIR}/entity.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/entity.h
    ${CMAKE_CURRENT_SOURCE_DIR}/material.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/material.h
    ${CMAKE_CURRENT_SOURCE_DIR}/light.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/light.h
    ${CMAKE_CURRENT_SOURCE_DIR}/transform.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/transform.h
    ${CMAKE_CURRENT_SOURCE_DIR}/view.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/view.h
    ${CMAKE_CURRENT_SOURCE_DIR}/scene.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/scene.h
)

set(private_libraries
    jipu::jipu
    spdlog::spdlog_header_only
)

set(LIB_TYPE STATIC)

if(BUILD_SHARED_LIBS)
    set(LIB_TYPE SHARED)
endif()

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