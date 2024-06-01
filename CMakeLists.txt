cmake_minimum_required(VERSION 3.27)
project(tetris_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(tetris_cpp
        src/main.cpp
        src/code/logic/cpp/Tauler.cpp
        src/code/logic/headers/Tauler.h
        src/code/logic/cpp/Joc.cpp
        src/code/logic/headers/Joc.h
        src/code/logic/cpp/Figura.cpp
        src/code/logic/headers/Figura.h
        src/code/logic/cpp/GraphicManager.cpp
        src/code/logic/headers/GraphicManager.h
        src/code/logic/headers/InfoJoc.h
        src/code/logic/cpp/Partida.cpp
        src/code/logic/headers/Partida.h
        src/code/graphic-lib/NFont/NFont.cpp
        src/code/graphic-lib/NFont/NFont.h
        src/code/graphic-lib/NFont/NFont_gpu.h
        src/code/graphic-lib/NFont/SDL_FontCache.cpp
        src/code/graphic-lib/NFont/SDL_FontCache.h
        src/code/graphic-lib/debug.cpp
        src/code/graphic-lib/debug.h
        src/code/graphic-lib/error.h
        src/code/graphic-lib/image_png.cpp
        src/code/graphic-lib/image_png.h
        src/code/graphic-lib/keyboard.cpp
        src/code/graphic-lib/keyboard.h
        src/code/graphic-lib/keyboard_sdl.h
        src/code/graphic-lib/libreria.h
        src/code/graphic-lib/mouse.cpp
        src/code/graphic-lib/mouse.h
        src/code/graphic-lib/sound.cpp
        src/code/graphic-lib/sound.h
        src/code/graphic-lib/sprites.cpp
        src/code/graphic-lib/sprites.h
        src/code/graphic-lib/stb_vorbis.cpp
        src/code/graphic-lib/stb_vorbis.h
        src/code/graphic-lib/video.cpp
        src/code/graphic-lib/video.h
        src/code/logic/cpp/ShapeQueue.cpp
        src/code/logic/cpp/ShapeNode.cpp
        src/code/logic/cpp/MovementNode.cpp
        src/code/logic/headers/MovementNode.h
        src/code/logic/headers/MovementQueue.h
        src/code/logic/headers/ShapeQueue.h
        src/code/logic/cpp/MovementNode.cpp
        src/code/logic/headers/MovementNode.h
        src/code/logic/cpp/MovementQueue.cpp
        src/code/logic/cpp/ShapeNode.cpp
        src/code/logic/cpp/ShapeQueue.cpp)

# Windows build not working
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
    find_package(ZLIB REQUIRED)

    # Include library folders
    target_include_directories(${PROJECT_NAME} PRIVATE ${SDL_DIR}/include REQUIRED)
    target_include_directories(${PROJECT_NAME} PRIVATE ${SDL_DIR} REQUIRED)

    # Link libraries
    target_link_libraries(${PROJECT_NAME} ${SDL_DIR}/build/libSDL2.a)
    target_link_libraries(${PROJECT_NAME} ${libpng_DIR}/build/libpng.a)
    target_link_libraries(${PROJECT_NAME} SDL2_ttf::SDL2_ttf SDL2_image::SDL2_image ZLIB::ZLIB)
endif ()

