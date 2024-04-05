# Add Graphic Library Guide
## Introduction
#### Project Explication:

In the Arcade projects you have the possibility to add your own graphic library.

In order to be able to change in full millieux of the games on the libraries you just added is not that great?
Be careful not to add 2 times the same libraries although it is possible it is useless.

Of course there are certain rules to respect that we will address.

## The way we do it !

### Basic:

To do this please create your folder at this place "src/graphicals" and named
this repertoir in minicules by the name of your graphic libraries.

------------

Then for your libraries to be added to the construction of our projects,
I let you go in the file "src/graphicals/CMakeLists.txt".
When you are in this file, at the end you should see:

```bash
## Add the graphical libraries here "create_graphic_library(<library_name>)"
set(SFML_DEPENDENCY sfml-graphics sfml-system sfml-window sfml-audio)
set(SDL2_DEPENDENCY SDL2 SDL2_image SDL2_ttf SDL2_mixer)

create_graphic_library(ncurses ncurses)
create_graphic_library(sfml "${SFML_DEPENDENCY}")
create_graphic_library(sdl2 "${SDL2_DEPENDENCY}")
```

I will let you add your line with the name of the library and its dependencies, if any:
set(YOUR_LIBRARY_DEPENDENCY your_dependency1 your_dependency2 ...)

Then you would add the line with the name of the library:
create_graphic_library(your_library "${YOUR_LIBRARY_DEPENDENCY}")

------------

### Let's build it:

It should be noted that in the architecture of graphic libraries there are 5 classes:
1. The main class on behalf of your libraries
2. The window class
3. The texture class
4. Text font class
5. The Sound Class

------------

#### Your Library Class (Main Class):

Create your files .hpp and .cpp, créer

