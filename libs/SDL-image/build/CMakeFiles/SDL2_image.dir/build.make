# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/build

# Include any dependencies generated for this target.
include CMakeFiles/SDL2_image.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SDL2_image.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SDL2_image.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SDL2_image.dir/flags.make

CMakeFiles/SDL2_image.dir/src/IMG.c.o: CMakeFiles/SDL2_image.dir/flags.make
CMakeFiles/SDL2_image.dir/src/IMG.c.o: /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG.c
CMakeFiles/SDL2_image.dir/src/IMG.c.o: CMakeFiles/SDL2_image.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/SDL2_image.dir/src/IMG.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SDL2_image.dir/src/IMG.c.o -MF CMakeFiles/SDL2_image.dir/src/IMG.c.o.d -o CMakeFiles/SDL2_image.dir/src/IMG.c.o -c /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG.c

CMakeFiles/SDL2_image.dir/src/IMG.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SDL2_image.dir/src/IMG.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG.c > CMakeFiles/SDL2_image.dir/src/IMG.c.i

CMakeFiles/SDL2_image.dir/src/IMG.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SDL2_image.dir/src/IMG.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG.c -o CMakeFiles/SDL2_image.dir/src/IMG.c.s

CMakeFiles/SDL2_image.dir/src/IMG_WIC.c.o: CMakeFiles/SDL2_image.dir/flags.make
CMakeFiles/SDL2_image.dir/src/IMG_WIC.c.o: /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_WIC.c
CMakeFiles/SDL2_image.dir/src/IMG_WIC.c.o: CMakeFiles/SDL2_image.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/SDL2_image.dir/src/IMG_WIC.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SDL2_image.dir/src/IMG_WIC.c.o -MF CMakeFiles/SDL2_image.dir/src/IMG_WIC.c.o.d -o CMakeFiles/SDL2_image.dir/src/IMG_WIC.c.o -c /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_WIC.c

CMakeFiles/SDL2_image.dir/src/IMG_WIC.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SDL2_image.dir/src/IMG_WIC.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_WIC.c > CMakeFiles/SDL2_image.dir/src/IMG_WIC.c.i

CMakeFiles/SDL2_image.dir/src/IMG_WIC.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SDL2_image.dir/src/IMG_WIC.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_WIC.c -o CMakeFiles/SDL2_image.dir/src/IMG_WIC.c.s

CMakeFiles/SDL2_image.dir/src/IMG_avif.c.o: CMakeFiles/SDL2_image.dir/flags.make
CMakeFiles/SDL2_image.dir/src/IMG_avif.c.o: /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_avif.c
CMakeFiles/SDL2_image.dir/src/IMG_avif.c.o: CMakeFiles/SDL2_image.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/SDL2_image.dir/src/IMG_avif.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SDL2_image.dir/src/IMG_avif.c.o -MF CMakeFiles/SDL2_image.dir/src/IMG_avif.c.o.d -o CMakeFiles/SDL2_image.dir/src/IMG_avif.c.o -c /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_avif.c

CMakeFiles/SDL2_image.dir/src/IMG_avif.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SDL2_image.dir/src/IMG_avif.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_avif.c > CMakeFiles/SDL2_image.dir/src/IMG_avif.c.i

CMakeFiles/SDL2_image.dir/src/IMG_avif.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SDL2_image.dir/src/IMG_avif.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_avif.c -o CMakeFiles/SDL2_image.dir/src/IMG_avif.c.s

CMakeFiles/SDL2_image.dir/src/IMG_bmp.c.o: CMakeFiles/SDL2_image.dir/flags.make
CMakeFiles/SDL2_image.dir/src/IMG_bmp.c.o: /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_bmp.c
CMakeFiles/SDL2_image.dir/src/IMG_bmp.c.o: CMakeFiles/SDL2_image.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/SDL2_image.dir/src/IMG_bmp.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SDL2_image.dir/src/IMG_bmp.c.o -MF CMakeFiles/SDL2_image.dir/src/IMG_bmp.c.o.d -o CMakeFiles/SDL2_image.dir/src/IMG_bmp.c.o -c /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_bmp.c

