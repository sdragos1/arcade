# Build Guide
## Introduction
#### Project Requirements:
You can build your project using either a Makefile or CMake.

Your CMakeLists.txt must build a program, at least three graphics dynamic libraries and at least two game
dynamic libraries at the root of the repository.

```bash
∼/B-OOP-400> mkdir ./build/ && cd ./build/
∼/B-OOP-400> cmake .. -G “Unix Makefiles” -DCMAKE_BUILD_TYPE=Release
[...]
∼/B-OOP-400> cmake --build .
[...]
∼/B-OOP-400> cd ..
∼/B-OOP-400> ls ./arcade ./lib/
./arcade
./lib/:
arcade_ncurses.so
arcade_pacman.so
arcade_sdl2.so
arcade_sfml.so
arcade_solarfox.so
```
------------

#### Why CMake for the project?
1. CMake provides a simpler and more abstracted way to describe the build process compared to writing Makefiles directly. This can make it easier for developers to understand and maintain the build system, especially for larger projects.

2. CMake supports more advanced features than traditional Makefiles, such as the ability to automatically locate dependencies, manage library dependencies, and generate package configuration files.

------------
#### The way we do it !
Currently we have a **Makefile** that calls our **CMake** files, thus making it easier for everyone on the project to build because we are more used to it.

We have a CMake file at the root of the repository **that doesnt need to be changed for the rest of the project.**

## How to build the libraries and games
#### Building a graphic library
To build our libraries we have a CMake file at in the `src/graphicals` folder that has a function for creating the dynamic libraries.

To build a graphical library for the ncurses for example you need two things:
1. A folder named `ncurses` in `src/graphical`
2. Add this line after the comment in the CMake file: `create_graphic_library(ncurses)`

Everything will be taken care of.

#### Building a game
The process will be the same. We have a CMake file at the `src/games`, that has a function for creating games.

To build a game like snake you need two things:
1. A folder named `snake` in `src/games`
2. Add this line after the comment in the CMake file `create_game(snake)`

## !!!Warning
The build wont work in these cases:
- You have two folders with the same name
- You have a folder with the incorrect name
- The CMake files are moved in the project

## Building the core
The core has a CMake file that is normally fine, and shouldn't be changed throughout the project
