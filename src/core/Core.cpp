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

void Core::handleEvents(std::unique_ptr<shared::graphics::IWindow> window)
{
    std::vector<shared::graphics::events::Event> events = window->getEvents();
    for (auto &event : events) {
        if (event.type == shared::graphics::events::EventType::KEY_PRESS) {
            shared::graphics::events::KeyPressEvent keyEvent = std::get<shared::graphics::events::KeyPressEvent>(event);
            if (keyEvent.getKeyCode().arrow == shared::graphics::events::UP) {
                window->close();
            }
        }
    }
}

void Core::runArcade()
{
    std::shared_ptr<shared::games::IGame> game = _librariesGame->getCurrentGame();
    std::shared_ptr<shared::graphics::IGraphicsProvider> renderer = _librariesRenderer->getCurrentLibrary();

    std::unique_ptr<shared::graphics::IWindow> window = renderer.get()->createWindow({{800, 600},
        shared::graphics::WindowMode::FULLSCREEN, 60, "Ncurses Lib", "Arcade"});
    while (true) {
        window->display();
        window->clear();
    }
}
