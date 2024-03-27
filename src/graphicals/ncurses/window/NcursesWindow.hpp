/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** NcursesWindow
*/

#pragma once

#include <iostream>
#include <ncurses.h>
#include <memory>
#include "events/key/KeyPressedEvent.hpp"
#include "events/NcursesEvents.hpp"
#include "../../abstracts/window/AWindow.hpp"
#include "../ressources/texture/NcursesTexture.hpp"

using namespace shared::graphics;

class NcursesWindow : public AWindow {
    public:
        explicit NcursesWindow(const WindowInitProps &props);
        ~NcursesWindow();

        void render(const TextureProps &props) override;
        void render(const TextProps &props) override;
        void clear() override;
        void display() override;
        void close() override;
        std::vector<events::EventPtr> getEvents(void) override;

    private:
        void renderTitle() const;

        WINDOW *_window;
        std::vector<events::EventPtr> _events;
};
