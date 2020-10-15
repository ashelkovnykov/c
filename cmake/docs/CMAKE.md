# CMake

CMake is a cross-platform, FOSS build-management tool. It is compiler-independent and build-tool-independent. Build automation tools (such as Make, QT Creator, and Ninja) are, at a minimum, platform dependent. For example, a makefile configured for Windows 7 will not work for Ubuntu Linux. This can make it difficult and annoying to compile code for multiple systems, as the build automation tools will require unique configuration files, run from the target system.

CMake allows users to setup their build pipeline in a platform, build-tool, and compiler agnostic manner. These settings are later provided or inferred, and CMake generates the appropriate raw configuration files.

## Features

- Cross-compilation
- Multiple builds from a single source tree
- In-place/out-of-place builds
- Commandline and GUI interfaces
- Support for complex dependencies (e.g. part of project must be compiled to executable before generating code to be compiled into final application)
- Integration with most IDEs, such as Microsoft Visual Studio, XCode, Eclipse, and CLion


