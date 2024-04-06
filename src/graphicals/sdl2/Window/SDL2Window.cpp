/*
** EPITECH PROJECT, 2024
** SDL2Window
** File description:
** Arcade
*/

#include "SDL2Window.hpp"

SDL2Window::SDL2Window(const shared::graphics::IWindow::WindowInitProps &windowProps) :
_sdl2basicTiles(40, 40), _sdl2basicwindow(windowProps.size.x * 40, windowProps.size.y * 40)
{
    _title = windowProps.title;
    _fps = windowProps.fps;
    _icon = windowProps.icon;
    _mode = windowProps.mode;
    _running = true;
    _frameStart = SDL_GetTicks();

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS) < 0) {
        throw SDL2WindowException("SDL2 Window", SDL_GetError());
    }

    if (TTF_Init() == -1) {
        throw SDL2WindowException("SDL2 Window", "Can't create SDL2 Window");
    }

    if (windowProps.mode == shared::graphics::IWindow::FULLSCREEN) {
        _window = SDL_CreateWindow(windowProps.title.c_str(), 0,
        0, windowProps.size.x * 40, windowProps.size.y * 40,
        SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN | SDL_WINDOW_RESIZABLE);
        if (_window == nullptr) {
            throw SDL2WindowException("SDL2 Window", SDL_GetError());
        }
    } else {
        _window = SDL_CreateWindow(windowProps.title.c_str(), 0,
        0, windowProps.size.x * 40, windowProps.size.y * 40,
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
        if (_window == nullptr) {
            throw SDL2WindowException("SDL2 Window", SDL_GetError());
        }
    }

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Surface* icon = IMG_Load(windowProps.icon.c_str());
    if (icon) {
        SDL_SetWindowIcon(_window, icon);
        SDL_FreeSurface(icon);
    }

    std::cout << "Constructor in SDL2Window" << std::endl;
}

SDL2Window::~SDL2Window()
{
    TTF_Quit();
    SDL_Quit();
    std::cout << "Destructor in SDL2Window" << std::endl;
}

void SDL2Window::setTitle(const std::string &title)
{
    SDL_SetWindowTitle(_window, title.c_str());
}

void SDL2Window::setSize(Vector2u size)
{
    SDL_SetWindowSize(_window, size.x, size.y);
}

Vector2u SDL2Window::getSize() const
{
    int windowWidth = 0;
    int windowHeight = 0;
    SDL_GetWindowSize(_window, &windowWidth, &windowHeight);

    return ((Vector2u) {static_cast<unsigned int>(windowWidth),
    static_cast<unsigned int>(windowHeight)});
}

void SDL2Window::setFramerateLimit(unsigned int fps)
{
    _fps = fps;
}

unsigned int SDL2Window::getFramerateLimit() const
{
    return _fps;
}

