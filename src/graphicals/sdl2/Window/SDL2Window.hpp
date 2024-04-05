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
        /**
         * @brief Construct a new SDL2Window object
         * @param windowProps
         */
        explicit SDL2Window(const shared::graphics::IWindow::WindowInitProps &windowProps);

        /**
         * @brief Destroy the SDL2Window object
         */
        ~SDL2Window();

        /**
         * @brief Set the Title of the Window object
         * @param title
         */
        void setTitle(const std::string &title) override;

        /**
         * @brief Set the Size of the Window object
         * @param size
         */
        void setSize(Vector2u size) override;

        /**
         * @brief Get the Size of the Window object
         * @return Vector2u
         */
        Vector2u getSize() const override;

        /**
         * @brief Set the Framerate Limit of the Window object
         * @param fps
         */
        void setFramerateLimit(unsigned int fps) override;

        /**
         * @brief Get the Framerate Limit of the Window object
         * @return unsigned int
         */
        unsigned int getFramerateLimit() const override;

        /**
         * @brief Set the Mode of the Window object
         * @param mode
         */
        void setMode(shared::graphics::IWindow::WindowMode mode) override;

        /**
         * @brief Get the Mode of the Window object
         * @return shared::graphics::IWindow::WindowMode
         */
        shared::graphics::IWindow::WindowMode getMode(void) const override;

        /**
         * @brief Set the Icon of the Window object
         * @param icon
         */
        void setIcon(const std::string &icon) override;

        /**
         * @brief Render the texture props on the window
         * @param props
         */
        void render(const shared::graphics::TextureProps &props) override;

        /**
         * @brief Render the texts props on the window
         * @param props
         */
        void render(const shared::graphics::TextProps &props) override;

        /**
         * @brief Clear the window
         */
        void clear(void) override;

        /**
         * @brief Display the window
         */
        void display(void) override;

        /**
         * @brief Close the window
         */
        void close(void) override;

        /**
         * @brief Check if the window is open
         * @return bool
         */
        bool isOpen(void) const override;

        /**
         * @brief Get the Events object
         * @return std::vector<std::shared_ptr<shared::graphics::events::IEvent>>
         */
        std::vector<std::shared_ptr<shared::graphics::events::IEvent>> getEvents(void) override;

        /**
         * @brief Map the key to keyTypes to make it match our key types
         * @param sfmlKey
         * @return shared::graphics::events::IKeyEvent::KeyType
         */
        shared::graphics::events::IKeyEvent::KeyType mapSDL2KeyToKeyType(SDL_Keycode sdl2Key);

        /**
         * @brief Map the key to keyCodes to make it match our key codes
         * @param sfmlKey
         * @param type
         * @return shared::graphics::events::IKeyEvent::KeyCode
         */
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
        Vector2u         _sdl2basicTiles;
        Vector2u         _sdl2basicwindow;
        shared::graphics::IWindow::WindowMode _mode;
};
