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
CMAKE_SOURCE_DIR = /home/mule/Documents/Calculator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mule/Documents/Calculator

# Include any dependencies generated for this target.
include CMakeFiles/CALCULATOR-atmega32u4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CALCULATOR-atmega32u4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CALCULATOR-atmega32u4.dir/flags.make

CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/KeypadMatrix.cpp.obj: CMakeFiles/CALCULATOR-atmega32u4.dir/flags.make
CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/KeypadMatrix.cpp.obj: c_lib/KeypadMatrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mule/Documents/Calculator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/KeypadMatrix.cpp.obj"
	/usr/bin/avr-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/KeypadMatrix.cpp.obj -c /home/mule/Documents/Calculator/c_lib/KeypadMatrix.cpp

CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/KeypadMatrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/KeypadMatrix.cpp.i"
	/usr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mule/Documents/Calculator/c_lib/KeypadMatrix.cpp > CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/KeypadMatrix.cpp.i

CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/KeypadMatrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/KeypadMatrix.cpp.s"
	/usr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mule/Documents/Calculator/c_lib/KeypadMatrix.cpp -o CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/KeypadMatrix.cpp.s

CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/KeypadMatrix.cpp.obj.requires:

.PHONY : CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/KeypadMatrix.cpp.obj.requires

CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/KeypadMatrix.cpp.obj.provides: CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/KeypadMatrix.cpp.obj.requires
	$(MAKE) -f CMakeFiles/CALCULATOR-atmega32u4.dir/build.make CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/KeypadMatrix.cpp.obj.provides.build
.PHONY : CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/KeypadMatrix.cpp.obj.provides

CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/KeypadMatrix.cpp.obj.provides.build: CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/KeypadMatrix.cpp.obj


CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/LCD.cpp.obj: CMakeFiles/CALCULATOR-atmega32u4.dir/flags.make
CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/LCD.cpp.obj: c_lib/LCD.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mule/Documents/Calculator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/LCD.cpp.obj"
	/usr/bin/avr-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/LCD.cpp.obj -c /home/mule/Documents/Calculator/c_lib/LCD.cpp

CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/LCD.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/LCD.cpp.i"
	/usr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mule/Documents/Calculator/c_lib/LCD.cpp > CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/LCD.cpp.i

CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/LCD.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/LCD.cpp.s"
	/usr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mule/Documents/Calculator/c_lib/LCD.cpp -o CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/LCD.cpp.s

CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/LCD.cpp.obj.requires:

.PHONY : CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/LCD.cpp.obj.requires

CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/LCD.cpp.obj.provides: CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/LCD.cpp.obj.requires
	$(MAKE) -f CMakeFiles/CALCULATOR-atmega32u4.dir/build.make CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/LCD.cpp.obj.provides.build
.PHONY : CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/LCD.cpp.obj.provides

CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/LCD.cpp.obj.provides.build: CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/LCD.cpp.obj


CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/Timing.cpp.obj: CMakeFiles/CALCULATOR-atmega32u4.dir/flags.make
CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/Timing.cpp.obj: c_lib/Timing.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mule/Documents/Calculator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/Timing.cpp.obj"
	/usr/bin/avr-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/Timing.cpp.obj -c /home/mule/Documents/Calculator/c_lib/Timing.cpp

CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/Timing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/Timing.cpp.i"
	/usr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mule/Documents/Calculator/c_lib/Timing.cpp > CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/Timing.cpp.i

CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/Timing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/Timing.cpp.s"
	/usr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mule/Documents/Calculator/c_lib/Timing.cpp -o CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/Timing.cpp.s

CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/Timing.cpp.obj.requires:

.PHONY : CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/Timing.cpp.obj.requires

CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/Timing.cpp.obj.provides: CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/Timing.cpp.obj.requires
	$(MAKE) -f CMakeFiles/CALCULATOR-atmega32u4.dir/build.make CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/Timing.cpp.obj.provides.build
.PHONY : CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/Timing.cpp.obj.provides

CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/Timing.cpp.obj.provides.build: CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/Timing.cpp.obj


# Object files for target CALCULATOR-atmega32u4
CALCULATOR__atmega32u4_OBJECTS = \
"CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/KeypadMatrix.cpp.obj" \
"CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/LCD.cpp.obj" \
"CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/Timing.cpp.obj"

# External object files for target CALCULATOR-atmega32u4
CALCULATOR__atmega32u4_EXTERNAL_OBJECTS =

libCALCULATOR-atmega32u4.a: CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/KeypadMatrix.cpp.obj
libCALCULATOR-atmega32u4.a: CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/LCD.cpp.obj
libCALCULATOR-atmega32u4.a: CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/Timing.cpp.obj
libCALCULATOR-atmega32u4.a: CMakeFiles/CALCULATOR-atmega32u4.dir/build.make
libCALCULATOR-atmega32u4.a: CMakeFiles/CALCULATOR-atmega32u4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mule/Documents/Calculator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libCALCULATOR-atmega32u4.a"
	$(CMAKE_COMMAND) -P CMakeFiles/CALCULATOR-atmega32u4.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CALCULATOR-atmega32u4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CALCULATOR-atmega32u4.dir/build: libCALCULATOR-atmega32u4.a

.PHONY : CMakeFiles/CALCULATOR-atmega32u4.dir/build

CMakeFiles/CALCULATOR-atmega32u4.dir/requires: CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/KeypadMatrix.cpp.obj.requires
CMakeFiles/CALCULATOR-atmega32u4.dir/requires: CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/LCD.cpp.obj.requires
CMakeFiles/CALCULATOR-atmega32u4.dir/requires: CMakeFiles/CALCULATOR-atmega32u4.dir/c_lib/Timing.cpp.obj.requires

.PHONY : CMakeFiles/CALCULATOR-atmega32u4.dir/requires

CMakeFiles/CALCULATOR-atmega32u4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CALCULATOR-atmega32u4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CALCULATOR-atmega32u4.dir/clean

CMakeFiles/CALCULATOR-atmega32u4.dir/depend:
	cd /home/mule/Documents/Calculator && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mule/Documents/Calculator /home/mule/Documents/Calculator /home/mule/Documents/Calculator /home/mule/Documents/Calculator /home/mule/Documents/Calculator/CMakeFiles/CALCULATOR-atmega32u4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CALCULATOR-atmega32u4.dir/depend

