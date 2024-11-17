cmake_minimum_required(VERSION 3.16)  

project(SpaceInvaders)  

set(CMAKE_CXX_STANDARD 20)  
set(CMAKE_CXX_STANDARD_REQUIRED ON) 

set(CMAKE_CXX_COMPILER "/usr/bin/g++")

file(GLOB SOURCES "src/*.cpp")
add_executable(SpaceInvaders ${SOURCES}
)

# Include headers
target_include_directories(SpaceInvaders
    PRIVATE
    ${CMAKE_SOURCE_DIR}/headers  # Adjust to your actual header folder
)

find_package(SFML 2.5 REQUIRED COMPONENTS graphics window system)
target_link_libraries(SpaceInvaders sfml-graphics sfml-window sfml-system)