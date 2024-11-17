
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

![Screenshot (272)](https://github.com/user-attachments/assets/42730d4b-dde6-4afd-85a4-f89dac8c2d70)
Fig. 1. Main menu

![Screenshot (351)](https://github.com/user-attachments/assets/fa20878b-772c-4e59-af6b-8ef8f80ab02f)
Fig. 2. "New player" option


![Screenshot (309)](https://github.com/user-attachments/assets/08577581-5845-4e02-b3c8-2cee7c522774)
Fig. 3. "Continue" option

![image](https://github.com/user-attachments/assets/70709a57-2552-493b-a331-40f6f305e804)
Fig. 4. "Score Table" option

![image](https://github.com/user-attachments/assets/8a500db2-0e85-4b60-9ad9-35bb3035ac08)
Fig. 5. "Rules" option with the ability to use scrolling


![Screenshot (325)](https://github.com/user-attachments/assets/3e12aa2f-4141-4148-98d9-619461d3d652)
Fig. 6. Gameplay in the initial phase

![Screenshot (288)](https://github.com/user-attachments/assets/ea6c5803-6010-459e-bcfe-be9818cc5743)
Fig. 8. Gameplay after getting the triple shot bonus

![image](https://github.com/user-attachments/assets/5a4ead27-4ff7-4cfa-b672-7d2a8a69f169)
Fig. 9. Message after the victory















