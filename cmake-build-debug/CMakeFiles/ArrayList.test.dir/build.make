# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /snap/clion/169/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/169/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/joao/Compilers

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/joao/Compilers/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ArrayList.test.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/ArrayList.test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ArrayList.test.dir/flags.make

CMakeFiles/ArrayList.test.dir/src/data_structures/array_list.c.o: CMakeFiles/ArrayList.test.dir/flags.make
CMakeFiles/ArrayList.test.dir/src/data_structures/array_list.c.o: ../src/data_structures/array_list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joao/Compilers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ArrayList.test.dir/src/data_structures/array_list.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ArrayList.test.dir/src/data_structures/array_list.c.o -c /home/joao/Compilers/src/data_structures/array_list.c

CMakeFiles/ArrayList.test.dir/src/data_structures/array_list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ArrayList.test.dir/src/data_structures/array_list.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/joao/Compilers/src/data_structures/array_list.c > CMakeFiles/ArrayList.test.dir/src/data_structures/array_list.c.i

CMakeFiles/ArrayList.test.dir/src/data_structures/array_list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ArrayList.test.dir/src/data_structures/array_list.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/joao/Compilers/src/data_structures/array_list.c -o CMakeFiles/ArrayList.test.dir/src/data_structures/array_list.c.s

CMakeFiles/ArrayList.test.dir/src/tests/array_list.test.c.o: CMakeFiles/ArrayList.test.dir/flags.make
CMakeFiles/ArrayList.test.dir/src/tests/array_list.test.c.o: ../src/tests/array_list.test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joao/Compilers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ArrayList.test.dir/src/tests/array_list.test.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ArrayList.test.dir/src/tests/array_list.test.c.o -c /home/joao/Compilers/src/tests/array_list.test.c

CMakeFiles/ArrayList.test.dir/src/tests/array_list.test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ArrayList.test.dir/src/tests/array_list.test.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/joao/Compilers/src/tests/array_list.test.c > CMakeFiles/ArrayList.test.dir/src/tests/array_list.test.c.i

CMakeFiles/ArrayList.test.dir/src/tests/array_list.test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ArrayList.test.dir/src/tests/array_list.test.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/joao/Compilers/src/tests/array_list.test.c -o CMakeFiles/ArrayList.test.dir/src/tests/array_list.test.c.s

CMakeFiles/ArrayList.test.dir/src/data_structures/linked_list.c.o: CMakeFiles/ArrayList.test.dir/flags.make
CMakeFiles/ArrayList.test.dir/src/data_structures/linked_list.c.o: ../src/data_structures/linked_list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joao/Compilers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/ArrayList.test.dir/src/data_structures/linked_list.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ArrayList.test.dir/src/data_structures/linked_list.c.o -c /home/joao/Compilers/src/data_structures/linked_list.c

CMakeFiles/ArrayList.test.dir/src/data_structures/linked_list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ArrayList.test.dir/src/data_structures/linked_list.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/joao/Compilers/src/data_structures/linked_list.c > CMakeFiles/ArrayList.test.dir/src/data_structures/linked_list.c.i

CMakeFiles/ArrayList.test.dir/src/data_structures/linked_list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ArrayList.test.dir/src/data_structures/linked_list.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/joao/Compilers/src/data_structures/linked_list.c -o CMakeFiles/ArrayList.test.dir/src/data_structures/linked_list.c.s

CMakeFiles/ArrayList.test.dir/src/data_structures/abstract_syntax_tree.c.o: CMakeFiles/ArrayList.test.dir/flags.make
CMakeFiles/ArrayList.test.dir/src/data_structures/abstract_syntax_tree.c.o: ../src/data_structures/abstract_syntax_tree.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joao/Compilers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/ArrayList.test.dir/src/data_structures/abstract_syntax_tree.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ArrayList.test.dir/src/data_structures/abstract_syntax_tree.c.o -c /home/joao/Compilers/src/data_structures/abstract_syntax_tree.c

CMakeFiles/ArrayList.test.dir/src/data_structures/abstract_syntax_tree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ArrayList.test.dir/src/data_structures/abstract_syntax_tree.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/joao/Compilers/src/data_structures/abstract_syntax_tree.c > CMakeFiles/ArrayList.test.dir/src/data_structures/abstract_syntax_tree.c.i

CMakeFiles/ArrayList.test.dir/src/data_structures/abstract_syntax_tree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ArrayList.test.dir/src/data_structures/abstract_syntax_tree.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/joao/Compilers/src/data_structures/abstract_syntax_tree.c -o CMakeFiles/ArrayList.test.dir/src/data_structures/abstract_syntax_tree.c.s

# Object files for target ArrayList.test
ArrayList_test_OBJECTS = \
"CMakeFiles/ArrayList.test.dir/src/data_structures/array_list.c.o" \
"CMakeFiles/ArrayList.test.dir/src/tests/array_list.test.c.o" \
"CMakeFiles/ArrayList.test.dir/src/data_structures/linked_list.c.o" \
"CMakeFiles/ArrayList.test.dir/src/data_structures/abstract_syntax_tree.c.o"

# External object files for target ArrayList.test
ArrayList_test_EXTERNAL_OBJECTS =

ArrayList.test: CMakeFiles/ArrayList.test.dir/src/data_structures/array_list.c.o
ArrayList.test: CMakeFiles/ArrayList.test.dir/src/tests/array_list.test.c.o
ArrayList.test: CMakeFiles/ArrayList.test.dir/src/data_structures/linked_list.c.o
ArrayList.test: CMakeFiles/ArrayList.test.dir/src/data_structures/abstract_syntax_tree.c.o
ArrayList.test: CMakeFiles/ArrayList.test.dir/build.make
ArrayList.test: CMakeFiles/ArrayList.test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/joao/Compilers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable ArrayList.test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ArrayList.test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ArrayList.test.dir/build: ArrayList.test
.PHONY : CMakeFiles/ArrayList.test.dir/build

CMakeFiles/ArrayList.test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ArrayList.test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ArrayList.test.dir/clean

CMakeFiles/ArrayList.test.dir/depend:
	cd /home/joao/Compilers/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/joao/Compilers /home/joao/Compilers /home/joao/Compilers/cmake-build-debug /home/joao/Compilers/cmake-build-debug /home/joao/Compilers/cmake-build-debug/CMakeFiles/ArrayList.test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ArrayList.test.dir/depend

