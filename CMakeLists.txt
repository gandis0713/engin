cmake_minimum_required(VERSION 3.22)

project(
    engin
    VERSION 0.0.1
    DESCRIPTION "3D Rendering Engine"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(engin)

# install(EXPORT ${PROJECT_NAME}-config
# NAMESPACE engin::
# DESTINATION ${CMAKE_INSTALL_PREFIX}/share/${PROJECT_NAME}
# )