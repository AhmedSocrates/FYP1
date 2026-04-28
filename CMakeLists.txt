cmake_minimum_required(VERSION 3.10)
project(AgenticEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(glfw3_DIR "C:/msys64/ucrt64/lib/cmake/glfw3")

# Find GLFW
find_package(glfw3 REQUIRED)

# 1. Define the executable and the source files
add_executable(Engine src/main.cpp src/Engine.cpp)

# 2. Tell the Engine exactly where to find the .h files (CRITICAL FIX)
target_include_directories(Engine PRIVATE ${CMAKE_SOURCE_DIR}/include)

# 3. Link the libraries
target_link_libraries(Engine PRIVATE glfw opengl32)