/*
** EPITECH PROJECT, 2024
** shared
** File description:
** KeyPressedEvent
*/

#pragma once

#include "../../../common/graphics/events/IKeyEvent.hpp"

namespace shared::graphics::events {
  class KeyPressedEvent;
}
class shared::graphics::events::KeyPressedEvent:
public shared::graphics::events::IKeyEvent
{
    public:
        KeyPressedEvent(KeyType keyType, KeyCode keyCode): _keyType(keyType), _keyCode(keyCode)  {}

        ~KeyPressedEvent() = default;

        const KeyCode getKeyCode(void) const noexcept override
        {
            return _keyCode;
        }

        const KeyType getKeyType(void) const noexcept override
        {
            return _keyType;
        }

        EventType getType() const noexcept override
        {
            return shared::graphics::events::KEY_PRESS;
        }

    private:
        KeyType _keyType;
        KeyCode _keyCode;
};
