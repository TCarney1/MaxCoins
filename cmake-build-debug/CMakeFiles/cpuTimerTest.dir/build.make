# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Thoma\CLionProjects\cpuTimerTest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Thoma\CLionProjects\cpuTimerTest\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\cpuTimerTest.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\cpuTimerTest.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\cpuTimerTest.dir\flags.make

CMakeFiles\cpuTimerTest.dir\main.cpp.obj: CMakeFiles\cpuTimerTest.dir\flags.make
CMakeFiles\cpuTimerTest.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Thoma\CLionProjects\cpuTimerTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cpuTimerTest.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\cpuTimerTest.dir\main.cpp.obj /FdCMakeFiles\cpuTimerTest.dir\ /FS -c C:\Users\Thoma\CLionProjects\cpuTimerTest\main.cpp
<<

CMakeFiles\cpuTimerTest.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpuTimerTest.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx86\x86\cl.exe > CMakeFiles\cpuTimerTest.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Thoma\CLionProjects\cpuTimerTest\main.cpp
<<

CMakeFiles\cpuTimerTest.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpuTimerTest.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\cpuTimerTest.dir\main.cpp.s /c C:\Users\Thoma\CLionProjects\cpuTimerTest\main.cpp
<<

# Object files for target cpuTimerTest
cpuTimerTest_OBJECTS = \
"CMakeFiles\cpuTimerTest.dir\main.cpp.obj"

# External object files for target cpuTimerTest
cpuTimerTest_EXTERNAL_OBJECTS =

cpuTimerTest.exe: CMakeFiles\cpuTimerTest.dir\main.cpp.obj
cpuTimerTest.exe: CMakeFiles\cpuTimerTest.dir\build.make
cpuTimerTest.exe: CMakeFiles\cpuTimerTest.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Thoma\CLionProjects\cpuTimerTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cpuTimerTest.exe"
	"C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\cpuTimerTest.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1424~1.283\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\cpuTimerTest.dir\objects1.rsp @<<
 /out:cpuTimerTest.exe /implib:cpuTimerTest.lib /pdb:C:\Users\Thoma\CLionProjects\cpuTimerTest\cmake-build-debug\cpuTimerTest.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\cpuTimerTest.dir\build: cpuTimerTest.exe

.PHONY : CMakeFiles\cpuTimerTest.dir\build

CMakeFiles\cpuTimerTest.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\cpuTimerTest.dir\cmake_clean.cmake
.PHONY : CMakeFiles\cpuTimerTest.dir\clean

CMakeFiles\cpuTimerTest.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\Thoma\CLionProjects\cpuTimerTest C:\Users\Thoma\CLionProjects\cpuTimerTest C:\Users\Thoma\CLionProjects\cpuTimerTest\cmake-build-debug C:\Users\Thoma\CLionProjects\cpuTimerTest\cmake-build-debug C:\Users\Thoma\CLionProjects\cpuTimerTest\cmake-build-debug\CMakeFiles\cpuTimerTest.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\cpuTimerTest.dir\depend

