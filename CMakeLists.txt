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
    set(SDL_DIR ${CMAKE_SOURCE_DIR}/libs/SDL)
    set(libpng_DIR ${CMAKE_SOURCE_DIR}/libs/libpng)
    find_package(SDL2_ttf REQUIRED)
    find_package(SDL2_image REQUIRED)

    # Include library folders
    target_include_directories(${PROJECT_NAME} PRIVATE ${SDL_DIR}/include REQUIRED)
    target_include_directories(${PROJECT_NAME} PRIVATE ${SDL_DIR} REQUIRED)

    # Link libraries
    target_link_libraries(${PROJECT_NAME} ${SDL_DIR}/build/libSDL2.a)
    target_link_libraries(${PROJECT_NAME} ${libpng_DIR}/build/libpng.a)
    target_link_libraries(${PROJECT_NAME} SDL2_ttf::SDL2_ttf SDL2_image::SDL2_image)
endif ()

