
cmake_minimum_required(VERSION 3.8)

project(MyProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable(MyExecutable
    main.cpp
)

target_sources(MyExecutable PRIVATE
    src/FileSystemService/FileSystem.cpp
)
target_sources(MyExecutable PRIVATE
    src/Formatter/FileSystemFormatter.cpp
)
target_include_directories(MyExecutable PRIVATE 

    src/FileSystemService 
    src/Formatter
)
