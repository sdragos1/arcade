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
    _currRenderer(nullptr), _currWindow(nullptr), _currLibIndex(0)
{
    try {
        std::vector<std::string>  librariesPath;
        const std::string libPath = "./lib/";
        UniqueDirectory libDirectory = std::make_unique<Directory>(libPath);
        librariesPath = libDirectory->getListLibraries();
        _librariesGame =  std::make_unique<GameList>(librariesPath);
        _librariesRenderer = std::make_unique<GraphicList>(librariesPath, defaultLib);
        _currLibIndex = _librariesRenderer->getIndex();

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        throw std::runtime_error("Can't create Core class");
    }
}

Core::~Core()
{
    std::cout << "Destructor in Core" << std::endl;
}

void Core::_initGraphicLib()
{
    _currRenderer = _librariesRenderer->getCurrentLibrary();
    _currWindow = _currRenderer->createWindow({{800, 600},
        shared::graphics::IWindow::WindowMode::WINDOWED, 60, "Ncurses Lib", ICON_PATH});
}

void Core::_displayEntityText(std::shared_ptr<components::ITextComponent> displayable)
{
    components::ITextComponent::TextProps textProps = displayable->getTextProps();
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

void Core::_displayEntityTexture(std::shared_ptr<components::ITextureComponent> displayable)
{
    shared::graphics::TextureProps entityProps{
        .texture = _currRenderer->createTexture(displayable->getTextureProps().sources.bin,
            displayable->getTextureProps().sources.ascii),
        .binTileSize = displayable->getTextureProps().sources.binTileSize,
        .origin = displayable->getTextureProps().origin,
        .size = displayable->getSize(),
        .position = displayable->getPosition()
    };
    _currWindow->render(entityProps);
}

void Core::_displayEntities(entity::EntitiesMap entities)
{
    std::vector<shared::graphics::TextureProps> entitiesProps;
    std::shared_ptr<shared::graphics::ITexture> texture;
    components::ComponentsMap components;
    components::ComponentType type;

    for (auto &entity : entities) {
        components = entity->getComponents();
        for (auto &component : components) {
            type = component->getType();
            if (type == components::ComponentType::TEXTURE) {
                _displayEntityTexture(
                    std::dynamic_pointer_cast<components::ITextureComponent>(component));
            }
            if (type == components::ComponentType::TEXT) {
                _displayEntityText(
                    std::dynamic_pointer_cast<components::ITextComponent>(component));
            }
        }
    }
}

void Core::_handleEntitiesKeyEvent(entity::EntitiesMap entities,
std::shared_ptr<shared::graphics::events::KeyPressedEvent> keyEvent)
{
    components::ComponentsMap components;
    components::ComponentType type;
    std::shared_ptr<components::IKeyboardComponent> keyboard = nullptr;
    components::IKeyboardComponent::KeyData keyData;

    keyData = CoreUtils::convertKey(keyEvent->getKeyCode(), keyEvent->getKeyType());
    for (auto &entity : entities) {
        components = entity->getComponents();
        for (auto &component : components) {
            type = component->getType();
            if (type == components::ComponentType::KEYBOARD) {
                keyboard = std::dynamic_pointer_cast<components::IKeyboardComponent>(component);
                keyboard->onKeyPress(_currGame, keyData);
            }
        }
    }
}

void Core::_handleGraphicSwitch()
{
    if (_currLibIndex != _librariesRenderer->getIndex()) {
        _currLibIndex = _librariesRenderer->getIndex();
    }
}

Core::GeneralEventType Core::_coreEvents(std::shared_ptr<events::KeyPressedEvent> keyEvent)
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

void Core::_handleEvents(entity::EntitiesMap entities)
{
    std::vector<shared::graphics::events::EventPtr> events = _currWindow->getEvents();

    if (events.size() == 0) {
        return;
    }
    for (auto &event : events) {
        if (event->getType() == shared::graphics::events::EventType::WINDOW_CLOSE) {
            _currWindow->close();
            return;
        }
        if (event->getType() == shared::graphics::events::EventType::KEY_PRESS) {
            std::shared_ptr<shared::graphics::events::KeyPressedEvent> keyEvent =
                std::dynamic_pointer_cast<shared::graphics::events::KeyPressedEvent>(event);
            auto coreEvent = _coreEvents(keyEvent);
            if (coreEvent == Core::GeneralEventType::EXIT) {
                _currWindow->close();
                return;
            }
            if (coreEvent == Core::GeneralEventType::NEXT_GRAPHICS) {
                _librariesRenderer->incrementIndex();
                return;
            }
            if (coreEvent == Core::GeneralEventType::PREV_GRAPHICS) {
                _librariesRenderer->decrementIndex();
                return;
            }
            _handleEntitiesKeyEvent(entities, keyEvent);
        }
    }
    events.clear();
}

void Core::runArcade()
{
    _currGame = _librariesGame->getCurrentGame();
    _initGraphicLib();
    std::vector<shared::graphics::events::IEvent> events;
    shared::games::entity::EntitiesMap gameEntities;
    auto prevTime = std::chrono::high_resolution_clock::now();

    while (_currWindow->isOpen()) {
        _handleGraphicSwitch();
        auto currentTime = std::chrono::high_resolution_clock::now();
        auto deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(prevTime -
            currentTime);
        _currGame->compute(deltaTime);
        prevTime = currentTime;
        gameEntities = _currGame->getEntities();
        _handleEvents(gameEntities);
        _currWindow->clear();
        _displayEntities(gameEntities);
        _currWindow->display();
    }
}
