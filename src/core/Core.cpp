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
        shared::graphics::IWindow::WindowMode::FULLSCREEN, 60, "Ncurses Lib", "Arcade"});

}

void Core::_displayEntity(std::shared_ptr<shared::games::components::ITextureComponent> displayable)
{
    shared::graphics::TextureProps entityProps{
        .texture = _currRenderer->createTexture(displayable->getTextureProps().sources.ascii,
            displayable->getTextureProps().sources.bin),
        .binTileSize = displayable->getTextureProps().sources.binTileSize,
        .origin = displayable->getTextureProps().origin,
        .size = displayable->getSize(),
        .position = displayable->getPosition()
    };
    _currWindow->render(entityProps);
}

void Core::_displayEntities(shared::games::entity::EntitiesMap entities)
{
    std::vector<shared::graphics::TextureProps> entitiesProps;
    std::shared_ptr<shared::graphics::ITexture> texture;
    shared::games::components::ComponentsMap components;
    shared::games::components::ComponentType type;

    for (auto &entity : entities) {
        components = entity->getComponents();
        for (auto &component : components) {
            type = component->getType();
            if (type == shared::games::components::ComponentType::DISPLAYABLE) {
                _displayEntity(std::dynamic_pointer_cast<shared::games::components::ITextureComponent>(component));
            }
        }
    }
}

Core::GeneralEventType Core::_handleEvents(shared::games::entity::EntitiesMap entities)
{
    std::vector<shared::graphics::events::EventPtr> events = _currWindow->getEvents();
    for (auto &event : events) {
        if (event->getType() == shared::graphics::events::EventType::KEY_PRESS) {
            std::shared_ptr<shared::graphics::events::KeyPressedEvent> keyEvent = std::dynamic_pointer_cast<shared::graphics::events::KeyPressedEvent>(event);
            if (keyEvent->getKeyCode().arrow == shared::graphics::events::IKeyEvent::UP) {
                _currWindow->close();
                return Core::GeneralEventType::EXIT;
            }
            for (auto &entity: entities) {
                for (auto &component : entity->getComponents()) {
                    if (component->getType() == shared::games::components::ComponentType::KEYBOARD) {
                    }
                }
            }
        }
    }
    events.clear();
    return Core::GeneralEventType::NONE;
}

void Core::runArcade()
{
    _init();
    std::vector<shared::graphics::events::IEvent> events;
    shared::games::entity::EntitiesMap gameEntities;

    while (true) {
        gameEntities = _currGame->getEntities();
        if (_handleEvents(gameEntities) == Core::GeneralEventType::EXIT) {
            break;
        }
        _currWindow->clear();
        _currWindow->display();
        _displayEntities(gameEntities);
    }
}
