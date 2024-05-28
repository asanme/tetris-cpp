cmake_minimum_required(VERSION 3.27)
project(tetris_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(tetris_cpp
        src/main.cpp
        src/lib/cpp/Tauler.cpp
        src/lib/headers/Tauler.h
        src/lib/cpp/Joc.cpp
        src/lib/headers/Joc.h
        src/lib/cpp/Figura.cpp
        src/lib/headers/Figura.h)

# Platform-specific SDL configuration
if (WIN32)
    # Windows specific configuration
    set(SDL2_DIR ${CMAKE_SOURCE_DIR}/external/SDL-Windows)

    # Add SDL2 directory to include directories
    target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_DIR}/include)

    # Add SDL2.dll to the output directory
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${SDL2_DIR}/SDL2.dll"
            $<TARGET_FILE_DIR:${PROJECT_NAME}>)

elseif (UNIX)
    # Linux specific configuration
    set(SDL2_DIR ${CMAKE_SOURCE_DIR}/libs/SDL)

    # Add SDL2 directory to include directories
    target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_DIR}/include)

    # Link SDL2 library
    target_link_libraries(${PROJECT_NAME} ${SDL2_DIR}/build/libSDL2.a)
endif ()

