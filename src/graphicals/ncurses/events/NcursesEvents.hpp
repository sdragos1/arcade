/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** NcursesEvents
*/

#pragma once

#include <cctype>
#include <ncurses.h>
#include "events/key/KeyPressedEvent.hpp"
#include "graphics/events/IEvent.hpp"

using namespace shared::graphics;

class NcursesEvents {
    public:
        NcursesEvents();
        ~NcursesEvents();

        static events::IKeyEvent::KeyType mapNcursesKeyToKeyType(int key);

        static events::IKeyEvent::KeyCode mapNcursesKeyToKeyCode(int key,
            events::IKeyEvent::KeyType type);
};
