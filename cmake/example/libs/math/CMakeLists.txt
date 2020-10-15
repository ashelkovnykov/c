cmake_minimum_required(VERSION 3.16.0)

# Adds a library target to be built from the source files listed (now, or later in "target_sources()" command). There are 7 types of library:
#
# 1. STATIC: contain object files for use when linking other targets
# 2. SHARED: dynamically linked and loaded at runtime
# 3. MODULE: plugins which are not linked to other targets, but can be loaded dynamically at runtime
# 4. OBJECT: compile source files, but do not archive/link the object files into a library. Instead, other targets may reference the objects as a
#            source
# 5. IMPORT: reference to a library located outside of the project
# 6. ALIAS: alias for an existing library
# 7. INTERFACE: does not have sources or directly generate output, but can have properties set on it which other libraries can import
add_library(CustomMath SHARED ./src/sqr.c)

# Create list of all source directories for the library
list(APPEND SOURCE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND SOURCE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/headers")
list(APPEND SOURCE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/src")

# Want to enforce that anyone linking to this library must include the sources to compile correctly, whereas this library does not need to include
# the sources as it does not need to be compiled on its own. The correct way to do this is using the INTERFACE keyword, which means that consumers
# require the specified sources, but the producer doesn't.
target_include_directories(CustomMath INTERFACE ${SOURCE_DIRS})

install(TARGETS CustomMath DESTINATION "${CMAKE_INSTALL_PREFIX}/lib")
install(FILES mathLib.h headers/sqr.h DESTINATION "${CMAKE_INSTALL_PREFIX}/include")
