/*
** EPITECH PROJECT, 2024
** SFMLWindow
** File description:
** Arcade
*/

#include "SFMLWindow.hpp"

SFMLWindow::SFMLWindow(const shared::graphics::IWindow::WindowInitProps &windowProps) :
_sfmlbasicTiles(40, 40), _sfmlbasicwindow(windowProps.size.x * 40, windowProps.size.y * 40)
{
    _title = windowProps.title;
    _fps = windowProps.fps;
    _icon = windowProps.icon;
    _mode = windowProps.mode;

    if (windowProps.mode == shared::graphics::IWindow::FULLSCREEN) {
        _window.create(sf::VideoMode(windowProps.size.x * 40, windowProps.size.y * 40),
        windowProps.title, sf::Style::Fullscreen);
    } else {
        _window.create(sf::VideoMode(windowProps.size.x * 40, windowProps.size.y * 40),
        windowProps.title, sf::Style::Default);
    }
    _window.setFramerateLimit(windowProps.fps);


    sf::Image icon;
    if (icon.loadFromFile(windowProps.icon))
        _window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    std::cout << "Constructor in SFMLWindow" << std::endl;
}

SFMLWindow::~SFMLWindow()
{
    if (_window.isOpen())
        _window.close();
    std::cout << "Destructor in SFMLWindow" << std::endl;
}

void SFMLWindow::setTitle(const std::string &title)
{
    _window.setTitle(title);
    _title = title;
}

void SFMLWindow::setSize(Vector2u size)
{
    _window.setSize((sf::Vector2u) {size.x, size.y});
}

Vector2u SFMLWindow::getSize() const
{
    Vector2u windowSize(_window.getSize().x, _window.getSize().y);
    return windowSize;
}

void SFMLWindow::setFramerateLimit(unsigned int fps)
{
    _window.setFramerateLimit(fps);
    _fps = fps;
}

unsigned int SFMLWindow::getFramerateLimit() const
{
    return _fps;
}

void SFMLWindow::setMode(shared::graphics::IWindow::WindowMode mode)
{
    _window.close();

    if (mode == shared::graphics::IWindow::WINDOWED) {
        _window.create(sf::VideoMode(_window.getSize().x, _window.getSize().y),
        _title, sf::Style::Default);
    } else if (mode == shared::graphics::IWindow::FULLSCREEN) {
        _window.create(sf::VideoMode(_window.getSize().x, _window.getSize().y),
        _title, sf::Style::Fullscreen);
    }
    _window.setFramerateLimit(_fps);
    sf::Image icon;
    if (icon.loadFromFile(_icon))
        _window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    _mode = mode;
}

shared::graphics::IWindow::WindowMode SFMLWindow::getMode(void) const
{
    return _mode;
}

void SFMLWindow::setIcon(const std::string &icon)
{
    sf::Image iconImage;
    if (iconImage.loadFromFile(icon))
        _window.setIcon(iconImage.getSize().x, iconImage.getSize().y,
        iconImage.getPixelsPtr());
    _icon = icon;
}

void SFMLWindow::render(const shared::graphics::TextureProps &props)
{
    auto sfmlTexture = std::dynamic_pointer_cast<SFMLTexture>(props.texture);

    if (sfmlTexture != nullptr) {
        sf::Texture entityTexture = sfmlTexture->getTexture();
        sf::Sprite sprite(entityTexture);

        sf::IntRect rect
         (props.origin.x * props.binTileSize.x, props.origin.y * props.binTileSize.y,
         props.size.x * props.binTileSize.x, props.size.y * props.b inTileSize.y);
        sprite.setTextureRect(rect);

        sprite.setOrigin(0, 0);

        sprite.setPosition(
        props.position.x * _sfmlbasicTiles.x,
        props.position.y * _sfmlbasicTiles.y);

        _window.draw(sprite);
    }
}

