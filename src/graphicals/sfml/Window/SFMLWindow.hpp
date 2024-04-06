/*
** EPITECH PROJECT, 2024
** SFMLWindow
** File description:
** Arcade
*/

#pragma once

#include <memory>
#include <string>
#include <iomanip>
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "../SFMLTexture.hpp"
#include "../SFMLFont.hpp"
#include "../exceptions/SFMLWindowException.hpp"
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

class SFMLWindow : public shared::graphics::IWindow
{
    public:

        /**
         * @brief Construct a new SFMLWindow object
         * @param windowProps
         */
        explicit SFMLWindow(const shared::graphics::IWindow::WindowInitProps &windowProps);

        /**
         * @brief Destroy the SFMLWindow object
         */
        ~SFMLWindow();

        /**
         * @brief Set the Window Title object
         * @param title
         */
        void setTitle(const std::string &title) override;

        /**
         * @brief Set the size of the window
         */
        void setSize(Vector2u size) override;

        /**
         * @brief Get the size of the window
         * @return Vector2u
         */
        Vector2u getSize() const override;

        /**
         * @brief Set the framerate limit
         * @param fps
         */
        void setFramerateLimit(unsigned int fps) override;

        /**
         * @brief Get the framerate limit
         * @return unsigned int
         */
        unsigned int getFramerateLimit() const override;

        /**
         * @brief Set the mode of the window
         * @param mode
         */
        void setMode(shared::graphics::IWindow::WindowMode mode) override;

        /**
         * @brief Get the mode of the window
         * @return shared::graphics::IWindow::WindowMode
         */
        shared::graphics::IWindow::WindowMode getMode(void) const override;

        /**
         * @brief Set the Window Icon object
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
         * @brief Get the events object
         * @return std::vector<std::shared_ptr<shared::graphics::events::IEvent>>
         */
        std::vector<std::shared_ptr<shared::graphics::events::IEvent>> getEvents(void) override;

        /**
         * @brief Map the key to keyTypes to make it match our key types
         * @param sfmlKey
         * @return shared::graphics::events::IKeyEvent::KeyType
         */
        shared::graphics::events::IKeyEvent::KeyType mapSFMLKeyToKeyType(sf::Keyboard::Key sfmlKey);

        /**
         * @brief Map the key to keyCodes to make it match our key codes
         * @param sfmlKey
         * @param type
         * @return shared::graphics::events::IKeyEvent::KeyCode
         */
        shared::graphics::events::IKeyEvent::KeyCode mapSFMLKeyToKeyCode
        (sf::Keyboard::Key sfmlKey, shared::graphics::events::IKeyEvent::KeyType type);

    private:
        sf::RenderWindow _window;
        std::string      _title;
        std::string      _icon;
        unsigned int     _fps;
        Vector2u         _sfmlbasicTiles;
        Vector2u         _sfmlbasicwindow;
        shared::graphics::IWindow::WindowMode _mode;
};
