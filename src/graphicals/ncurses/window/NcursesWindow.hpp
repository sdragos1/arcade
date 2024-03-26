/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** NcursesWindow
*/

#pragma once

#include <iostream>
#include <ncurses.h>
#include "graphics/events/key/KeyPressEvent.hpp"
#include "graphics/window/IWindow.hpp"

using namespace shared::graphics;

class NcursesWindow : public shared::graphics::IWindow {
    public:
        explicit NcursesWindow(const WindowInitProps &props);
        ~NcursesWindow();

        void setTitle(const std::string &title) override;
        std::string getTitle() const override;
        void setSize(Vector2u size) override;
        Vector2u getSize() const override;
        void setFramerateLimit(unsigned int limit) override;
        unsigned int getFramerateLimit() const override;
        void setMode(WindowMode mode) override;
        WindowMode getMode() const override;
        void setIcon(const std::string &icon) override;
        const std::string &getIcon(void) const override;
        void render(const EntityProps &props) override;
        void clear() override;
        void display() override;
        void close() override;
        bool isOpen() const override;
        std::vector<events::Event> getEvents(void) override;

    private:
        void renderTitle() const;

        std::string _title;
        Vector2u _size;
        WindowMode _mode;
        std::string _icon;
        unsigned int _fps;
        bool _isOpen;
        WINDOW *_window;
        std::vector<events::Event> _events;
};