CMakeFiles/SDL2_image.dir/src/IMG_bmp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SDL2_image.dir/src/IMG_bmp.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_bmp.c > CMakeFiles/SDL2_image.dir/src/IMG_bmp.c.i

CMakeFiles/SDL2_image.dir/src/IMG_bmp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SDL2_image.dir/src/IMG_bmp.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_bmp.c -o CMakeFiles/SDL2_image.dir/src/IMG_bmp.c.s

CMakeFiles/SDL2_image.dir/src/IMG_gif.c.o: CMakeFiles/SDL2_image.dir/flags.make
CMakeFiles/SDL2_image.dir/src/IMG_gif.c.o: /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_gif.c
CMakeFiles/SDL2_image.dir/src/IMG_gif.c.o: CMakeFiles/SDL2_image.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/SDL2_image.dir/src/IMG_gif.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SDL2_image.dir/src/IMG_gif.c.o -MF CMakeFiles/SDL2_image.dir/src/IMG_gif.c.o.d -o CMakeFiles/SDL2_image.dir/src/IMG_gif.c.o -c /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_gif.c

CMakeFiles/SDL2_image.dir/src/IMG_gif.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SDL2_image.dir/src/IMG_gif.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_gif.c > CMakeFiles/SDL2_image.dir/src/IMG_gif.c.i

CMakeFiles/SDL2_image.dir/src/IMG_gif.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SDL2_image.dir/src/IMG_gif.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_gif.c -o CMakeFiles/SDL2_image.dir/src/IMG_gif.c.s

CMakeFiles/SDL2_image.dir/src/IMG_jpg.c.o: CMakeFiles/SDL2_image.dir/flags.make
CMakeFiles/SDL2_image.dir/src/IMG_jpg.c.o: /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_jpg.c
CMakeFiles/SDL2_image.dir/src/IMG_jpg.c.o: CMakeFiles/SDL2_image.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/SDL2_image.dir/src/IMG_jpg.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SDL2_image.dir/src/IMG_jpg.c.o -MF CMakeFiles/SDL2_image.dir/src/IMG_jpg.c.o.d -o CMakeFiles/SDL2_image.dir/src/IMG_jpg.c.o -c /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_jpg.c

CMakeFiles/SDL2_image.dir/src/IMG_jpg.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SDL2_image.dir/src/IMG_jpg.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_jpg.c > CMakeFiles/SDL2_image.dir/src/IMG_jpg.c.i

CMakeFiles/SDL2_image.dir/src/IMG_jpg.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SDL2_image.dir/src/IMG_jpg.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_jpg.c -o CMakeFiles/SDL2_image.dir/src/IMG_jpg.c.s

CMakeFiles/SDL2_image.dir/src/IMG_jxl.c.o: CMakeFiles/SDL2_image.dir/flags.make
CMakeFiles/SDL2_image.dir/src/IMG_jxl.c.o: /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_jxl.c
CMakeFiles/SDL2_image.dir/src/IMG_jxl.c.o: CMakeFiles/SDL2_image.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/SDL2_image.dir/src/IMG_jxl.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SDL2_image.dir/src/IMG_jxl.c.o -MF CMakeFiles/SDL2_image.dir/src/IMG_jxl.c.o.d -o CMakeFiles/SDL2_image.dir/src/IMG_jxl.c.o -c /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_jxl.c

CMakeFiles/SDL2_image.dir/src/IMG_jxl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SDL2_image.dir/src/IMG_jxl.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_jxl.c > CMakeFiles/SDL2_image.dir/src/IMG_jxl.c.i

CMakeFiles/SDL2_image.dir/src/IMG_jxl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SDL2_image.dir/src/IMG_jxl.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_jxl.c -o CMakeFiles/SDL2_image.dir/src/IMG_jxl.c.s

