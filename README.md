# Advent of Code Solutions - C++ using CMake + vcpkg

This is a fork of [cpp-vcpkg-seed](https://github.com/legends2k/cpp-vcpkg-seed) adapted for Advent of Code solutions.
Cross-platform, cross-toolchain C++ project using CMake as meta-build system and
vcpkg as package manager for solving Advent of Code puzzles.

# Tools

Make sure the following tools are installed:

* C++ compiler toolchain (just pick one)
  - **Windows**: VC++ (Visual Studio 2017+), [MinGW][] (GCC on Windows), Clang
  - **Linux**: GCC, Clang
  - **Mac**: Clang (Xcode), GCC
* [CMake][]
* [vcpkg][]

**`cmake` should be in `PATH`**.  Verify if `cmake --version`
displays the version properly.

# Build

Make sure `VCPKG_ROOT` is set correctly depending on how you set it up.

``` shell
git clone --recursive https://github.com/vineethkuttan/advent-of-code-2025.git

cd advent-of-code-2025

cmake -B build -DCMAKE_TOOLCHAIN_FILE="$env:VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake"

cmake --build build
```

This should build the day executables under `//build/dayX/Debug/` (or `//build/dayX/Release/` for release builds).

Each day's CMakeLists.txt is configured to automatically copy the corresponding input.txt file from `aoc-questions-inputs/2025/dayX/` to the build directory.

## IDE

CMake can generate project/solution files for different IDEs including

* Visual Studio
* QtCreator
* Eclipse
* Sublime Text
* CodeBlocks
* Codelite

Locate project files at `//build` directory after project is built from command
line.  Use `-G` in the `cmake -B` command above to change from default IDE;
refer `cmake --help` for details.

# Dependencies

This Advent of Code project currently has no external dependencies and uses only standard C++ libraries. 
The `vcpkg.json` manifest is included for future use if you need additional libraries for complex solutions.

```json
{
  "dependencies": []
}
```

You can add packages as needed for specific problems (e.g., graph libraries, regex, or visualization tools).
Check [available packages in vcpkg][packages] when adding dependencies.

Refer [vcpkg manifest documentation][] for details.

# Project Structure

Each day's solution is organized in its own folder:
- `dayX/` - Contains the C++ source files (`dayX.cpp`, `dayX.h`) and CMakeLists.txt
- `aoc-questions-inputs/2025/dayX/` - Contains the puzzle input (`input.txt`)

The build system automatically copies input files to the appropriate build directories.


# References

* [CMake Documentation][cmake-doc]
* [vcpkg Manifest Mode: CMake Example][vcpkg cmake example]


[CMake]: https://cmake.org/
[vcpkg]: https://vcpkg.io/en/getting-started.html
[mingw]: https://sourceforge.net/projects/mingw-w64/files/mingw-w64/mingw-w64-release/
[fltk]: https://www.fltk.org/
[spdlog]: https://github.com/gabime/spdlog
[vcpkg manifest documentation]: https://vcpkg.io/en/docs/users/manifests.html
[vcpkg cmake example]: https://vcpkg.io/en/docs/examples/manifest-mode-cmake.html
[cmake-doc]: https://cmake.org/cmake/help/latest/index.html
[packages]: https://vcpkg.io/en/packages.html
