/*
** EPITECH PROJECT, 2024
** SDL2Window
** File description:
** Arcade
*/

#pragma once

#include <memory>
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "../SDL2Font.hpp"
#include "../SDL2Texture.hpp"
#include "../exceptions/SDL2WindowException.hpp"
#include "../../../../common/types/Vector.hpp"
#include "../../../../common/types/Libraries.hpp"
#include "../../../../common/graphics/events/IEvent.hpp"
#include "../../../../common/graphics/IWindow.hpp"
#include "../../../../shared/events/WindowCloseEvent.hpp"
#include "../../../../shared/events/WindowResizeEvent.hpp"
#include "../../../../common/graphics/types/TextProps.hpp"
#include "../../../../common/graphics/types/TextureProps.hpp"
#include "../../../../shared/events/key/KeyPressedEvent.hpp"
#include "../../../../shared/events/key/KeyReleaseEvent.hpp"
#include "../../../../shared/events/mouse/MouseMoveEvent.hpp"
#include "../../../../shared/events/mouse/MouseButtonPressEvent.hpp"
#include "../../../../shared/events/mouse/MouseButtonPressEvent.hpp"
#include "../../../../shared/events/mouse/MouseButtonReleaseEvent.hpp"

class SDL2Window : public shared::graphics::IWindow
{
    public:
        explicit SDL2Window(const shared::graphics::IWindow::WindowInitProps &windowProps);

        ~SDL2Window();

        void setTitle(const std::string &title) override;

        void setSize(Vector2u size) override;

        Vector2u getSize() const override;

        void setFramerateLimit(unsigned int fps) override;

        unsigned int getFramerateLimit() const override;

        void setMode(shared::graphics::IWindow::WindowMode mode) override;

        shared::graphics::IWindow::WindowMode getMode(void) const override;

        void setIcon(const std::string &icon) override;

        void render(const shared::graphics::TextureProps &props) override;

        void render(const shared::graphics::TextProps &props) override;

        void clear(void) override;

        void display(void) override;

        void close(void) override;

        bool isOpen(void) const override;

        std::vector<std::shared_ptr<shared::graphics::events::IEvent>> getEvents(void) override;

        shared::graphics::events::IKeyEvent::KeyType mapSDL2KeyToKeyType(SDL_Keycode sdl2Key);

        shared::graphics::events::IKeyEvent::KeyCode mapSDL2KeyToKeyCode
        (SDL_Keycode sdl2Key, shared::graphics::events::IKeyEvent::KeyType type);

    private:
        Uint32           _frameStart;
        bool             _running;
        SDL_Window      *_window;
        SDL_Renderer    *_renderer;
        std::string      _title;
        std::string      _icon;
        unsigned int     _fps;
        shared::graphics::IWindow::WindowMode _mode;
};