CMakeFiles/SDL2_image.dir/src/IMG_lbm.c.o: CMakeFiles/SDL2_image.dir/flags.make
CMakeFiles/SDL2_image.dir/src/IMG_lbm.c.o: /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_lbm.c
CMakeFiles/SDL2_image.dir/src/IMG_lbm.c.o: CMakeFiles/SDL2_image.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/SDL2_image.dir/src/IMG_lbm.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SDL2_image.dir/src/IMG_lbm.c.o -MF CMakeFiles/SDL2_image.dir/src/IMG_lbm.c.o.d -o CMakeFiles/SDL2_image.dir/src/IMG_lbm.c.o -c /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_lbm.c

CMakeFiles/SDL2_image.dir/src/IMG_lbm.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SDL2_image.dir/src/IMG_lbm.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_lbm.c > CMakeFiles/SDL2_image.dir/src/IMG_lbm.c.i

CMakeFiles/SDL2_image.dir/src/IMG_lbm.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SDL2_image.dir/src/IMG_lbm.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_lbm.c -o CMakeFiles/SDL2_image.dir/src/IMG_lbm.c.s

CMakeFiles/SDL2_image.dir/src/IMG_pcx.c.o: CMakeFiles/SDL2_image.dir/flags.make
CMakeFiles/SDL2_image.dir/src/IMG_pcx.c.o: /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_pcx.c
CMakeFiles/SDL2_image.dir/src/IMG_pcx.c.o: CMakeFiles/SDL2_image.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/SDL2_image.dir/src/IMG_pcx.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SDL2_image.dir/src/IMG_pcx.c.o -MF CMakeFiles/SDL2_image.dir/src/IMG_pcx.c.o.d -o CMakeFiles/SDL2_image.dir/src/IMG_pcx.c.o -c /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_pcx.c

CMakeFiles/SDL2_image.dir/src/IMG_pcx.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SDL2_image.dir/src/IMG_pcx.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_pcx.c > CMakeFiles/SDL2_image.dir/src/IMG_pcx.c.i

CMakeFiles/SDL2_image.dir/src/IMG_pcx.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SDL2_image.dir/src/IMG_pcx.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_pcx.c -o CMakeFiles/SDL2_image.dir/src/IMG_pcx.c.s

CMakeFiles/SDL2_image.dir/src/IMG_png.c.o: CMakeFiles/SDL2_image.dir/flags.make
CMakeFiles/SDL2_image.dir/src/IMG_png.c.o: /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_png.c
CMakeFiles/SDL2_image.dir/src/IMG_png.c.o: CMakeFiles/SDL2_image.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/SDL2_image.dir/src/IMG_png.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SDL2_image.dir/src/IMG_png.c.o -MF CMakeFiles/SDL2_image.dir/src/IMG_png.c.o.d -o CMakeFiles/SDL2_image.dir/src/IMG_png.c.o -c /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_png.c

CMakeFiles/SDL2_image.dir/src/IMG_png.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SDL2_image.dir/src/IMG_png.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_png.c > CMakeFiles/SDL2_image.dir/src/IMG_png.c.i

CMakeFiles/SDL2_image.dir/src/IMG_png.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SDL2_image.dir/src/IMG_png.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_png.c -o CMakeFiles/SDL2_image.dir/src/IMG_png.c.s

CMakeFiles/SDL2_image.dir/src/IMG_pnm.c.o: CMakeFiles/SDL2_image.dir/flags.make
CMakeFiles/SDL2_image.dir/src/IMG_pnm.c.o: /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_pnm.c
CMakeFiles/SDL2_image.dir/src/IMG_pnm.c.o: CMakeFiles/SDL2_image.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/SDL2_image.dir/src/IMG_pnm.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SDL2_image.dir/src/IMG_pnm.c.o -MF CMakeFiles/SDL2_image.dir/src/IMG_pnm.c.o.d -o CMakeFiles/SDL2_image.dir/src/IMG_pnm.c.o -c /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_pnm.c

CMakeFiles/SDL2_image.dir/src/IMG_pnm.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SDL2_image.dir/src/IMG_pnm.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_pnm.c > CMakeFiles/SDL2_image.dir/src/IMG_pnm.c.i

CMakeFiles/SDL2_image.dir/src/IMG_pnm.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SDL2_image.dir/src/IMG_pnm.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_pnm.c -o CMakeFiles/SDL2_image.dir/src/IMG_pnm.c.s

