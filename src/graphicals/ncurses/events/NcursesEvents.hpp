/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** NcursesEvents
*/

#pragma once

#include <ncurses.h>
#include "events/key/KeyPressedEvent.hpp"
#include "graphics/events/IEvent.hpp"

using namespace shared::graphics::events;

class NcursesEvents {
    public:
        NcursesEvents();
        ~NcursesEvents();

        static shared::graphics::events::EventPtr getNcursesEvent(int key);
};