void SFMLWindow::render(const shared::graphics::TextProps &props)
{
    auto sfmlFont = std::dynamic_pointer_cast<SFMLFont>(props.font);
    float vertical = 0.0;
    float horizontal = 0.0;

    if (sfmlFont != nullptr) {
        sf::Text text;
        sf::Font font;
        font.loadFromFile(sfmlFont->getPath());

        text.setFont(font);
        text.setString(props.content);
        text.setCharacterSize(props.fontSize);

        sf::Color colorFont(props.color.r, props.color.g, props.color.b, props.color.a);
        text.setFillColor(colorFont);

        if (props.align == shared::graphics::TextAlign::LEFT) {
            horizontal = 0;
        } else if (props.align == shared::graphics::TextAlign::CENTER) {
            horizontal = (_sfmlbasicwindow.x / 2) - (text.getLocalBounds().width / 2);
        } else {
            horizontal = (_sfmlbasicwindow.x) - (text.getLocalBounds().width);
        }
        if (props.verticalAlign == shared::graphics::TextVerticalAlign::TOP) {
            vertical = 0;
        } else if (props.verticalAlign == shared::graphics::TextVerticalAlign::MIDDLE) {
            vertical = (_sfmlbasicwindow.y / 2) - (text.getLocalBounds().height / 2);
        } else {
            vertical = (_sfmlbasicwindow.y) - (text.getLocalBounds().height);
        }

        float posX = static_cast<float>(props.position.x);
        float posY = static_cast<float>(props.position.y);

        text.setPosition((sf::Vector2f) {horizontal + (props.position.x * _sfmlbasicTiles.x),
        vertical + (props.position.y * _sfmlbasicTiles.y)});
        _window.draw(text);
    }
}

void SFMLWindow::clear(void)
{
    _window.clear();
}

void SFMLWindow::display(void)
{
    _window.display();
}

void SFMLWindow::close(void)
{
    _window.close();
}

bool SFMLWindow::isOpen(void) const
{
    return _window.isOpen();
}

shared::graphics::events::IKeyEvent::KeyType SFMLWindow::mapSFMLKeyToKeyType
(sf::Keyboard::Key sfmlKey)
{
    switch (sfmlKey) {
        case sf::Keyboard::Key::LControl:
        case sf::Keyboard::Key::RControl:
        case sf::Keyboard::Key::LAlt:
        case sf::Keyboard::Key::RAlt:
        case sf::Keyboard::Key::LShift:
        case sf::Keyboard::Key::RShift:
            return shared::graphics::events::IKeyEvent::CONTROL;

        case sf::Keyboard::Key::Up:
        case sf::Keyboard::Key::Down:
        case sf::Keyboard::Key::Left:
        case sf::Keyboard::Key::Right:
            return shared::graphics::events::IKeyEvent::ARROW;

        default:
            if (sf::Keyboard::Key::F1 <= sfmlKey && sfmlKey <= sf::Keyboard::Key::F15)
                return shared::graphics::events::IKeyEvent::FUNC;
            else if (sf::Keyboard::Key::A <= sfmlKey && sfmlKey <= sf::Keyboard::Key::Z)
                return shared::graphics::events::IKeyEvent::CHAR;
            else
                return shared::graphics::events::IKeyEvent::UNKNOWN;
    }
}

shared::graphics::events::IKeyEvent::KeyCode SFMLWindow::mapSFMLKeyToKeyCode
(sf::Keyboard::Key sfmlKey, shared::graphics::events::IKeyEvent::KeyType type)
{
    if (type == shared::graphics::events::IKeyEvent::CONTROL) {
        switch (sfmlKey) {
            case sf::Keyboard::Key::LControl:
            case sf::Keyboard::Key::RControl:
                return {.control = shared::graphics::events::IKeyEvent::ControlCode::CTRL};
            case sf::Keyboard::Key::LAlt:
            case sf::Keyboard::Key::RAlt:
                return {.control = shared::graphics::events::IKeyEvent::ControlCode::ALT};
            case sf::Keyboard::Key::LShift:
            case sf::Keyboard::Key::RShift:
                return {.control = shared::graphics::events::IKeyEvent::ControlCode::SHIFT};
        }
    }
    if (type == shared::graphics::events::IKeyEvent::ARROW) {
        switch (sfmlKey) {
            case sf::Keyboard::Key::Up:
                return {.arrow = shared::graphics::events::IKeyEvent::ArrowCode::UP};
            case sf::Keyboard::Key::Down:
                return {.arrow = shared::graphics::events::IKeyEvent::ArrowCode::DOWN};
            case sf::Keyboard::Key::Right:
                return {.arrow = shared::graphics::events::IKeyEvent::ArrowCode::RIGHT};
            case sf::Keyboard::Key::Left:
                return {.arrow = shared::graphics::events::IKeyEvent::ArrowCode::LEFT};
        }
    }
    if (type == shared::graphics::events::IKeyEvent::CHAR) {
            return {.character = static_cast<char>(sfmlKey - sf::Keyboard::Key::A + 'a')};
    }
    if (type == shared::graphics::events::IKeyEvent::FUNC) {
        return {.func = static_cast<unsigned char>((sfmlKey - sf::Keyboard::Key::F1) + 1)};
    }
    return {.character = static_cast<char>(0)};
}

