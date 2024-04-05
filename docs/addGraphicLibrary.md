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
4. The font class
5. The Sound Class

Remember that each. cpp file you create must be added to the **CMakeLists.txt**.

------------

#### Your Library Class (Main Class):

Create your files . hpp and . cpp, create your class on behalf of your libraries that must
inherit the **"shared::graphics::IGraphicsProvider"** class. This class will relay to
your other classes, as it will be used to create the **Window**, **Sound**, **Texture** and **Font**.
So implement your functions by overriding the functions of the class "shared::graphics::IGraphicsProvider".
These functions must of course return class them by creating them.

Here are the functions a override:

```bash
/**
* @brief Get the manifest of the graphics library
*
* @return Manifest of the graphics library
*/
virtual const GraphicsManifest &getManifest(void) const noexcept = 0;

/**
* @brief Create a new window object
*
* @param windowProps Properties to use to init the window
* @return Created window object
*/
virtual std::unique_ptr<IWindow> createWindow(const IWindow::WindowInitProps &windowProps) = 0;

/**
* @brief Create a sound object
*
* @param path Path of the sound file
* @return Created sound object
*/
virtual std::shared_ptr<ISound> createSound(const std::string &path) = 0;

/**
* @brief Create a texture object
*
* @param bin Path of the binary texture file
* @param ascii Path of the ascii texture file
* @return Created texture object
*/
virtual std::shared_ptr<ITexture> createTexture(const std::string &bin, const std::string &ascii) = 0;

/**
* @brief Create a font object
*
* @param path Path of the font file
* @return Created font object
*/
virtual std::shared_ptr<IFont> createFont(const std::string &path) = 0;
```
------------

#### The Window Class:

Create the Window directory, in which you can create your . hpp and . cpp files,

This class is the second main class, it serves to create the window, render the images,
the texts, and manage the events. As the main class and for all the next classes you will have to
override all functions.

This class inherit from **"shared::graphics::IWindow"**

Here is a brief overview of the a override functions:

```bash
/**
* @brief Render the texture of entity with given properties
*
* @param props Properties of the entity & texture to render
*/
virtual void render(const TextureProps &props) = 0;

/**
* @brief Render the text of entity with given properties
*
* @param props Properties of the entity & text to render
*/
virtual void render(const TextProps &props) = 0;

/**
* @brief Clear the content of the window
*
*/
virtual void clear(void) = 0;

/**
* @brief Display the content of the window
*
*/
virtual void display(void) = 0;

/**
* @brief Close the window
*
*/
virtual void close(void) = 0;
```

------------

#### The texture Class:

This class is used to create the texture of the image you want to appear on
your window and therefore this class will be used in the Window class and more
especially by the render function which serves to give the images to the window for it to be displayed.

This class inherit from **"shared::graphics::ITexture"**

------------

#### Font class

This class is used to create the font of the text you want to appear on
your window and therefore this class will be used in the Window class and more
especially by the render function which serves to give the images to the window for it to be displayed.

This class inherit from **"shared::graphics::IFont"**

------------

#### Sound Class

This class is used to manage the sound on the libraries you want to add, I let you create the files . cpp and . hpp,
where you will override the functions of the ISound class by implementing the sound system with the library functions 
that you want to add to the arcade project.

This class inherit from **"shared::graphics::ISound"**

------------

### Shared Library

If you wish to have more information about the implementation of the libraries I suggest you go to the folder
**"common/"** where you will find all the interfaces that will inherit your class. These interfaces are domesticated and explained.
If the common folder does not exist I redirect you to this url: **https://github.com/G-Epitech/MAYBDF-ArcadeShared.git**
