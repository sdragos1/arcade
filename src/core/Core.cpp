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
    _currRenderer(nullptr), _currWindow(nullptr), _currLibIndex(0), _gameEntities()
{
    try {
        std::vector<std::string>  librariesPath;
        const std::string libPath = "./lib/";
        UniqueDirectory libDirectory = std::make_unique<Directory>(libPath);
        librariesPath = libDirectory->getListLibraries();
        _librariesGame =  std::make_unique<GameList>(librariesPath);
        _librariesRenderer = std::make_unique<GraphicList>(librariesPath, defaultLib);
        _currLibIndex = _librariesRenderer->getIndex();
        _launchGame = false;
        _playerName = "";
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
    _currWindow = _currRenderer->createWindow({
        .size = _currGame->getSize(),
        .mode = IWindow::WindowMode::WINDOWED,
        .fps = _currGame->getFps(),
        .title = _currGame->getManifest().name,
        .icon = _currGame->getManifest().iconPath});
}

void Core::_handleGraphicSwitch()
{
    if (_currLibIndex != _librariesRenderer->getIndex()) {
        _currLibIndex = _librariesRenderer->getIndex();
        _currRenderer = _librariesRenderer->getCurrentLibrary();
        _currWindow->close();
        _currWindow.release();
        _initGraphicLib();
    }
}

void Core::_handleCollisions(std::shared_ptr<components::ICollidableComponent> collidable,
entity::EntityPtr collidableEntity)
{
    for (auto &entity : _gameEntities) {
        if (collidableEntity == entity) {
            continue;
        }
        for (auto &component : entity->getComponents()) {
            if (component->getType() == components::COLLIDABLE) {
                auto collidableComp =
                    std::dynamic_pointer_cast<components::ICollidableComponent>(component);
                if (CoreUtils::checkCollision(collidable, collidableComp)) {
                    collidable->onCollide(_currGame, collidableComp);
                }
            }
        }
    }
}

void Core::_displayText(std::shared_ptr<components::ITextComponent> displayable)
{
    components::ITextComponent::TextProps textProps = displayable->getTextProps();
    std::shared_ptr<IFont> font = _currRenderer->createFont(textProps.font.path);
    TextProps text {
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

void Core::_displayTexture(std::shared_ptr<components::ITextureComponent> displayable)
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

void Core::_displayManager()
{
    components::ComponentsMap components;
    components::ComponentType type;

    for (auto &entity : _gameEntities) {
        components = entity->getComponents();
        for (auto &component : components) {
            type = component->getType();
            if (type == components::ComponentType::TEXTURE) {
                _displayTexture(
                    std::dynamic_pointer_cast<components::ITextureComponent>(component));
            }
            if (type == components::ComponentType::TEXT) {
                _displayText(
                    std::dynamic_pointer_cast<components::ITextComponent>(component));
            }
        }
    }
}

void Core::_handleMouseMoveEvent(
    std::shared_ptr<components::IDisplayableComponent> displayable,
    std::shared_ptr<events::MouseMoveEvent> mouseEvent)
{
    if (CoreUtils::isDisplayablePressed(displayable, mouseEvent)) {
        displayable->onMouseHover(_currGame);
    }
}

void Core::_handleMouseButtonReleasedEvent(
    std::shared_ptr<components::IDisplayableComponent> displayable,
    std::shared_ptr<events::MouseButtonReleaseEvent> mouseEvent)
{
    if (CoreUtils::isDisplayablePressed(displayable, mouseEvent)) {
        displayable->onMouseRelease(_currGame);
    }
}

void Core::_handleMouseButtonPressedEvent(
    std::shared_ptr<components::IDisplayableComponent> displayable,
    std::shared_ptr<events::MouseButtonPressEvent> mouseEvent)
{
    if (CoreUtils::isDisplayablePressed(displayable, mouseEvent)) {
        displayable->onMousePress(_currGame);
    }
}

void Core::_handleKeyPressEvent(std::shared_ptr<components::IKeyboardComponent> &keyboard,
std::shared_ptr<events::KeyPressedEvent> keyEvent)
{
    components::IKeyboardComponent::KeyData keyData;

    keyData = CoreUtils::convertKey(keyEvent->getKeyCode(), keyEvent->getKeyType());
    keyboard->onKeyPress(_currGame, keyData);
}

void Core::_handleKeyReleaseEvent(std::shared_ptr<components::IKeyboardComponent> &keyboard,
std::shared_ptr<events::KeyReleaseEvent> keyEvent)
{
    components::IKeyboardComponent::KeyData keyData;

    keyData = CoreUtils::convertKey(keyEvent->getKeyCode(), keyEvent->getKeyType());
    keyboard->onKeyRelease(_currGame, keyData);
}

void Core::_handleEntityEvents(entity::EntityPtr &entity, events::EventPtr event)
{
    components::ComponentType type;
    components::ComponentsMap components = entity->getComponents();

    for (auto &component : components) {
        type = component->getType();
        if (type == components::ComponentType::KEYBOARD) {
            auto keyboard = std::dynamic_pointer_cast<components::IKeyboardComponent>(component);
            if (event->getType() == events::EventType::KEY_PRESS) {
                _handleKeyPressEvent(
                    keyboard,
                    std::dynamic_pointer_cast<events::KeyPressedEvent>(event));
            }
            if (event->getType() == events::EventType::KEY_RELEASE) {
                _handleKeyReleaseEvent(
                    keyboard,
                    std::dynamic_pointer_cast<events::KeyReleaseEvent>(event));
            }
        }
        if (type == components::ComponentType::TEXTURE) {
            auto displayable =
                std::dynamic_pointer_cast<components::IDisplayableComponent>(component);
            if (event->getType() == events::EventType::MOUSE_BTN_PRESS) {
                _handleMouseButtonPressedEvent(
                    displayable,
                    std::dynamic_pointer_cast<events::MouseButtonPressEvent>(event));
            }
            if (event->getType() == events::EventType::MOUSE_BTN_RELEASE) {
                _handleMouseButtonReleasedEvent(
                    displayable,
                    std::dynamic_pointer_cast<events::MouseButtonReleaseEvent>(event));
            }
            if (event->getType() == events::EventType::MOUSE_MOVE) {
                _handleMouseMoveEvent(
                    displayable,
                    std::dynamic_pointer_cast<events::MouseMoveEvent>(event));
            }
        }
    }
}

std::size_t Core::_handleEvents()
{
    std::vector<events::EventPtr> events = _currWindow->getEvents();

    if (events.size() == 0) {
        return 0;
    }
    for (auto &event : events) {
        if (event->getType() == events::EventType::WINDOW_CLOSE) {
            _currWindow->close();
            return QUIT_ARCADE;
        }
        if (event->getType() == events::EventType::KEY_PRESS) {
            auto keyEvent = std::dynamic_pointer_cast<events::KeyPressedEvent>(event);
            std::size_t result = _handleGeneralEvents(keyEvent);
            if (result == 0) {
                return 0;
            } else if (result == BACK_MENU) {
                return BACK_MENU;
            } else if (result == QUIT_ARCADE) {
                return QUIT_ARCADE;
            }
        }
        for (auto &entity : _gameEntities) {
            _handleEntityEvents(entity, event);
        }
    }
    events.clear();
    return 0;
}

int Core::_handleGeneralEvents(std::shared_ptr<events::KeyPressedEvent> keyEvent)
{
    switch (keyEvent->getKeyCode().character)
    {
        case 'a':
            _currWindow->close();
            return QUIT_ARCADE;
        case 'd':
            _librariesRenderer->incrementIndex();
            return 0;
        case 'q':
            _librariesRenderer->decrementIndex();
            return 0;
        case 'e':
            _currWindow->close();
            _currWindow.release();
            return BACK_MENU;
        default:
            return 3;
    }
}

void Core::_collisionsManager()
{
    for (auto &entity : _gameEntities) {
        for (auto &component : entity->getComponents()) {
            if (component->getType() == components::COLLIDABLE) {
                auto collidable = std::dynamic_pointer_cast<components::ICollidableComponent>(component);
                _handleCollisions(collidable, entity);
            }
        }
    }
}

std::size_t Core::runArcade()
{
    auto prevTime = std::chrono::high_resolution_clock::now();
    std::size_t resultEvent = 0;

    _currGame = _librariesGame->getCurrentGame();
    _initGraphicLib();
    while (_currWindow->isOpen()) {
        _handleGraphicSwitch();
        auto currentTime = std::chrono::high_resolution_clock::now();
        auto deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(prevTime -
            currentTime);
        _currGame->compute(deltaTime);
        prevTime = currentTime;
        _gameEntities = _currGame->getEntities();
        resultEvent = _handleEvents();
        _collisionsManager();
        if (resultEvent == BACK_MENU)
            return BACK_MENU;
        if (resultEvent == QUIT_ARCADE)
            return QUIT_ARCADE;
        _currWindow->clear();
        _displayManager();
        _currWindow->display();
        _highscoreHandlers();
    }
    return 0;
}

bool Core::getLaunchArcade() const
{
    return _launchGame;
}
