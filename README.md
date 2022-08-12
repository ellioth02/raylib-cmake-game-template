# Raylib CMake Game Template

## Summary
A simple Raylib game template using CMake as the build system. CMake has been chosen to make the build system cross platform.

## Features
- This game template incorporates Raylib as a git submodule.
- CMake checks the git submodules when building. 
- CMake automaticly checks for new source .c files in /src/ when building

## Prerequisites
- CMake 3.12 or higher
- Git
- A CMake supported build system

## Supported Platfroms
I provide here a list of platforms for which I have tested to build this project on with CMake:
- Windows (Windows 10)
- Linux (Ubuntu 22.04.1 LTS)
- macOS (macOS Monterey on M1)

## Disclaimer
A list of common problems:
1. The automatic checking for new source .c files at build using GLOB can sometimes not work. The solution is to reconfigure the cmake project.
2. It can be a little daunting to build on linux, but check the CMake errors and install corresponding missing libraries and you should be fine.

## Credits
I created this template myself with some insperation from https://github.com/SasLuca/raylib-cmake-template.
The Raylib logo is from https://github.com/raysan5/raylib.
