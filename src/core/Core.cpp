/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Core
*/

#include "Core.hpp"
#include <iostream>

Core::Core(std::string defaultLib)
    : _librariesGame(nullptr), _librariesRenderer(nullptr), _currGame(nullptr),
    _currRenderer(nullptr), _currWindow(nullptr)
{
    try {
        std::vector<std::string>  librariesPath;
        const std::string libPath = "./lib/";
        UniqueDirectory libDirectory = std::make_unique<Directory>(libPath);
        librariesPath = libDirectory->getListLibraries();
        _librariesGame =  std::make_unique<GameList>(librariesPath);
        _librariesRenderer = std::make_unique<GraphicList>(librariesPath, defaultLib);
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        throw std::runtime_error("Can't create Core class");
    }
}

Core::~Core()
{
}

void Core::_init()
{
    _currGame = _librariesGame->getCurrentGame();
    _currRenderer = _librariesRenderer->getCurrentLibrary();
    _currWindow = _currRenderer->createWindow({{800, 600},
        shared::graphics::WindowMode::FULLSCREEN, 60, "Ncurses Lib", "Arcade"});

}

void Core::_displayEntity(std::shared_ptr<shared::games::components::IDisplayableComponent> displayable)
{
    shared::graphics::EntityProps entityProps{
        .textureProps = {
            .texture = _currRenderer->createTexture(displayable->getTextureProps().sources.ascii,
                displayable->getTextureProps().sources.bin),
            .binTileSize = displayable->getTextureProps().sources.binTileSize,
            .origin = displayable->getTextureProps().origin
        },
        .size = displayable->getSize(),
        .position = displayable->getPosition()
    };
    _currWindow->render(entityProps);
}

void Core::_displayEntities(shared::games::entity::EntitiesMap entities)
{
    std::vector<shared::graphics::EntityProps> entitiesProps;
    std::shared_ptr<shared::graphics::ITexture> texture;
    shared::games::components::ComponentsMap components;
    shared::games::components::ComponentType type;

    for (auto &entity : entities) {
        components = entity.second.get()->getComponents();
        for (auto &component : components) {
            type = component.second.get()->getType();
            if (type == shared::games::components::ComponentType::DISPLAYABLE) {
                _displayEntity(std::dynamic_pointer_cast<shared::games::components::IDisplayableComponent>(component.second));
            }
        }
    }
}

Core::GeneralEventType Core::_handleEvents(std::vector<shared::graphics::events::Event> events)
{
    for (auto &event : events) {
        if (event.type == shared::graphics::events::EventType::KEY_PRESS) {
            shared::graphics::events::KeyPressEvent keyEvent =
                static_cast<shared::graphics::events::KeyPressEvent &>(event);
            if (keyEvent.getKeyCode().arrow == shared::graphics::events::LEFT) {
                _currWindow->close();
                return Core::GeneralEventType::EXIT;
            }
        }

    }
    events.clear();
    return Core::GeneralEventType::NONE;
}

void Core::runArcade()
{
    _init();
    std::vector<shared::graphics::events::Event> events;
    shared::games::entity::EntitiesMap gameEntities;

    while (true) {
        events = _currWindow->getEvents();
        if (_handleEvents(events) == Core::GeneralEventType::EXIT) {
            break;
        }
        gameEntities = _currGame->getEntities();
        _currWindow->clear();
        _currWindow->display();
        _displayEntities(gameEntities);
    }
}
