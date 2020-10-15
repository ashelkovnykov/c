# Specifies minimum version of CMake which is required to correctly process this configuration file
# Alternate configuration:
#       cmake_minimum_required(VERSION 3.17.0...3.18.2)
cmake_minimum_required(VERSION 3.16.0)

# Mandatory command for declaring a CMake project and specifying core project info: name, version, description, homepage, language. The input to this
# command is injected into many CMake environment variables.
project(Example VERSION 0.1.0 DESCRIPTION "Example CMake project definition" HOMEPAGE_URL www.cmake.org/cmake/help/latest/index.html LANGUAGES C)

# Creates a new boolean option which users can control through the cache/CMake GUI.
option(CUSTOM_MATH "Use customized math functions from internal library" ON)

# Adds an executable target with the name "myExecutable", compiled from source file "main.c". The file name of the executable will be generated from
# the name using the conventions of the platform (i.e. "name" vs. "name.exe"). The source files can be omitted and specified later by the
# "target_sources()" command. Existing executables can be imported from outside the project and/or referenced by aliases.
add_executable(myExecutable ./src/main.c)

# Standard if command. See CMake language specification for exact functionality (which differs slightly from C/C++).
if (CUSTOM_MATH)
    # Adds a subdirectory to the build which contains a self-contained CMake target (executable or library). Note that the CMakeLists.txt contained
    # therein will be evaluated immediately, before continuing with the one which called it.
    add_subdirectory(./libs/math)

    # The list command manages user-created list variables which store arbitrary text data. There are various list sub-commands: LENGTH, GET, JOIN,
    # SUBLIST, FIND, APPEND, FILTER, INSERT, POP_BACK, POP_FRONT, PREPEND, REMOVE_ITEM, REMOVE_AT, REMOVE_DUPLICATES, TRANSFORM, REVERSE, and SORT.
    list(APPEND EXTRA_LIBS CustomMath)
endif ()

# CMake command used to configure source files by performing code injection. This example specifies that the template for a header file called
# "source1.h.in" should be read, processed by CMake, and the results stored as "source1.h". CMake variables can be referenced in the template file
# using the syntax "@VAR@" or "${VAR}". In addition, the special command #cmakedefine is available.
configure_file(templates/settings.h.in ./generated/settings.h)

# CMake command used to link a library (whether local or imported) to another target (library or executable). How/what kind of library is linked to
# the target has many configuration specifications, see language specification for more information.
target_link_libraries(myExecutable PUBLIC ${EXTRA_LIBS})

# Some CMake commands such as "configure_file()" generate new files that don't actually exist in the sources. The directories which contain these
# generated files need to be registered so that the files they contain can be correctly passed to the compiler after CMake generates the files.
target_include_directories(myExecutable PUBLIC "${PROJECT_BINARY_DIR}/generated")

# CMake command used to set CMake, CMake cache, and environment variables. It's possible to overwrite CMake variables in the parent scope with such a
# command. Note that environment variables overwritten this way are only overwritten for the current CMake process: not the process which called
# CMake, nor the system environment at large.
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# The install command allows the user to define installation rules. Installation rules can be set for four different types of objects: targets (i.e.
# executables, libraries, etc.), files, directories, and exports (files containing code which allow CMake to import parts of the installation tree
# from one project into another).
#
# Each of these install objects has slightly different settings, but there are several core settings which apply to all objects:
# DESTINATION:      The directory on disk to which the file(s) for the object will be installed
# PERMISSIONS:      The file permissions for the installed file(s)
# CONFIGURATIONS:   The type of installation to perform (i.e. debug, release, something else entirely)
# COMPONENT:        The name of the installation component that this rule is associated with (so that installation can be compartmentalized)
# EXCLUDE_FROM_ALL: Whether to exclude this object from full installations (can only be installed by directly calling its installation component)
install(TARGETS myExecutable DESTINATION "${CMAKE_INSTALL_PREFIX}/bin")
install(FILES "${PROJECT_BINARY_DIR}/generated/settings.h"  DESTINATION "${CMAKE_INSTALL_PREFIX}/include")

# This command has two uses: to generate custom output which can then be used by the following CMake commands, or to perform a custom operation
# as a part of building some target. This below example uses the signature for the second use case.
add_custom_command(TARGET myExecutable
        POST_BUILD
        COMMAND echo "Compiled ${CMAKE_PROJECT_NAME} ${CMAKE_PROJECT_VERSION}"
        USES_TERMINAL)
