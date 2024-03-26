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

shared::graphics::events::Event NcursesEvents::getNcursesEvent(int key)
{
    switch (key)
    {
        case KEY_UP:
            return KeyPressEvent(KeyType::ARROW, KeyCode{.arrow = ArrowCode::UP});
        case KEY_DOWN:
            return KeyPressEvent(KeyType::ARROW, KeyCode{.arrow = ArrowCode::DOWN});
        case KEY_LEFT:
            return KeyPressEvent(KeyType::ARROW, KeyCode{.arrow = ArrowCode::LEFT});
        case KEY_RIGHT:
            return KeyPressEvent(KeyType::ARROW, KeyCode{.arrow = ArrowCode::RIGHT});
        default:
            return KeyPressEvent(KeyType::ARROW, KeyCode{.arrow = ArrowCode::UP});
    }
}
