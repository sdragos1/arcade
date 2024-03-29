/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Core
*/

#include <iostream>
#include "Core.hpp"

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
        shared::graphics::IWindow::WindowMode::WINDOWED, 60, "Ncurses Lib", ICON_PATH});
}

void Core::_displayEntityText(std::shared_ptr<shared::games::components::ITextComponent> displayable)
{
    shared::games::components::ITextComponent::TextProps textProps = displayable->getTextProps();
    std::shared_ptr<IFont> font = _currRenderer->createFont(textProps.font.path);
    shared::graphics::TextProps text{
        .font = font,
        .fontSize = textProps.font.size,
        .content = textProps.content,
        .align = CoreUtils::mapTextAlign(textProps.align),
        .verticalAlign = CoreUtils::mapTextVerticalAlign(textProps.verticalAlign),
        .color = textProps.color,
        .size = displayable->getSize(),
        .position = displayable->getPosition()
    };
    _currWindow->render(text);
}

void Core::_displayEntityTexture(std::shared_ptr<shared::games::components::ITextureComponent> displayable)
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
            if (type == shared::games::components::ComponentType::TEXTURE) {
                _displayEntityTexture(std::dynamic_pointer_cast<shared::games::components::ITextureComponent>(component));
            }
            if (type == shared::games::components::ComponentType::TEXT) {
                std::shared_ptr <shared::games::components::ITextComponent> textComponent =
                    std::dynamic_pointer_cast<shared::games::components::ITextComponent>(component);
                _displayEntityText(textComponent);
            }
        }
    }
}

void Core::_handleEntitiesKeyEvent(shared::games::entity::EntitiesMap entities,
std::shared_ptr<shared::graphics::events::KeyPressedEvent> keyEvent)
{
    shared::games::components::ComponentsMap components;
    shared::games::components::ComponentType type;
    std::shared_ptr<shared::games::components::IKeyboardComponent> keyboard = nullptr;
    shared::games::components::IKeyboardComponent::KeyData keyData;

    keyData = CoreUtils::convertKey(keyEvent->getKeyCode(), keyEvent->getKeyType());
    for (auto &entity : entities) {
        components = entity->getComponents();
        for (auto &component : components) {
            type = component->getType();
            if (type == shared::games::components::ComponentType::KEYBOARD) {
                keyboard = std::dynamic_pointer_cast<shared::games::components::IKeyboardComponent>(component);
                keyboard->onKeyPress(_currGame, keyData);
            }
        }
    }
}

Core::GeneralEventType Core::_coreEvents(std::shared_ptr<shared::graphics::events::KeyPressedEvent> keyEvent)
{
    switch (keyEvent->getKeyCode().character)
    {
        case 'a':
            return Core::GeneralEventType::EXIT;
            break;
        case 'z':
            return Core::GeneralEventType::NEXT_GAME;
            break;
        case 's':
            return Core::GeneralEventType::PREV_GAME;
            break;
        case 'd':
            return Core::GeneralEventType::NEXT_GRAPHICS;
            break;
        case 'q':
            return Core::GeneralEventType::PREV_GRAPHICS;
            break;
        case 'r':
            return Core::GeneralEventType::RESTART_GAME;
            break;
        default:
            return Core::GeneralEventType::NONE;
    }
}

Core::GeneralEventType Core::_handleEvents(shared::games::entity::EntitiesMap entities)
{
    std::vector<shared::graphics::events::EventPtr> events = _currWindow->getEvents();

    if (events.size() == 0) {
        return Core::GeneralEventType::NONE;
    }
    for (auto &event : events) {
        if (event->getType() == shared::graphics::events::EventType::WINDOW_CLOSE) {
            _currWindow->close();
            return Core::GeneralEventType::EXIT;
        }
        if (event->getType() == shared::graphics::events::EventType::KEY_PRESS) {
            std::shared_ptr<shared::graphics::events::KeyPressedEvent> keyEvent =
                std::dynamic_pointer_cast<shared::graphics::events::KeyPressedEvent>(event);
            if (_coreEvents(keyEvent) == Core::GeneralEventType::EXIT) {
                _currWindow->close();
                return Core::GeneralEventType::EXIT;
            }
            _handleEntitiesKeyEvent(entities, keyEvent);
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
        _displayEntities(gameEntities);
        _currWindow->display();
    }
}
