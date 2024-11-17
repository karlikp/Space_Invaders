
# 👾 Space Invaders
Space Invaders is a classic arcade shooter game where players control a ship with laser cannon to defend Earth by destroying waves of descending alien invaders before they reach the ground.

## Table of contents:
1. [Introduction](#Introduction)
2. [Requirements](#Requirements)
3. [Installation](#Installation)
4. [Usage](#Usage)
   
### 1. Introduction:

This project was my main assignment during the fourth semester of my studies, developed as part of a computer programming course.

I chose to create this game because it reminded me of my favorite childhood game, which inspired me to bring a similar experience to life.

## 2. Requirements:
- 2.1. Linux (tested on Ubuntu 22.04 LTS)
    - g++ compiler
      ```bash
      sudo apt update
      sudo apt install g++
      ```
    - library SFML
      ```bash
      sudo apt install libsfml-dev
      ```
    - CMake
      ```bash
      sudo apt install cmake
      ```
- 2.2. Windows (tested on Windows 11)
    - g++ compiler (https://www.msys2.org/)
    - configured SFML library (https://www.sfml-dev.org/download.php)
    - CMake (https://cmake.org/download/)

## 3. Installation:
- Download repository Space_Invaders
- Go to Space_Invaders directory
 ```bash
 cd /path/to/Space_Invaders
 ```
- Create build directory and go there
 ```bash
 mkdir build
 cd build
```
- Set up a project build system
 ```bash
 cmake ..
```
- build project with Makefile
```
make
```
   - start program (on Linux)
   ```bash
   ./Spacelnvaders
   ```
   - start program (on Windows)
   ```bash
   SpaceInvaders
   ```
## Usage:
In the progress
