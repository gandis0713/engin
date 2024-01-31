cmake_minimum_required(VERSION 3.22)

project(
    engin
    VERSION 0.0.1
    DESCRIPTION "3D Rendering Engine"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(engin)

if(ENABLE_SAMPLE)
    add_subdirectory(samples)
endif()

if(ENABLE_TEST)
    enable_testing() # enable test here.
    add_subdirectory(test)
endif()

# install(EXPORT ${PROJECT_NAME}-config
# NAMESPACE engin::
# DESTINATION ${CMAKE_INSTALL_PREFIX}/share/${PROJECT_NAME}
# )