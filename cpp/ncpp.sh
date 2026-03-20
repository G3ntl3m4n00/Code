#!/bin/bash

PROJECT_NAME=${1:-"my_project"}

mkdir -p "$PROJECT_NAME"/{src,include,build,data}

# Main source file
touch "$PROJECT_NAME/src/main.cpp"

# CMakeLists.txt
cat > "$PROJECT_NAME/CMakeLists.txt" << EOF
cmake_minimum_required(VERSION 3.20)
project($PROJECT_NAME)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

add_executable($PROJECT_NAME src/main.cpp)

# Set working directory to src/ when running the binary
set_target_properties($PROJECT_NAME PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "\${CMAKE_SOURCE_DIR}/src"
    RUNTIME_OUTPUT_DIRECTORY "\${CMAKE_SOURCE_DIR}/src"
)
EOF


# Generate compile_commands.json for clangd
cd "$PROJECT_NAME/build"
cmake .. -DCMAKE_BUILD_TYPE=Debug > /dev/null 2>&1
ln -sf build/compile_commands.json ../compile_commands.json

echo "✓ Project '$PROJECT_NAME' created"
echo "  cd $PROJECT_NAME/src"
echo "  cmake --build ../build && ./$PROJECT_NAME"

cd .. && nvim
