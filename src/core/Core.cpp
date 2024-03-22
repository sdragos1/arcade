/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Core
*/

#include "Core.hpp"

Core::Core()
{
    try {
        const std::string libPath = "./lib/";
        UniqueDirectory libDirectory = std::make_unique<Directory>(libPath);
        _librariesPath = libDirectory->getListLibraries();
        _librariesGame =  std::make_unique<LibraryList<shared::games::IGame>>(shared::types::LibraryType::GAME, _librariesPath);
        _librariesRenderer = std::make_unique<LibraryList<shared::graphics::IGraphicsProvider>>(shared::types::LibraryType::GRAPHIC, _librariesPath);
        
        // _librariesRenderer->getCurrentLibrary()->init();
        // _librariesRenderer->incrementeIndex();
        // _librariesRenderer->getCurrentLibrary()->init();
        // _librariesRenderer->incrementeIndex();
        // _librariesRenderer->getCurrentLibrary()->init();

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