CMakeFiles/SDL2_image.dir/src/IMG_qoi.c.o: CMakeFiles/SDL2_image.dir/flags.make
CMakeFiles/SDL2_image.dir/src/IMG_qoi.c.o: /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_qoi.c
CMakeFiles/SDL2_image.dir/src/IMG_qoi.c.o: CMakeFiles/SDL2_image.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/SDL2_image.dir/src/IMG_qoi.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SDL2_image.dir/src/IMG_qoi.c.o -MF CMakeFiles/SDL2_image.dir/src/IMG_qoi.c.o.d -o CMakeFiles/SDL2_image.dir/src/IMG_qoi.c.o -c /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_qoi.c

CMakeFiles/SDL2_image.dir/src/IMG_qoi.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SDL2_image.dir/src/IMG_qoi.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_qoi.c > CMakeFiles/SDL2_image.dir/src/IMG_qoi.c.i

CMakeFiles/SDL2_image.dir/src/IMG_qoi.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SDL2_image.dir/src/IMG_qoi.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_qoi.c -o CMakeFiles/SDL2_image.dir/src/IMG_qoi.c.s

CMakeFiles/SDL2_image.dir/src/IMG_stb.c.o: CMakeFiles/SDL2_image.dir/flags.make
CMakeFiles/SDL2_image.dir/src/IMG_stb.c.o: /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_stb.c
CMakeFiles/SDL2_image.dir/src/IMG_stb.c.o: CMakeFiles/SDL2_image.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/SDL2_image.dir/src/IMG_stb.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SDL2_image.dir/src/IMG_stb.c.o -MF CMakeFiles/SDL2_image.dir/src/IMG_stb.c.o.d -o CMakeFiles/SDL2_image.dir/src/IMG_stb.c.o -c /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_stb.c

CMakeFiles/SDL2_image.dir/src/IMG_stb.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SDL2_image.dir/src/IMG_stb.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_stb.c > CMakeFiles/SDL2_image.dir/src/IMG_stb.c.i

CMakeFiles/SDL2_image.dir/src/IMG_stb.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SDL2_image.dir/src/IMG_stb.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_stb.c -o CMakeFiles/SDL2_image.dir/src/IMG_stb.c.s

CMakeFiles/SDL2_image.dir/src/IMG_svg.c.o: CMakeFiles/SDL2_image.dir/flags.make
CMakeFiles/SDL2_image.dir/src/IMG_svg.c.o: /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_svg.c
CMakeFiles/SDL2_image.dir/src/IMG_svg.c.o: CMakeFiles/SDL2_image.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/SDL2_image.dir/src/IMG_svg.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SDL2_image.dir/src/IMG_svg.c.o -MF CMakeFiles/SDL2_image.dir/src/IMG_svg.c.o.d -o CMakeFiles/SDL2_image.dir/src/IMG_svg.c.o -c /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_svg.c

CMakeFiles/SDL2_image.dir/src/IMG_svg.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SDL2_image.dir/src/IMG_svg.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_svg.c > CMakeFiles/SDL2_image.dir/src/IMG_svg.c.i

CMakeFiles/SDL2_image.dir/src/IMG_svg.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SDL2_image.dir/src/IMG_svg.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_svg.c -o CMakeFiles/SDL2_image.dir/src/IMG_svg.c.s

CMakeFiles/SDL2_image.dir/src/IMG_tga.c.o: CMakeFiles/SDL2_image.dir/flags.make
CMakeFiles/SDL2_image.dir/src/IMG_tga.c.o: /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_tga.c
CMakeFiles/SDL2_image.dir/src/IMG_tga.c.o: CMakeFiles/SDL2_image.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building C object CMakeFiles/SDL2_image.dir/src/IMG_tga.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SDL2_image.dir/src/IMG_tga.c.o -MF CMakeFiles/SDL2_image.dir/src/IMG_tga.c.o.d -o CMakeFiles/SDL2_image.dir/src/IMG_tga.c.o -c /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_tga.c

