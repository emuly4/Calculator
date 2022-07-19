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

# Utility rule file for upload_Calc_eeprom.

# Include the progress variables for this target.
include CMakeFiles/upload_Calc_eeprom.dir/progress.make

CMakeFiles/upload_Calc_eeprom: Calc-atmega32u4-eeprom.hex
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/mule/Documents/Calculator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Uploading Calc-atmega32u4-eeprom.hex to atmega32u4 using avr109"
	avrdude -p atmega32u4 -c avr109 -U eeprom:w:Calc-atmega32u4-eeprom.hex -P /dev/ttyCalc

Calc-atmega32u4-eeprom.hex: Calc-atmega32u4.elf
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/mule/Documents/Calculator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating Calc-atmega32u4-eeprom.hex"
	/usr/bin/avr-objcopy -j .eeprom --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0 --no-change-warnings -O ihex Calc-atmega32u4.elf Calc-atmega32u4-eeprom.hex

upload_Calc_eeprom: CMakeFiles/upload_Calc_eeprom
upload_Calc_eeprom: Calc-atmega32u4-eeprom.hex
upload_Calc_eeprom: CMakeFiles/upload_Calc_eeprom.dir/build.make

.PHONY : upload_Calc_eeprom

# Rule to build all files generated by this target.
CMakeFiles/upload_Calc_eeprom.dir/build: upload_Calc_eeprom

.PHONY : CMakeFiles/upload_Calc_eeprom.dir/build

CMakeFiles/upload_Calc_eeprom.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/upload_Calc_eeprom.dir/cmake_clean.cmake
.PHONY : CMakeFiles/upload_Calc_eeprom.dir/clean

CMakeFiles/upload_Calc_eeprom.dir/depend:
	cd /home/mule/Documents/Calculator && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mule/Documents/Calculator /home/mule/Documents/Calculator /home/mule/Documents/Calculator /home/mule/Documents/Calculator /home/mule/Documents/Calculator/CMakeFiles/upload_Calc_eeprom.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/upload_Calc_eeprom.dir/depend

