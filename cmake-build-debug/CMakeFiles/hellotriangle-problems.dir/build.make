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
include CMakeFiles/hellotriangle-problems.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hellotriangle-problems.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hellotriangle-problems.dir/flags.make

CMakeFiles/hellotriangle-problems.dir/src/hellotriangle-problems.cpp.o: CMakeFiles/hellotriangle-problems.dir/flags.make
CMakeFiles/hellotriangle-problems.dir/src/hellotriangle-problems.cpp.o: ../src/hellotriangle-problems.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/trevor/Documents/coding/github/openGL-experimentation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hellotriangle-problems.dir/src/hellotriangle-problems.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hellotriangle-problems.dir/src/hellotriangle-problems.cpp.o -c /home/trevor/Documents/coding/github/openGL-experimentation/src/hellotriangle-problems.cpp

CMakeFiles/hellotriangle-problems.dir/src/hellotriangle-problems.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hellotriangle-problems.dir/src/hellotriangle-problems.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/trevor/Documents/coding/github/openGL-experimentation/src/hellotriangle-problems.cpp > CMakeFiles/hellotriangle-problems.dir/src/hellotriangle-problems.cpp.i

CMakeFiles/hellotriangle-problems.dir/src/hellotriangle-problems.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hellotriangle-problems.dir/src/hellotriangle-problems.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/trevor/Documents/coding/github/openGL-experimentation/src/hellotriangle-problems.cpp -o CMakeFiles/hellotriangle-problems.dir/src/hellotriangle-problems.cpp.s

# Object files for target hellotriangle-problems
hellotriangle__problems_OBJECTS = \
"CMakeFiles/hellotriangle-problems.dir/src/hellotriangle-problems.cpp.o"

# External object files for target hellotriangle-problems
hellotriangle__problems_EXTERNAL_OBJECTS =

hellotriangle-problems: CMakeFiles/hellotriangle-problems.dir/src/hellotriangle-problems.cpp.o
hellotriangle-problems: CMakeFiles/hellotriangle-problems.dir/build.make
hellotriangle-problems: CMakeFiles/hellotriangle-problems.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/trevor/Documents/coding/github/openGL-experimentation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hellotriangle-problems"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hellotriangle-problems.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hellotriangle-problems.dir/build: hellotriangle-problems

.PHONY : CMakeFiles/hellotriangle-problems.dir/build

CMakeFiles/hellotriangle-problems.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hellotriangle-problems.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hellotriangle-problems.dir/clean

CMakeFiles/hellotriangle-problems.dir/depend:
	cd /home/trevor/Documents/coding/github/openGL-experimentation/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/trevor/Documents/coding/github/openGL-experimentation /home/trevor/Documents/coding/github/openGL-experimentation /home/trevor/Documents/coding/github/openGL-experimentation/cmake-build-debug /home/trevor/Documents/coding/github/openGL-experimentation/cmake-build-debug /home/trevor/Documents/coding/github/openGL-experimentation/cmake-build-debug/CMakeFiles/hellotriangle-problems.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hellotriangle-problems.dir/depend