CMakeFiles/SDL2_image.dir/src/IMG_tga.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SDL2_image.dir/src/IMG_tga.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_tga.c > CMakeFiles/SDL2_image.dir/src/IMG_tga.c.i

CMakeFiles/SDL2_image.dir/src/IMG_tga.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SDL2_image.dir/src/IMG_tga.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_tga.c -o CMakeFiles/SDL2_image.dir/src/IMG_tga.c.s

CMakeFiles/SDL2_image.dir/src/IMG_tif.c.o: CMakeFiles/SDL2_image.dir/flags.make
CMakeFiles/SDL2_image.dir/src/IMG_tif.c.o: /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_tif.c
CMakeFiles/SDL2_image.dir/src/IMG_tif.c.o: CMakeFiles/SDL2_image.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building C object CMakeFiles/SDL2_image.dir/src/IMG_tif.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SDL2_image.dir/src/IMG_tif.c.o -MF CMakeFiles/SDL2_image.dir/src/IMG_tif.c.o.d -o CMakeFiles/SDL2_image.dir/src/IMG_tif.c.o -c /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_tif.c

CMakeFiles/SDL2_image.dir/src/IMG_tif.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SDL2_image.dir/src/IMG_tif.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_tif.c > CMakeFiles/SDL2_image.dir/src/IMG_tif.c.i

CMakeFiles/SDL2_image.dir/src/IMG_tif.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SDL2_image.dir/src/IMG_tif.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_tif.c -o CMakeFiles/SDL2_image.dir/src/IMG_tif.c.s

CMakeFiles/SDL2_image.dir/src/IMG_webp.c.o: CMakeFiles/SDL2_image.dir/flags.make
CMakeFiles/SDL2_image.dir/src/IMG_webp.c.o: /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_webp.c
CMakeFiles/SDL2_image.dir/src/IMG_webp.c.o: CMakeFiles/SDL2_image.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building C object CMakeFiles/SDL2_image.dir/src/IMG_webp.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SDL2_image.dir/src/IMG_webp.c.o -MF CMakeFiles/SDL2_image.dir/src/IMG_webp.c.o.d -o CMakeFiles/SDL2_image.dir/src/IMG_webp.c.o -c /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_webp.c

CMakeFiles/SDL2_image.dir/src/IMG_webp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SDL2_image.dir/src/IMG_webp.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_webp.c > CMakeFiles/SDL2_image.dir/src/IMG_webp.c.i

CMakeFiles/SDL2_image.dir/src/IMG_webp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SDL2_image.dir/src/IMG_webp.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_webp.c -o CMakeFiles/SDL2_image.dir/src/IMG_webp.c.s

CMakeFiles/SDL2_image.dir/src/IMG_xcf.c.o: CMakeFiles/SDL2_image.dir/flags.make
CMakeFiles/SDL2_image.dir/src/IMG_xcf.c.o: /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_xcf.c
CMakeFiles/SDL2_image.dir/src/IMG_xcf.c.o: CMakeFiles/SDL2_image.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building C object CMakeFiles/SDL2_image.dir/src/IMG_xcf.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SDL2_image.dir/src/IMG_xcf.c.o -MF CMakeFiles/SDL2_image.dir/src/IMG_xcf.c.o.d -o CMakeFiles/SDL2_image.dir/src/IMG_xcf.c.o -c /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_xcf.c

CMakeFiles/SDL2_image.dir/src/IMG_xcf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SDL2_image.dir/src/IMG_xcf.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_xcf.c > CMakeFiles/SDL2_image.dir/src/IMG_xcf.c.i

CMakeFiles/SDL2_image.dir/src/IMG_xcf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SDL2_image.dir/src/IMG_xcf.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_xcf.c -o CMakeFiles/SDL2_image.dir/src/IMG_xcf.c.s

