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
include CMakeFiles/shaders-problems.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/shaders-problems.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/shaders-problems.dir/flags.make

CMakeFiles/shaders-problems.dir/src/shaders-problems.cpp.o: CMakeFiles/shaders-problems.dir/flags.make
CMakeFiles/shaders-problems.dir/src/shaders-problems.cpp.o: ../src/shaders-problems.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/trevor/Documents/coding/github/openGL-experimentation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/shaders-problems.dir/src/shaders-problems.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/shaders-problems.dir/src/shaders-problems.cpp.o -c /home/trevor/Documents/coding/github/openGL-experimentation/src/shaders-problems.cpp

CMakeFiles/shaders-problems.dir/src/shaders-problems.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shaders-problems.dir/src/shaders-problems.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/trevor/Documents/coding/github/openGL-experimentation/src/shaders-problems.cpp > CMakeFiles/shaders-problems.dir/src/shaders-problems.cpp.i

CMakeFiles/shaders-problems.dir/src/shaders-problems.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shaders-problems.dir/src/shaders-problems.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/trevor/Documents/coding/github/openGL-experimentation/src/shaders-problems.cpp -o CMakeFiles/shaders-problems.dir/src/shaders-problems.cpp.s

# Object files for target shaders-problems
shaders__problems_OBJECTS = \
"CMakeFiles/shaders-problems.dir/src/shaders-problems.cpp.o"

# External object files for target shaders-problems
shaders__problems_EXTERNAL_OBJECTS =

shaders-problems: CMakeFiles/shaders-problems.dir/src/shaders-problems.cpp.o
shaders-problems: CMakeFiles/shaders-problems.dir/build.make
shaders-problems: CMakeFiles/shaders-problems.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/trevor/Documents/coding/github/openGL-experimentation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable shaders-problems"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/shaders-problems.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/shaders-problems.dir/build: shaders-problems

.PHONY : CMakeFiles/shaders-problems.dir/build

CMakeFiles/shaders-problems.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/shaders-problems.dir/cmake_clean.cmake
.PHONY : CMakeFiles/shaders-problems.dir/clean

CMakeFiles/shaders-problems.dir/depend:
	cd /home/trevor/Documents/coding/github/openGL-experimentation/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/trevor/Documents/coding/github/openGL-experimentation /home/trevor/Documents/coding/github/openGL-experimentation /home/trevor/Documents/coding/github/openGL-experimentation/cmake-build-debug /home/trevor/Documents/coding/github/openGL-experimentation/cmake-build-debug /home/trevor/Documents/coding/github/openGL-experimentation/cmake-build-debug/CMakeFiles/shaders-problems.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/shaders-problems.dir/depend

