# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/brookie/github/TronSys/Lab 3/Q2Conveyor++"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/brookie/github/TronSys/Lab 3/Q2Conveyor++"

# Include any dependencies generated for this target.
include CMakeFiles/Conv.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Conv.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Conv.dir/flags.make

CMakeFiles/Conv.dir/main.cpp.o: CMakeFiles/Conv.dir/flags.make
CMakeFiles/Conv.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/brookie/github/TronSys/Lab 3/Q2Conveyor++/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Conv.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Conv.dir/main.cpp.o -c "/home/brookie/github/TronSys/Lab 3/Q2Conveyor++/main.cpp"

CMakeFiles/Conv.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Conv.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/brookie/github/TronSys/Lab 3/Q2Conveyor++/main.cpp" > CMakeFiles/Conv.dir/main.cpp.i

CMakeFiles/Conv.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Conv.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/brookie/github/TronSys/Lab 3/Q2Conveyor++/main.cpp" -o CMakeFiles/Conv.dir/main.cpp.s

CMakeFiles/Conv.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Conv.dir/main.cpp.o.requires

CMakeFiles/Conv.dir/main.cpp.o.provides: CMakeFiles/Conv.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Conv.dir/build.make CMakeFiles/Conv.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Conv.dir/main.cpp.o.provides

CMakeFiles/Conv.dir/main.cpp.o.provides.build: CMakeFiles/Conv.dir/main.cpp.o


CMakeFiles/Conv.dir/Conveyor.cpp.o: CMakeFiles/Conv.dir/flags.make
CMakeFiles/Conv.dir/Conveyor.cpp.o: Conveyor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/brookie/github/TronSys/Lab 3/Q2Conveyor++/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Conv.dir/Conveyor.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Conv.dir/Conveyor.cpp.o -c "/home/brookie/github/TronSys/Lab 3/Q2Conveyor++/Conveyor.cpp"

CMakeFiles/Conv.dir/Conveyor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Conv.dir/Conveyor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/brookie/github/TronSys/Lab 3/Q2Conveyor++/Conveyor.cpp" > CMakeFiles/Conv.dir/Conveyor.cpp.i

CMakeFiles/Conv.dir/Conveyor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Conv.dir/Conveyor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/brookie/github/TronSys/Lab 3/Q2Conveyor++/Conveyor.cpp" -o CMakeFiles/Conv.dir/Conveyor.cpp.s

CMakeFiles/Conv.dir/Conveyor.cpp.o.requires:

.PHONY : CMakeFiles/Conv.dir/Conveyor.cpp.o.requires

CMakeFiles/Conv.dir/Conveyor.cpp.o.provides: CMakeFiles/Conv.dir/Conveyor.cpp.o.requires
	$(MAKE) -f CMakeFiles/Conv.dir/build.make CMakeFiles/Conv.dir/Conveyor.cpp.o.provides.build
.PHONY : CMakeFiles/Conv.dir/Conveyor.cpp.o.provides

CMakeFiles/Conv.dir/Conveyor.cpp.o.provides.build: CMakeFiles/Conv.dir/Conveyor.cpp.o


CMakeFiles/Conv.dir/LoadingRobot.cpp.o: CMakeFiles/Conv.dir/flags.make
CMakeFiles/Conv.dir/LoadingRobot.cpp.o: LoadingRobot.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/brookie/github/TronSys/Lab 3/Q2Conveyor++/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Conv.dir/LoadingRobot.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Conv.dir/LoadingRobot.cpp.o -c "/home/brookie/github/TronSys/Lab 3/Q2Conveyor++/LoadingRobot.cpp"

CMakeFiles/Conv.dir/LoadingRobot.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Conv.dir/LoadingRobot.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/brookie/github/TronSys/Lab 3/Q2Conveyor++/LoadingRobot.cpp" > CMakeFiles/Conv.dir/LoadingRobot.cpp.i

CMakeFiles/Conv.dir/LoadingRobot.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Conv.dir/LoadingRobot.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/brookie/github/TronSys/Lab 3/Q2Conveyor++/LoadingRobot.cpp" -o CMakeFiles/Conv.dir/LoadingRobot.cpp.s

CMakeFiles/Conv.dir/LoadingRobot.cpp.o.requires:

.PHONY : CMakeFiles/Conv.dir/LoadingRobot.cpp.o.requires

CMakeFiles/Conv.dir/LoadingRobot.cpp.o.provides: CMakeFiles/Conv.dir/LoadingRobot.cpp.o.requires
	$(MAKE) -f CMakeFiles/Conv.dir/build.make CMakeFiles/Conv.dir/LoadingRobot.cpp.o.provides.build
