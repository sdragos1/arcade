/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** NcursesEvents
*/

#include "NcursesEvents.hpp"

NcursesEvents::NcursesEvents()
{
}

NcursesEvents::~NcursesEvents()
{
}


events::IKeyEvent::KeyType NcursesEvents::mapNcursesKeyToKeyType(int key)
{
    switch (key)
    {
        case KEY_UP:
        case KEY_DOWN:
        case KEY_LEFT:
        case KEY_RIGHT:
            return events::IKeyEvent::ARROW;

        case KEY_F(1):
        case KEY_F(2):
        case KEY_F(3):
            return events::IKeyEvent::FUNC;

        case KEY_BACKSPACE:
        case KEY_DC:
        case KEY_ENTER:
        case KEY_HOME:
        case KEY_END:
        case KEY_IC:
        case KEY_NPAGE:
        case KEY_PPAGE:
        case KEY_RESIZE:
        case KEY_LL:
            return events::IKeyEvent::CONTROL;

        default:
            if (std::isalpha(key))
                return events::IKeyEvent::CHAR;
            else
                return events::IKeyEvent::UNKNOWN;
    }
}

events::IKeyEvent::KeyCode NcursesEvents::mapNcursesKeyToKeyCode(int key,
    events::IKeyEvent::KeyType type)
{
    if (type == events::IKeyEvent::CONTROL) {
        switch (key) {
            case KEY_BACKSPACE:
                return {.control = events::IKeyEvent::ControlCode::CTRL};
            case KEY_DC:
                return {.control = events::IKeyEvent::ControlCode::ALT};
            case KEY_ENTER:
                return {.control = events::IKeyEvent::ControlCode::SHIFT};
        }
    }
    if (type == events::IKeyEvent::ARROW) {
        switch (key) {
            case KEY_UP:
                return {.arrow = events::IKeyEvent::ArrowCode::UP};
            case KEY_DOWN:
                return {.arrow = events::IKeyEvent::ArrowCode::DOWN};
            case KEY_RIGHT:
                return {.arrow = events::IKeyEvent::ArrowCode::RIGHT};
            case KEY_LEFT:
                return {.arrow = events::IKeyEvent::ArrowCode::LEFT};
        }
    }
    if (type == events::IKeyEvent::CHAR) {
        return {.character = static_cast<char>(key)};
    }
    if (type == events::IKeyEvent::FUNC) {
        return {.func = static_cast<unsigned char>(key - KEY_F(1) + 1)};
    }
    return {.character = static_cast<char>(0)};
}