std::vector<shared::graphics::events::EventPtr> SFMLWindow::getEvents(void)
{
    std::vector<shared::graphics::events::EventPtr> eventsList;

    sf::Event event;
    while (_window.pollEvent(event)) {
        float coefX = static_cast<float>(_window.getSize().x) /
        static_cast<float>(_sfmlbasicwindow.x);
        float coefY = static_cast<float>(_window.getSize().y) /
        static_cast<float>(_sfmlbasicwindow.y);

        Vector2f sizeTiles(_sfmlbasicTiles.x * coefX, _sfmlbasicTiles.y * coefY);

        shared::graphics::events::IKeyEvent::KeyType KeyFindType;

        switch (event.type) {
            case sf::Event::Closed:
                eventsList.push_back
                (std::make_shared<shared::graphics::events::WindowCloseEvent>());
                break;
            case sf::Event::Resized:
                eventsList.push_back
                (std::make_shared<shared::graphics::events::WindowResizeEvent>
                ((Vector2u) {event.size.width, event.size.height}));
                break;
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Right) {
                    eventsList.push_back
                    (std::make_shared<shared::graphics::events::MouseButtonPressEvent>
                    (shared::graphics::events::IMouseButtonEvent::RIGHT,
                    (Vector2f) {(event.mouseButton.x / static_cast<float>(sizeTiles.x)),
                    (event.mouseButton.y / static_cast<float>(sizeTiles.y))}));
                } else if (event.mouseButton.button == sf::Mouse::Left) {
                    eventsList.push_back
                    (std::make_shared<shared::graphics::events::MouseButtonPressEvent>
                    (shared::graphics::events::IMouseButtonEvent::RIGHT,
                    (Vector2f) {(event.mouseButton.x / static_cast<float>(sizeTiles.x)),
                    (event.mouseButton.y / static_cast<float>(sizeTiles.y))}));
                }
                break;
            case sf::Event::MouseButtonReleased:
                if (event.mouseButton.button == sf::Mouse::Right) {
                    eventsList.push_back
                    (std::make_shared<shared::graphics::events::MouseButtonReleaseEvent>
                    (shared::graphics::events::IMouseButtonEvent::LEFT,
                    (Vector2f) {(event.mouseButton.x / static_cast<float>(sizeTiles.x)),
                    (event.mouseButton.y / static_cast<float>(sizeTiles.y))}));
                } else if (event.mouseButton.button == sf::Mouse::Left) {
                    eventsList.push_back
                    (std::make_shared<shared::graphics::events::MouseButtonReleaseEvent>
                    (shared::graphics::events::IMouseButtonEvent::RIGHT,
                    (Vector2f) {(event.mouseButton.x / static_cast<float>(sizeTiles.x)),
                    (event.mouseButton.y / static_cast<float>(sizeTiles.y))}));
                }
                break;
            case sf::Event::MouseMoved:
                eventsList.push_back(std::make_shared<shared::graphics::events::MouseMoveEvent>
                    ((Vector2f) {(event.mouseButton.x / static_cast<float>(sizeTiles.x)),
                    (event.mouseButton.y / static_cast<float>(sizeTiles.y))}));
                break;
            case sf::Event::KeyPressed:
                KeyFindType = mapSFMLKeyToKeyType(event.key.code);
                if (KeyFindType == shared::graphics::events::IKeyEvent::UNKNOWN)
                    break;
                eventsList.push_back(std::make_shared<shared::graphics::events::KeyPressedEvent>
                (KeyFindType, mapSFMLKeyToKeyCode(event.key.code, KeyFindType)));
                break;
            case sf::Event::KeyReleased:
                KeyFindType = mapSFMLKeyToKeyType(event.key.code);
                if (KeyFindType == shared::graphics::events::IKeyEvent::UNKNOWN)
                    break;
                eventsList.push_back(std::make_shared<shared::graphics::events::KeyReleaseEvent>
                (KeyFindType, mapSFMLKeyToKeyCode(event.key.code, KeyFindType)));
                break;
            default:
                break;
        }
    }
    return eventsList;
}