void SDL2Window::setMode(shared::graphics::IWindow::WindowMode mode)
{
    int windowWidth = 0;
    int windowHeight = 0;
    SDL_GetWindowSize(_window, &windowWidth, &windowHeight);
    SDL_DestroyWindow(_window);

    if (mode == shared::graphics::IWindow::FULLSCREEN) {
        _window = SDL_CreateWindow(_title.c_str(), 0,
        0, windowWidth, windowHeight,
        SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN | SDL_WINDOW_RESIZABLE);
    } else {
        _window = SDL_CreateWindow(_title.c_str(), 0,
        0, windowWidth, windowHeight,
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    }
}

shared::graphics::IWindow::WindowMode SDL2Window::getMode(void) const
{
    return _mode;
}

void SDL2Window::setIcon(const std::string &icon)
{
    SDL_Surface* SDL2icon = IMG_Load(icon.c_str());
    if (SDL2icon) {
        SDL_SetWindowIcon(_window, SDL2icon);
        SDL_FreeSurface(SDL2icon);
    }
}

void SDL2Window::render(const shared::graphics::TextureProps &props)
{
    auto sdl2Texture = std::dynamic_pointer_cast<SDL2Texture>(props.texture);

    if (sdl2Texture != nullptr) {
        sdl2Texture->setTexture(_renderer);

        int windowWidth = 0;
        int windowHeight = 0;
        SDL_GetWindowSize(_window, &windowWidth, &windowHeight);
        float coefX = static_cast<float>(windowWidth) / static_cast<float>(_sdl2basicwindow.x);
        float coefY = static_cast<float>(windowHeight) / static_cast<float>(_sdl2basicwindow.y);
        Vector2f sizeTiles(_sdl2basicTiles.x * coefX, _sdl2basicTiles.y * coefY);

        int x = (props.position.x * sizeTiles.x);
        int y = (props.position.y * sizeTiles.y);

        SDL_Rect srcRect = {
            static_cast<int>(props.origin.x) * static_cast<int>(props.binTileSize.x),
            static_cast<int>(props.origin.y) * static_cast<int>(props.binTileSize.y),
            static_cast<int>(props.size.x) * static_cast<int>(props.binTileSize.x),
            static_cast<int>(props.size.y) * static_cast<int>(props.binTileSize.y)
        };

        SDL_Rect destRect = {x, y,
            static_cast<int>(props.size.x) * static_cast<int>(_sdl2basicTiles.x),
            static_cast<int>(props.size.y) * static_cast<int>(_sdl2basicTiles.y)};
        if (SDL_RenderCopy(_renderer, sdl2Texture->getTexture(), &srcRect, &destRect) < 0) {
            std::cout << SDL_GetError() << std::endl;
        }
    }
}

void SDL2Window::render(const shared::graphics::TextProps &props)
{
    auto sdl2Font = std::dynamic_pointer_cast<SDL2Font>(props.font);
    SDL_Color textColor = {props.color.r, props.color.g, props.color.b, props.color.a};
    int vertical = 0;
    int horizontal = 0;
    int windowWidth = 0;
    int windowHeight = 0;
    int textWidth = 0;
    int textHeight = 0;

    sdl2Font->setFont(props.fontSize);
    sdl2Font->setSurface(props.content.c_str(), textColor);
    sdl2Font->setTexture(_renderer);

    textWidth = sdl2Font->getSurface()->w;
    textHeight = sdl2Font->getSurface()->h;
    SDL_GetWindowSize(_window, &windowWidth, &windowHeight);

    if (props.align == shared::graphics::TextAlign::LEFT) {
        horizontal = 0;
    } else if (props.align == shared::graphics::TextAlign::CENTER) {
        horizontal = (windowWidth / 2) - (textWidth / 2);
    } else {
        horizontal = (windowWidth) - (textWidth);
    }
    if (props.verticalAlign == shared::graphics::TextVerticalAlign::TOP) {
        vertical = 0;
    } else if (props.verticalAlign == shared::graphics::TextVerticalAlign::MIDDLE) {
        vertical = (windowHeight / 2) - (textHeight / 2);
    } else {
        vertical = (windowHeight) - (textHeight);
    }

    SDL_Rect dstRect = {
        horizontal + static_cast<int>(props.position.x * static_cast<float>(_sdl2basicTiles.x)),
        vertical + static_cast<int>(props.position.y * static_cast<float>(_sdl2basicTiles.y)),
        textWidth,
        textHeight
    };
    if (SDL_RenderCopy(_renderer, sdl2Font->getTexture(), nullptr, &dstRect) < 0) {
        std::cout << SDL_GetError() << std::endl;
    }
}

void SDL2Window::clear(void)
{
    if (SDL_RenderClear(_renderer) < 0) {
        std::cout << SDL_GetError() << std::endl;
    }
}

void SDL2Window::display(void)
{
    int frameTime = SDL_GetTicks() - _frameStart;
    if (frameTime < 1000 / _fps) {
        SDL_Delay((1000 / _fps) - frameTime);
    }
    SDL_RenderPresent(_renderer);
}

void SDL2Window::close(void)
{
    _running = false;
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
}

bool SDL2Window::isOpen(void) const
{
    return _running;
}

shared::graphics::events::IKeyEvent::KeyType SDL2Window::mapSDL2KeyToKeyType(SDL_Keycode sdl2Key)
{
    switch (sdl2Key) {
        case SDLK_LCTRL:
        case SDLK_RCTRL:
        case SDLK_LALT:
        case SDLK_RALT:
        case SDLK_LSHIFT:
        case SDLK_RSHIFT:
            return shared::graphics::events::IKeyEvent::CONTROL;

        case SDLK_UP:
        case SDLK_DOWN:
        case SDLK_LEFT:
        case SDLK_RIGHT:
            return shared::graphics::events::IKeyEvent::ARROW;

        default:
            if (SDLK_F1 <= sdl2Key && sdl2Key <= SDLK_F12)
                return shared::graphics::events::IKeyEvent::FUNC;
            else if (SDLK_a <= sdl2Key && sdl2Key <= SDLK_z)
                return shared::graphics::events::IKeyEvent::CHAR;
            else
                return shared::graphics::events::IKeyEvent::UNKNOWN;
    }
}

shared::graphics::events::IKeyEvent::KeyCode SDL2Window::mapSDL2KeyToKeyCode
(SDL_Keycode sdl2Key, shared::graphics::events::IKeyEvent::KeyType type)
{
    if (type == shared::graphics::events::IKeyEvent::CONTROL) {
        switch (sdl2Key) {
            case SDLK_LCTRL:
            case SDLK_RCTRL:
                return {.control = shared::graphics::events::IKeyEvent::ControlCode::CTRL};
            case SDLK_LALT:
            case SDLK_RALT:
                return {.control = shared::graphics::events::IKeyEvent::ControlCode::ALT};
            case SDLK_LSHIFT:
            case SDLK_RSHIFT:
                return {.control = shared::graphics::events::IKeyEvent::ControlCode::SHIFT};
        }
    }
    if (type == shared::graphics::events::IKeyEvent::ARROW) {
        switch (sdl2Key) {
            case SDLK_UP:
                return {.arrow = shared::graphics::events::IKeyEvent::ArrowCode::UP};
            case SDLK_DOWN:
                return {.arrow = shared::graphics::events::IKeyEvent::ArrowCode::DOWN};
            case SDLK_RIGHT:
                return {.arrow = shared::graphics::events::IKeyEvent::ArrowCode::RIGHT};
            case SDLK_LEFT:
                return {.arrow = shared::graphics::events::IKeyEvent::ArrowCode::LEFT};
        }
    }
    if (type == shared::graphics::events::IKeyEvent::CHAR) {
        return {.character = static_cast<char>(sdl2Key - SDLK_a + 'a')};
    }
    if (type == shared::graphics::events::IKeyEvent::FUNC) {
        return {.func = static_cast<unsigned char>((sdl2Key - SDLK_F1) + 1)};
    }
    return {.character = static_cast<char>(0)};
}

std::vector<std::shared_ptr<shared::graphics::events::IEvent>> SDL2Window::getEvents(void)
{
    _frameStart = SDL_GetTicks();
    std::vector<std::shared_ptr<shared::graphics::events::IEvent>> eventsList;

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        int windowWidth = 0;
        int windowHeight = 0;
        SDL_GetWindowSize(_window, &windowWidth, &windowHeight);
        float coefX = static_cast<float>(windowWidth) / static_cast<float>(_sdl2basicwindow.x);
        float coefY = static_cast<float>(windowHeight) / static_cast<float>(_sdl2basicwindow.y);
        Vector2f sizeTiles(_sdl2basicTiles.x * coefX, _sdl2basicTiles.y * coefY);
        shared::graphics::events::IKeyEvent::KeyType KeyFindType;
        SDL_Keycode keycode;

        switch (event.type)  {
            case SDL_QUIT:
                eventsList.push_back
                (std::make_shared<shared::graphics::events::WindowCloseEvent>());
                break;
            case SDL_WINDOWEVENT:
                if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
                    eventsList.push_back
                    (std::make_shared<shared::graphics::events::WindowResizeEvent>
                    ((Vector2u) {static_cast<unsigned int>(event.window.data1),
                    static_cast<unsigned int>(event.window.data2)}));
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_RIGHT) {
                    eventsList.push_back
                    (std::make_shared<shared::graphics::events::MouseButtonPressEvent>
                    (shared::graphics::events::IMouseButtonEvent::RIGHT,
                    (Vector2f) {(event.button.x / static_cast<float>(sizeTiles.x)),
                    (event.button.y / static_cast<float>(sizeTiles.y))}));
                } else if (event.button.button == SDL_BUTTON_LEFT) {
                    eventsList.push_back
                    (std::make_shared<shared::graphics::events::MouseButtonPressEvent>
                    (shared::graphics::events::IMouseButtonEvent::LEFT,
                    (Vector2f) {(event.button.x / static_cast<float>(sizeTiles.x)),
                    (event.button.y / static_cast<float>(sizeTiles.y))}));
                }
                break;
            case SDL_MOUSEBUTTONUP:
                if (event.button.button == SDL_BUTTON_RIGHT) {
                    eventsList.push_back
                    (std::make_shared<shared::graphics::events::MouseButtonReleaseEvent>
                    (shared::graphics::events::IMouseButtonEvent::RIGHT,
                    (Vector2f) {(event.button.x / static_cast<float>(sizeTiles.x)),
                    (event.button.y / static_cast<float>(sizeTiles.y))}));
                } else if (event.button.button == SDL_BUTTON_LEFT) {
                    eventsList.push_back
                    (std::make_shared<shared::graphics::events::MouseButtonReleaseEvent>
                    (shared::graphics::events::IMouseButtonEvent::LEFT,
                    (Vector2f) {(event.button.x / static_cast<float>(sizeTiles.x)),
                    (event.button.y / static_cast<float>(sizeTiles.y))}));
                }
                break;
            case SDL_MOUSEMOTION:
                eventsList.push_back(std::make_shared<shared::graphics::events::MouseMoveEvent>
                    ((Vector2f) {(event.motion.x / static_cast<float>(sizeTiles.x)),
                    (event.motion.y / static_cast<float>(sizeTiles.y))}));
                break;
            case SDL_KEYDOWN:
                keycode = event.key.keysym.sym;
                KeyFindType = mapSDL2KeyToKeyType(keycode);
                if (KeyFindType == shared::graphics::events::IKeyEvent::UNKNOWN)
                    break;
                eventsList.push_back(std::make_shared<shared::graphics::events::KeyPressedEvent>
                (KeyFindType, mapSDL2KeyToKeyCode(keycode, KeyFindType)));
                break;
            case SDL_KEYUP:
                keycode = event.key.keysym.sym;
                KeyFindType = mapSDL2KeyToKeyType(keycode);
                if (KeyFindType == shared::graphics::events::IKeyEvent::UNKNOWN)
                    break;
                eventsList.push_back(std::make_shared<shared::graphics::events::KeyReleaseEvent>
                (KeyFindType, mapSDL2KeyToKeyCode(keycode, KeyFindType)));
                break;
            default:
                break;
        }
    }
    return eventsList;
}

