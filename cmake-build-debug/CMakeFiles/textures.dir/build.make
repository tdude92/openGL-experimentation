# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/trevor/Documents/coding/clion-2019.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/trevor/Documents/coding/clion-2019.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/trevor/Documents/coding/github/openGL-experimentation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/trevor/Documents/coding/github/openGL-experimentation/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/textures.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/textures.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/textures.dir/flags.make

CMakeFiles/textures.dir/src/textures.cpp.o: CMakeFiles/textures.dir/flags.make
CMakeFiles/textures.dir/src/textures.cpp.o: ../src/textures.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/trevor/Documents/coding/github/openGL-experimentation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/textures.dir/src/textures.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/textures.dir/src/textures.cpp.o -c /home/trevor/Documents/coding/github/openGL-experimentation/src/textures.cpp

CMakeFiles/textures.dir/src/textures.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/textures.dir/src/textures.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/trevor/Documents/coding/github/openGL-experimentation/src/textures.cpp > CMakeFiles/textures.dir/src/textures.cpp.i

CMakeFiles/textures.dir/src/textures.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/textures.dir/src/textures.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/trevor/Documents/coding/github/openGL-experimentation/src/textures.cpp -o CMakeFiles/textures.dir/src/textures.cpp.s

CMakeFiles/textures.dir/src/stb_image.cpp.o: CMakeFiles/textures.dir/flags.make
CMakeFiles/textures.dir/src/stb_image.cpp.o: ../src/stb_image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/trevor/Documents/coding/github/openGL-experimentation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/textures.dir/src/stb_image.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/textures.dir/src/stb_image.cpp.o -c /home/trevor/Documents/coding/github/openGL-experimentation/src/stb_image.cpp

CMakeFiles/textures.dir/src/stb_image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/textures.dir/src/stb_image.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/trevor/Documents/coding/github/openGL-experimentation/src/stb_image.cpp > CMakeFiles/textures.dir/src/stb_image.cpp.i

CMakeFiles/textures.dir/src/stb_image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/textures.dir/src/stb_image.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/trevor/Documents/coding/github/openGL-experimentation/src/stb_image.cpp -o CMakeFiles/textures.dir/src/stb_image.cpp.s

# Object files for target textures
textures_OBJECTS = \
"CMakeFiles/textures.dir/src/textures.cpp.o" \
"CMakeFiles/textures.dir/src/stb_image.cpp.o"

# External object files for target textures
textures_EXTERNAL_OBJECTS =

textures: CMakeFiles/textures.dir/src/textures.cpp.o
textures: CMakeFiles/textures.dir/src/stb_image.cpp.o
textures: CMakeFiles/textures.dir/build.make
textures: CMakeFiles/textures.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/trevor/Documents/coding/github/openGL-experimentation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable textures"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/textures.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/textures.dir/build: textures

.PHONY : CMakeFiles/textures.dir/build

CMakeFiles/textures.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/textures.dir/cmake_clean.cmake
.PHONY : CMakeFiles/textures.dir/clean

CMakeFiles/textures.dir/depend:
	cd /home/trevor/Documents/coding/github/openGL-experimentation/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/trevor/Documents/coding/github/openGL-experimentation /home/trevor/Documents/coding/github/openGL-experimentation /home/trevor/Documents/coding/github/openGL-experimentation/cmake-build-debug /home/trevor/Documents/coding/github/openGL-experimentation/cmake-build-debug /home/trevor/Documents/coding/github/openGL-experimentation/cmake-build-debug/CMakeFiles/textures.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/textures.dir/depend

