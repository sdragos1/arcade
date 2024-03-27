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

        std::cout << _librariesRenderer->getCurrentLibrary()->getManifest().name << std::endl;
 
        shared::graphics::IWindow::WindowInitProps propWindow {
            .size = (shared::types::Vector2u) {1920, 1080},
            .mode = shared::graphics::IWindow::WINDOWED,
            .fps = 120,
            .title = "TITOUAN le bg",
            .icon = "null"
        };
 
        shared::graphics::TextureProps snakeHead {
            .texture = _librariesRenderer->getCurrentLibrary()->createTexture("../Arcade_assets/Snake/apple.png", "../Arcade_assets/Snake/apple.png"),
            .binTileSize = (shared::types::Vector2f) {10, 10},
            .origin = (shared::types::Vector2u) {0, 0},
            .size = (shared::types::Vector2u) {0, 0},
            .position = (shared::types::Vector2i) {50, 50}
        };
 
        std::unique_ptr<shared::graphics::IWindow> window = _librariesRenderer->getCurrentLibrary()->createWindow(propWindow);
 
        while (window->isOpen()) {
            std::vector<std::shared_ptr<shared::graphics::events::IEvent>> events = window->getEvents();
            for (int index = 0; index < events.size(); index++) {
                if (events[index]->getType() == shared::graphics::events::WINDOW_CLOSE) {
                    window->close();
                }
                if (events[index]->getType() == shared::graphics::events::KEY_PRESS) {
                    auto EventKey = std::dynamic_pointer_cast<shared::graphics::events::IKeyEvent>(events[index]);
                    
                    if (EventKey != nullptr) {
                        if (EventKey->getKeyType() == shared::graphics::events::IKeyEvent::ARROW) {
                            if (EventKey->getKeyCode().arrow == shared::graphics::events::IKeyEvent::ArrowCode::DOWN) {
                                snakeHead.position.y += 1;
                            }
                            if (EventKey->getKeyCode().arrow == shared::graphics::events::IKeyEvent::ArrowCode::UP) {
                                snakeHead.position.y -= 1;
                            }
                            if (EventKey->getKeyCode().arrow == shared::graphics::events::IKeyEvent::ArrowCode::LEFT) {
                                snakeHead.position.x -= 1;
                            }
                            if (EventKey->getKeyCode().arrow == shared::graphics::events::IKeyEvent::ArrowCode::RIGHT) {
                                snakeHead.position.x += 1;
                            }
                        }
                    }
                }
            }
            window->clear();
 
            window->render(snakeHead);
 
            window->display();
 
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        throw std::runtime_error("Can't create Core class");
    }
}

Core::~Core()
{
}


