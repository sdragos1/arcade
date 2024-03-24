/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Core
*/

#include "Core.hpp"
#include <iostream>

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
}

void Core::helpMessage()
{
    std::cout << "USAGE: ./arcade library" << std::endl;
    std::cout << "\tlibrary is the the graphics library to use initially" << std::endl;
}
