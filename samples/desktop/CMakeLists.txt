cmake_minimum_required(VERSION 3.22)

if(APPLE)
    # Scheme Environment should be set to Xcode project.
    set(CMAKE_XCODE_SCHEME_ENVIRONMENT
        VK_ICD_FILENAMES=$ENV{VULKAN_SDK}/share/vulkan/icd.d/MoltenVK_icd.json
        VK_LAYER_PATH=$ENV{VULKAN_SDK}/share/vulkan/explicit_layer.d
    )
endif()

function(configure_sample target)
    cmake_minimum_required(VERSION 3.22)

    project(
        ${target}
        VERSION 0.1
        DESCRIPTION "${target} sample"
        LANGUAGES CXX
    )
    file(GLOB_RECURSE srcs "*.cpp" "*.h")

    if(ANDROID)
        add_library(${target} SHARED
            ${srcs}
        )
    else()
        add_executable(${target}
            ${srcs}
        )
    endif()

    find_package(spdlog CONFIG REQUIRED)

    target_link_libraries(${target}
        PRIVATE
        engin::engin
        spdlog::spdlog_header_only
    )

    # set compile options
    if(MSVC)
    # TODO
    elseif(APPLE)
        target_compile_options(${target}
            PUBLIC
            -Wall
            -Werror
            -Wno-unused-parameter
            -Wno-unused-function
            -Wno-unused-but-set-variable
            -Wno-unused-variable

            PRIVATE
            -fno-rtti # -fno-exceptions
        )
    endif()

    if(CMAKE_GENERATOR STREQUAL "Ninja")
        set(BINARY_OUT ${CMAKE_CURRENT_BINARY_DIR})
    else()
        set(BINARY_OUT ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_BUILD_TYPE})
    endif()

    # convert shader to spirv
    find_program(GLSLC_EXE NAMES glslc)

    if(NOT ANDROID)
        # copy spirv to output
        set(SHADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/shaders)
        file(GLOB_RECURSE shaders "${SHADER_DIR}/*.vert" "${SHADER_DIR}/*.frag" "${SHADER_DIR}/*.comp")

        if(EXISTS ${GLSLC_EXE})
            function(run_glslc tar shader_name src dst)
                add_custom_command(TARGET ${tar} POST_BUILD
                    COMMAND ${GLSLC_EXE} ${src}/${shader_name} -o ${dst}/${shader_name}.spv
                )
            endfunction()

            foreach(shader ${shaders})
                cmake_path(GET shader FILENAME shader_name)
                run_glslc(${target} ${shader_name} ${SHADER_DIR} ${BINARY_OUT})
                run_glslc(${target} ${shader_name} ${SHADER_DIR} ${SHADER_DIR})
            endforeach(shader)
        else()
            foreach(shader ${shaders})
                cmake_path(GET shader FILENAME shader_name)
                file(COPY ${SHADER_DIR}/${shader_name}.spv DESTINATION ${BINARY_OUT})
            endforeach(shader)
        endif()
    endif()

    # copy resources
    file(GLOB_RECURSE resources "${CMAKE_CURRENT_SOURCE_DIR}/res/*.*")

    foreach(resource ${resources})
        file(COPY ${resource} DESTINATION ${BINARY_OUT})
    endforeach(resource)
endfunction()

add_subdirectory(triangle)