CMakeFiles/SDL2_image.dir/src/IMG_xpm.c.o: CMakeFiles/SDL2_image.dir/flags.make
CMakeFiles/SDL2_image.dir/src/IMG_xpm.c.o: /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_xpm.c
CMakeFiles/SDL2_image.dir/src/IMG_xpm.c.o: CMakeFiles/SDL2_image.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building C object CMakeFiles/SDL2_image.dir/src/IMG_xpm.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SDL2_image.dir/src/IMG_xpm.c.o -MF CMakeFiles/SDL2_image.dir/src/IMG_xpm.c.o.d -o CMakeFiles/SDL2_image.dir/src/IMG_xpm.c.o -c /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_xpm.c

CMakeFiles/SDL2_image.dir/src/IMG_xpm.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SDL2_image.dir/src/IMG_xpm.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_xpm.c > CMakeFiles/SDL2_image.dir/src/IMG_xpm.c.i

CMakeFiles/SDL2_image.dir/src/IMG_xpm.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SDL2_image.dir/src/IMG_xpm.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_xpm.c -o CMakeFiles/SDL2_image.dir/src/IMG_xpm.c.s

CMakeFiles/SDL2_image.dir/src/IMG_xv.c.o: CMakeFiles/SDL2_image.dir/flags.make
CMakeFiles/SDL2_image.dir/src/IMG_xv.c.o: /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_xv.c
CMakeFiles/SDL2_image.dir/src/IMG_xv.c.o: CMakeFiles/SDL2_image.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Building C object CMakeFiles/SDL2_image.dir/src/IMG_xv.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SDL2_image.dir/src/IMG_xv.c.o -MF CMakeFiles/SDL2_image.dir/src/IMG_xv.c.o.d -o CMakeFiles/SDL2_image.dir/src/IMG_xv.c.o -c /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_xv.c

CMakeFiles/SDL2_image.dir/src/IMG_xv.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SDL2_image.dir/src/IMG_xv.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_xv.c > CMakeFiles/SDL2_image.dir/src/IMG_xv.c.i

CMakeFiles/SDL2_image.dir/src/IMG_xv.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SDL2_image.dir/src/IMG_xv.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/src/IMG_xv.c -o CMakeFiles/SDL2_image.dir/src/IMG_xv.c.s

# Object files for target SDL2_image
SDL2_image_OBJECTS = \
"CMakeFiles/SDL2_image.dir/src/IMG.c.o" \
"CMakeFiles/SDL2_image.dir/src/IMG_WIC.c.o" \
"CMakeFiles/SDL2_image.dir/src/IMG_avif.c.o" \
"CMakeFiles/SDL2_image.dir/src/IMG_bmp.c.o" \
"CMakeFiles/SDL2_image.dir/src/IMG_gif.c.o" \
"CMakeFiles/SDL2_image.dir/src/IMG_jpg.c.o" \
"CMakeFiles/SDL2_image.dir/src/IMG_jxl.c.o" \
"CMakeFiles/SDL2_image.dir/src/IMG_lbm.c.o" \
"CMakeFiles/SDL2_image.dir/src/IMG_pcx.c.o" \
"CMakeFiles/SDL2_image.dir/src/IMG_png.c.o" \
"CMakeFiles/SDL2_image.dir/src/IMG_pnm.c.o" \
"CMakeFiles/SDL2_image.dir/src/IMG_qoi.c.o" \
"CMakeFiles/SDL2_image.dir/src/IMG_stb.c.o" \
"CMakeFiles/SDL2_image.dir/src/IMG_svg.c.o" \
"CMakeFiles/SDL2_image.dir/src/IMG_tga.c.o" \
"CMakeFiles/SDL2_image.dir/src/IMG_tif.c.o" \
"CMakeFiles/SDL2_image.dir/src/IMG_webp.c.o" \
"CMakeFiles/SDL2_image.dir/src/IMG_xcf.c.o" \
"CMakeFiles/SDL2_image.dir/src/IMG_xpm.c.o" \
"CMakeFiles/SDL2_image.dir/src/IMG_xv.c.o"

# External object files for target SDL2_image
SDL2_image_EXTERNAL_OBJECTS =

