cmake_minimum_required(VERSION 3.20)
project(4283-LowMem1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

add_executable(4283-LowMem1 src/main.cpp)

# Set working directory to src/ when running the binary
set_target_properties(4283-LowMem1 PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/src"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/src"
)
