# 👾 Space Invaders
Space Invaders is a classic arcade shooter game where players control a ship with laser cannon to defend Earth by destroying waves of descending alien invaders before they reach the ground.

## Table of contents:
1. [Introduction](#1-introduction)
2. [Requirements](#2-requirements)
3. [Installation](#3-installation)
4. [Usage](#4-usage)
5. [Gallery](#5-gallery)
   
## 1. Introduction:

This project was my main assignment during the fourth semester of my studies, developed as part of a computer programming course.

I chose to create this game because it reminded me of my favorite childhood game, which inspired me to bring a similar experience to life.

## 2. Requirements:
   - 2.1. Operating system:
       - Linux (tested on Ubuntu 22.04 LTS)
       <!--- Windows (tested on Windows 11)-->
   - 2.2. Dependence:
       - g++ compiler
       - SFML library
       - CMake

## 3. Installation:
   - 3.1. Dependence for Linux (ubuntu 22.04):
       - g++ compiler
         ```bash
         sudo apt update
         sudo apt install g++
         ```
       - SFML library
         ```bash
         sudo apt install libsfml-dev
         ```
       - CMake
         ```bash
         sudo apt install cmake
         ```
  <!-- - 3.2. Dependence for Windows:
       - g++ compiler (https://www.msys2.org/)
       - configured SFML library (https://www.sfml-dev.org/download.php)
       - CMake (https://cmake.org/download/)-->

## 4. Usage:
   - 4.1 download repository:
      ```bash
      git clone https://github.com/karlikp/Space_Invaders.git
      ```
      or for SSH standard:
      ```bash
      git@github.com:karlikp/Space_Invaders.git
      ```
   - 4.2 Go to Space_Invaders directory
      ```bash
      cd /path/to/Space_Invaders
      ```
   - 4.3 Create build directory and go there
      ```bash
      mkdir build
      cd build
      ```
   - 4.4 Set up a project build system
      ```bash
      cmake ..
      ```
   - 4.5 build project with Makefile
      ```
      make
      ```
   - 4.6 start program:
     ```bash
     ./Spacelnvaders
     ```
      <!--- on Windows:
        ```bash
        SpaceInvaders
        ```-->
## 5. Gallery:

<div align="center">
  <img src="https://github.com/user-attachments/assets/42730d4b-dde6-4afd-85a4-f89dac8c2d70" alt="menu">
  <p>Fig. 1. Main menu</p>
</div>
<br>

<div align="center">
  <img src="https://github.com/user-attachments/assets/fa20878b-772c-4e59-af6b-8ef8f80ab02f" alt="Screenshot (351)">
  <p>Fig. 2. "New player" option</p>
</div>
<br>

<div align="center">
  <img src="https://github.com/user-attachments/assets/08577581-5845-4e02-b3c8-2cee7c522774" alt="Screenshot (309)">
  <p>Fig. 3. "Continue" option</p>
</div>
<br>

<div align="center">
  <img src="https://github.com/user-attachments/assets/70709a57-2552-493b-a331-40f6f305e804" alt="Score Table">
  <p>Fig. 4. "Score Table" option</p>
</div>
<br>

<div align="center">
  <img src="https://github.com/user-attachments/assets/8a500db2-0e85-4b60-9ad9-35bb3035ac08" alt="Rules Option">
  <p>Fig. 5. "Rules" option with the ability to use scrolling</p>
</div>
<br>

<div align="center">
  <img src="https://github.com/user-attachments/assets/3e12aa2f-4141-4148-98d9-619461d3d652" alt="Gameplay Initial Phase">
  <p>Fig. 6. Gameplay in the initial phase</p>
</div>
<br>

<div align="center">
  <img src="https://github.com/user-attachments/assets/ea6c5803-6010-459e-bcfe-be9818cc5743" alt="Gameplay After Triple Shot">
  <p>Fig. 7. Gameplay after getting the triple shot bonus</p>
</div>
<br>

<div align="center">
  <img src="https://github.com/user-attachments/assets/5a4ead27-4ff7-4cfa-b672-7d2a8a69f169" alt="Victory Message">
  <p>Fig. 8. Message after the victory</p>
</div>
<br>















