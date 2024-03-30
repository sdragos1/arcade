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
        IWindow::WindowMode::WINDOWED, 60, "Ncurses Lib", ICON_PATH});
}

void Core::_displayEntityText(std::shared_ptr<components::ITextComponent> displayable)
{
    components::ITextComponent::TextProps textProps = displayable->getTextProps();
    std::shared_ptr<IFont> font = _currRenderer->createFont(textProps.font.path);
    TextProps text{
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
    TextureProps entityProps{
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
    std::vector<TextureProps> entitiesProps;
    std::shared_ptr<ITexture> texture;
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
std::shared_ptr<events::KeyPressedEvent> keyEvent)
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
        _currRenderer = _librariesRenderer->getCurrentLibrary();
        _initGraphicLib();
    }
}

int Core::_coreEvents(std::shared_ptr<events::KeyPressedEvent> keyEvent)
{
    switch (keyEvent->getKeyCode().character)
    {
        case 'a':
            _currWindow->close();
            return 0;
        case 'd':
            _librariesRenderer->incrementIndex();
            return 0;
        case 'q':
            _librariesRenderer->decrementIndex();
            return 0;
        default:
            return 1;
    }
}

void Core::_handleEvents(entity::EntitiesMap entities)
{
    std::vector<events::EventPtr> events = _currWindow->getEvents();

    if (events.size() == 0) {
        return;
    }
    for (auto &event : events) {
        if (event->getType() == events::EventType::WINDOW_CLOSE) {
            _currWindow->close();
            return;
        }
        if (event->getType() == events::EventType::KEY_PRESS) {
            auto keyEvent = std::dynamic_pointer_cast<events::KeyPressedEvent>(event);
            if (_coreEvents(keyEvent) == 0) {
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
