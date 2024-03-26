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
#include "events/NcursesEvents.hpp"
#include "../../abstracts/window/AWindow.hpp"

using namespace shared::graphics;

class NcursesWindow : public AWindow {
    public:
        explicit NcursesWindow(const WindowInitProps &props);
        ~NcursesWindow();

        void render(const EntityProps &props) override;
        void clear() override;
        void display() override;
        void close() override;
        std::vector<events::Event> getEvents(void) override;

    private:
        void renderTitle() const;

        WINDOW *_window;
        std::vector<events::Event> _events;
};
