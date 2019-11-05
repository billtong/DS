# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.10)
# set the cxx standard 17
set (CMAKE_CXX_STANDARD 17)
# Set the project name
project (data-structure-and-algorithm)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
        src/CDijkstra.cpp
        src/CSearch.cpp
        src/CSubsetSum.cpp
        src/Main.cpp
        )

# Add an executable with the above sources
add_executable(data-structure-and-algorithm ${SOURCES})

# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/
target_include_directories(data-structure-and-algorithm
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        )