.PHONY : CMakeFiles/Conv.dir/LoadingRobot.cpp.o.provides

CMakeFiles/Conv.dir/LoadingRobot.cpp.o.provides.build: CMakeFiles/Conv.dir/LoadingRobot.cpp.o


CMakeFiles/Conv.dir/ProcessingRobot.cpp.o: CMakeFiles/Conv.dir/flags.make
CMakeFiles/Conv.dir/ProcessingRobot.cpp.o: ProcessingRobot.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/brookie/github/TronSys/Lab 3/Q2Conveyor++/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Conv.dir/ProcessingRobot.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Conv.dir/ProcessingRobot.cpp.o -c "/home/brookie/github/TronSys/Lab 3/Q2Conveyor++/ProcessingRobot.cpp"

CMakeFiles/Conv.dir/ProcessingRobot.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Conv.dir/ProcessingRobot.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/brookie/github/TronSys/Lab 3/Q2Conveyor++/ProcessingRobot.cpp" > CMakeFiles/Conv.dir/ProcessingRobot.cpp.i

CMakeFiles/Conv.dir/ProcessingRobot.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Conv.dir/ProcessingRobot.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/brookie/github/TronSys/Lab 3/Q2Conveyor++/ProcessingRobot.cpp" -o CMakeFiles/Conv.dir/ProcessingRobot.cpp.s

CMakeFiles/Conv.dir/ProcessingRobot.cpp.o.requires:

.PHONY : CMakeFiles/Conv.dir/ProcessingRobot.cpp.o.requires

CMakeFiles/Conv.dir/ProcessingRobot.cpp.o.provides: CMakeFiles/Conv.dir/ProcessingRobot.cpp.o.requires
	$(MAKE) -f CMakeFiles/Conv.dir/build.make CMakeFiles/Conv.dir/ProcessingRobot.cpp.o.provides.build
.PHONY : CMakeFiles/Conv.dir/ProcessingRobot.cpp.o.provides

CMakeFiles/Conv.dir/ProcessingRobot.cpp.o.provides.build: CMakeFiles/Conv.dir/ProcessingRobot.cpp.o


# Object files for target Conv
Conv_OBJECTS = \
"CMakeFiles/Conv.dir/main.cpp.o" \
"CMakeFiles/Conv.dir/Conveyor.cpp.o" \
"CMakeFiles/Conv.dir/LoadingRobot.cpp.o" \
"CMakeFiles/Conv.dir/ProcessingRobot.cpp.o"

# External object files for target Conv
Conv_EXTERNAL_OBJECTS =

Conv: CMakeFiles/Conv.dir/main.cpp.o
Conv: CMakeFiles/Conv.dir/Conveyor.cpp.o
Conv: CMakeFiles/Conv.dir/LoadingRobot.cpp.o
Conv: CMakeFiles/Conv.dir/ProcessingRobot.cpp.o
Conv: CMakeFiles/Conv.dir/build.make
Conv: CMakeFiles/Conv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/brookie/github/TronSys/Lab 3/Q2Conveyor++/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Conv"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Conv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Conv.dir/build: Conv

.PHONY : CMakeFiles/Conv.dir/build

CMakeFiles/Conv.dir/requires: CMakeFiles/Conv.dir/main.cpp.o.requires
CMakeFiles/Conv.dir/requires: CMakeFiles/Conv.dir/Conveyor.cpp.o.requires
CMakeFiles/Conv.dir/requires: CMakeFiles/Conv.dir/LoadingRobot.cpp.o.requires
CMakeFiles/Conv.dir/requires: CMakeFiles/Conv.dir/ProcessingRobot.cpp.o.requires

.PHONY : CMakeFiles/Conv.dir/requires

CMakeFiles/Conv.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Conv.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Conv.dir/clean

CMakeFiles/Conv.dir/depend:
	cd "/home/brookie/github/TronSys/Lab 3/Q2Conveyor++" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/brookie/github/TronSys/Lab 3/Q2Conveyor++" "/home/brookie/github/TronSys/Lab 3/Q2Conveyor++" "/home/brookie/github/TronSys/Lab 3/Q2Conveyor++" "/home/brookie/github/TronSys/Lab 3/Q2Conveyor++" "/home/brookie/github/TronSys/Lab 3/Q2Conveyor++/CMakeFiles/Conv.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Conv.dir/depend