libSDL2_image-2.0.so.0.800.2: CMakeFiles/SDL2_image.dir/src/IMG.c.o
libSDL2_image-2.0.so.0.800.2: CMakeFiles/SDL2_image.dir/src/IMG_WIC.c.o
libSDL2_image-2.0.so.0.800.2: CMakeFiles/SDL2_image.dir/src/IMG_avif.c.o
libSDL2_image-2.0.so.0.800.2: CMakeFiles/SDL2_image.dir/src/IMG_bmp.c.o
libSDL2_image-2.0.so.0.800.2: CMakeFiles/SDL2_image.dir/src/IMG_gif.c.o
libSDL2_image-2.0.so.0.800.2: CMakeFiles/SDL2_image.dir/src/IMG_jpg.c.o
libSDL2_image-2.0.so.0.800.2: CMakeFiles/SDL2_image.dir/src/IMG_jxl.c.o
libSDL2_image-2.0.so.0.800.2: CMakeFiles/SDL2_image.dir/src/IMG_lbm.c.o
libSDL2_image-2.0.so.0.800.2: CMakeFiles/SDL2_image.dir/src/IMG_pcx.c.o
libSDL2_image-2.0.so.0.800.2: CMakeFiles/SDL2_image.dir/src/IMG_png.c.o
libSDL2_image-2.0.so.0.800.2: CMakeFiles/SDL2_image.dir/src/IMG_pnm.c.o
libSDL2_image-2.0.so.0.800.2: CMakeFiles/SDL2_image.dir/src/IMG_qoi.c.o
libSDL2_image-2.0.so.0.800.2: CMakeFiles/SDL2_image.dir/src/IMG_stb.c.o
libSDL2_image-2.0.so.0.800.2: CMakeFiles/SDL2_image.dir/src/IMG_svg.c.o
libSDL2_image-2.0.so.0.800.2: CMakeFiles/SDL2_image.dir/src/IMG_tga.c.o
libSDL2_image-2.0.so.0.800.2: CMakeFiles/SDL2_image.dir/src/IMG_tif.c.o
libSDL2_image-2.0.so.0.800.2: CMakeFiles/SDL2_image.dir/src/IMG_webp.c.o
libSDL2_image-2.0.so.0.800.2: CMakeFiles/SDL2_image.dir/src/IMG_xcf.c.o
libSDL2_image-2.0.so.0.800.2: CMakeFiles/SDL2_image.dir/src/IMG_xpm.c.o
libSDL2_image-2.0.so.0.800.2: CMakeFiles/SDL2_image.dir/src/IMG_xv.c.o
libSDL2_image-2.0.so.0.800.2: CMakeFiles/SDL2_image.dir/build.make
libSDL2_image-2.0.so.0.800.2: /usr/lib/libSDL2-2.0.so.0.3000.3
libSDL2_image-2.0.so.0.800.2: CMakeFiles/SDL2_image.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_21) "Linking C shared library libSDL2_image-2.0.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SDL2_image.dir/link.txt --verbose=$(VERBOSE)
	$(CMAKE_COMMAND) -E cmake_symlink_library libSDL2_image-2.0.so.0.800.2 libSDL2_image-2.0.so.0 libSDL2_image-2.0.so
	/usr/bin/cmake -E create_symlink libSDL2_image-2.0.so.0 libSDL2_image.so

libSDL2_image-2.0.so.0: libSDL2_image-2.0.so.0.800.2
	@$(CMAKE_COMMAND) -E touch_nocreate libSDL2_image-2.0.so.0

libSDL2_image-2.0.so: libSDL2_image-2.0.so.0.800.2
	@$(CMAKE_COMMAND) -E touch_nocreate libSDL2_image-2.0.so

# Rule to build all files generated by this target.
CMakeFiles/SDL2_image.dir/build: libSDL2_image-2.0.so
.PHONY : CMakeFiles/SDL2_image.dir/build

CMakeFiles/SDL2_image.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SDL2_image.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SDL2_image.dir/clean

CMakeFiles/SDL2_image.dir/depend:
	cd /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/build /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/build /home/asanme/cpp-projects/tetris-cpp/libs/SDL-image/build/CMakeFiles/SDL2_image.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/SDL2_image.dir/depend
