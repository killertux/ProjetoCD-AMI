# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_SOURCE_DIR = /home/clemente/Faculdade/CD/ProjetoCD-AMI/AMI_Client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/clemente/Faculdade/CD/ProjetoCD-AMI/AMI_Client/build

# Include any dependencies generated for this target.
include CMakeFiles/ami_client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ami_client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ami_client.dir/flags.make

AMI_Client.moc: ../AMI_Client.h
AMI_Client.moc: AMI_Client.moc_parameters
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/clemente/Faculdade/CD/ProjetoCD-AMI/AMI_Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating AMI_Client.moc"
	/usr/lib/qt4/bin/moc @/home/clemente/Faculdade/CD/ProjetoCD-AMI/AMI_Client/build/AMI_Client.moc_parameters

CMakeFiles/ami_client.dir/AMI_Client.cpp.o: CMakeFiles/ami_client.dir/flags.make
CMakeFiles/ami_client.dir/AMI_Client.cpp.o: ../AMI_Client.cpp
CMakeFiles/ami_client.dir/AMI_Client.cpp.o: AMI_Client.moc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clemente/Faculdade/CD/ProjetoCD-AMI/AMI_Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ami_client.dir/AMI_Client.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ami_client.dir/AMI_Client.cpp.o -c /home/clemente/Faculdade/CD/ProjetoCD-AMI/AMI_Client/AMI_Client.cpp

CMakeFiles/ami_client.dir/AMI_Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ami_client.dir/AMI_Client.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clemente/Faculdade/CD/ProjetoCD-AMI/AMI_Client/AMI_Client.cpp > CMakeFiles/ami_client.dir/AMI_Client.cpp.i

CMakeFiles/ami_client.dir/AMI_Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ami_client.dir/AMI_Client.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clemente/Faculdade/CD/ProjetoCD-AMI/AMI_Client/AMI_Client.cpp -o CMakeFiles/ami_client.dir/AMI_Client.cpp.s

CMakeFiles/ami_client.dir/AMI_Client.cpp.o.requires:

.PHONY : CMakeFiles/ami_client.dir/AMI_Client.cpp.o.requires

CMakeFiles/ami_client.dir/AMI_Client.cpp.o.provides: CMakeFiles/ami_client.dir/AMI_Client.cpp.o.requires
	$(MAKE) -f CMakeFiles/ami_client.dir/build.make CMakeFiles/ami_client.dir/AMI_Client.cpp.o.provides.build
.PHONY : CMakeFiles/ami_client.dir/AMI_Client.cpp.o.provides

CMakeFiles/ami_client.dir/AMI_Client.cpp.o.provides.build: CMakeFiles/ami_client.dir/AMI_Client.cpp.o


CMakeFiles/ami_client.dir/main.cpp.o: CMakeFiles/ami_client.dir/flags.make
CMakeFiles/ami_client.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clemente/Faculdade/CD/ProjetoCD-AMI/AMI_Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ami_client.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ami_client.dir/main.cpp.o -c /home/clemente/Faculdade/CD/ProjetoCD-AMI/AMI_Client/main.cpp

CMakeFiles/ami_client.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ami_client.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clemente/Faculdade/CD/ProjetoCD-AMI/AMI_Client/main.cpp > CMakeFiles/ami_client.dir/main.cpp.i

CMakeFiles/ami_client.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ami_client.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clemente/Faculdade/CD/ProjetoCD-AMI/AMI_Client/main.cpp -o CMakeFiles/ami_client.dir/main.cpp.s

CMakeFiles/ami_client.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/ami_client.dir/main.cpp.o.requires

CMakeFiles/ami_client.dir/main.cpp.o.provides: CMakeFiles/ami_client.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/ami_client.dir/build.make CMakeFiles/ami_client.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/ami_client.dir/main.cpp.o.provides

CMakeFiles/ami_client.dir/main.cpp.o.provides.build: CMakeFiles/ami_client.dir/main.cpp.o


# Object files for target ami_client
ami_client_OBJECTS = \
"CMakeFiles/ami_client.dir/AMI_Client.cpp.o" \
"CMakeFiles/ami_client.dir/main.cpp.o"

# External object files for target ami_client
ami_client_EXTERNAL_OBJECTS =

ami_client: CMakeFiles/ami_client.dir/AMI_Client.cpp.o
ami_client: CMakeFiles/ami_client.dir/main.cpp.o
ami_client: CMakeFiles/ami_client.dir/build.make
ami_client: /usr/lib64/libQtCore.so
ami_client: /usr/lib64/libQtGui.so
ami_client: /usr/lib64/libQtNetwork.so
ami_client: CMakeFiles/ami_client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/clemente/Faculdade/CD/ProjetoCD-AMI/AMI_Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ami_client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ami_client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ami_client.dir/build: ami_client

.PHONY : CMakeFiles/ami_client.dir/build

CMakeFiles/ami_client.dir/requires: CMakeFiles/ami_client.dir/AMI_Client.cpp.o.requires
CMakeFiles/ami_client.dir/requires: CMakeFiles/ami_client.dir/main.cpp.o.requires

.PHONY : CMakeFiles/ami_client.dir/requires

CMakeFiles/ami_client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ami_client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ami_client.dir/clean

CMakeFiles/ami_client.dir/depend: AMI_Client.moc
	cd /home/clemente/Faculdade/CD/ProjetoCD-AMI/AMI_Client/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/clemente/Faculdade/CD/ProjetoCD-AMI/AMI_Client /home/clemente/Faculdade/CD/ProjetoCD-AMI/AMI_Client /home/clemente/Faculdade/CD/ProjetoCD-AMI/AMI_Client/build /home/clemente/Faculdade/CD/ProjetoCD-AMI/AMI_Client/build /home/clemente/Faculdade/CD/ProjetoCD-AMI/AMI_Client/build/CMakeFiles/ami_client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ami_client.dir/depend

