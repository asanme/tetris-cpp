cmake_minimum_required(VERSION 3.27)
project(tetris_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(tetris_cpp
        src/main.cpp
        src/code/logic/Tauler.cpp
        src/code/logic/headers/Tauler.h
        src/code/logic/Joc.cpp
        src/code/logic/headers/Joc.h
        src/code/logic/Figura.cpp
        src/code/logic/headers/Figura.h
        src/code/logic/GraphicManager.cpp
        src/code/logic/headers/GraphicManager.h
        src/code/logic/headers/InfoJoc.h
        src/code/logic/Partida.cpp
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
        src/code/util/MovementNode.cpp
        src/code/util/MovementQueue.cpp
        src/code/util/ShapeNode.cpp
        src/code/util/ShapeQueue.cpp
        src/code/util/headers/MovementNode.h
        src/code/util/headers/MovementQueue.h
        src/code/util/headers/ShapeNode.h
        src/code/util/headers/ShapeQueue.h
        src/code/util/headers/Utilities.h
        src/code/util/Utilities.cpp
        src/code/logic/Tetris.cpp
        src/code/logic/headers/Tetris.h)

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
    find_package(PNG REQUIRED)
    find_package(SDL2 REQUIRED)
    find_package(SDL2_ttf REQUIRED)
    find_package(SDL2_image REQUIRED)

    # Include libpng directories
    include_directories(${PNG_INCLUDE_DIR})

    # Link libraries
    target_link_libraries(${PROJECT_NAME} ${PNG_LIBRARY} SDL2::SDL2 SDL2_ttf::SDL2_ttf SDL2_image::SDL2_image ZLIB::ZLIB)
endif ()

