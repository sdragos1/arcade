/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Core
*/

#include <iostream>
#include "Core.hpp"

Core::Core(std::string defaultLib)
{
    try {
        const std::string libPath = "./lib/";
        UniqueDirectory libDirectory = std::make_unique<Directory>(libPath);
        _librariesPath = libDirectory->getListLibraries();
        _librariesGame =  std::make_unique<GameList>(_librariesPath);
        _librariesRenderer = std::make_unique<GraphicList>(_librariesPath, defaultLib);
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        throw std::runtime_error("Can't create Core class");
    }
}

Core::~Core()
{
    std::cout << "Destructor in Core" << std::endl;
}


