# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/pedro/clion-2018.2.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/pedro/clion-2018.2.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pedro/MP-Final

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pedro/MP-Final/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Predio.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Predio.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Predio.dir/flags.make

CMakeFiles/Predio.dir/source/Predio.cpp.o: CMakeFiles/Predio.dir/flags.make
CMakeFiles/Predio.dir/source/Predio.cpp.o: ../source/Predio.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pedro/MP-Final/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Predio.dir/source/Predio.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Predio.dir/source/Predio.cpp.o -c /home/pedro/MP-Final/source/Predio.cpp

CMakeFiles/Predio.dir/source/Predio.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Predio.dir/source/Predio.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pedro/MP-Final/source/Predio.cpp > CMakeFiles/Predio.dir/source/Predio.cpp.i

CMakeFiles/Predio.dir/source/Predio.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Predio.dir/source/Predio.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pedro/MP-Final/source/Predio.cpp -o CMakeFiles/Predio.dir/source/Predio.cpp.s

# Object files for target Predio
Predio_OBJECTS = \
"CMakeFiles/Predio.dir/source/Predio.cpp.o"

# External object files for target Predio
Predio_EXTERNAL_OBJECTS =

libPredio.a: CMakeFiles/Predio.dir/source/Predio.cpp.o
libPredio.a: CMakeFiles/Predio.dir/build.make
libPredio.a: CMakeFiles/Predio.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pedro/MP-Final/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libPredio.a"
	$(CMAKE_COMMAND) -P CMakeFiles/Predio.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Predio.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Predio.dir/build: libPredio.a

.PHONY : CMakeFiles/Predio.dir/build

CMakeFiles/Predio.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Predio.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Predio.dir/clean

CMakeFiles/Predio.dir/depend:
	cd /home/pedro/MP-Final/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pedro/MP-Final /home/pedro/MP-Final /home/pedro/MP-Final/cmake-build-debug /home/pedro/MP-Final/cmake-build-debug /home/pedro/MP-Final/cmake-build-debug/CMakeFiles/Predio.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Predio.dir/depend

