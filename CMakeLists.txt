# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name and language
project(RobotSimulator LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find SFML package
# Adjust the path to where your SFML is installed
set(SFML_DIR C:/Users/auahm/Documents/SFML)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${SFML_DIR}/cmake/Modules/")

# Find SFML components
find_package(SFML REQUIRED COMPONENTS 
    system 
    window 
    graphics 
    network 
    audio
)

# Add executable
file(GLOB SOURCE_FILES 
    src/*.cpp
    src/*.h
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE 
    ${SFML_INCLUDE_DIR}
)

# Link libraries
target_link_libraries(${PROJECT_NAME} 
    sfml-system 
    sfml-window 
    sfml-graphics 
    sfml-network 
    sfml-audio
)

# Optional: Add compiler warnings
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()