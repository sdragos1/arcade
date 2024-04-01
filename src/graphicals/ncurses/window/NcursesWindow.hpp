/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** NcursesWindow
*/

#pragma once

#include <memory>
#include <iostream>
#include <ncurses.h>
#include "../NcursesFont.hpp"
#include "../NcursesTexture.hpp"
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

#define NCURSES_ORIGIN_OFFSET_Y 2
#define NCURSES_ORIGIN_OFFSET_X 1

using namespace shared::graphics;

class NcursesWindow : public shared::graphics::IWindow
{
    public:
        explicit NcursesWindow(const WindowInitProps &props);

        ~NcursesWindow();

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

        static events::IKeyEvent::KeyType mapNcursesKeyToKeyType(int key);

        static events::IKeyEvent::KeyCode mapNcursesKeyToKeyCode(int key,
        events::IKeyEvent::KeyType type);

    private:
        WINDOW                               *_window;
        int                                   _fps;
        shared::graphics::IWindow::WindowMode _mode;
        Vector2u                              _ncursesbasicwindow;
        bool                                  _running;
        std::string                           _title;

        void renderTitle() const;
};
