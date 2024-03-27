/*
** EPITECH PROJECT, 2024
** shared
** File description:
** KeyReleaseEvent
*/

#pragma once

#include "../../../common/graphics/events/IKeyEvent.hpp"

namespace shared::graphics::events {
  class KeyReleaseEvent;
}
class shared::graphics::events::KeyReleaseEvent:
public shared::graphics::events::IKeyEvent
{
    public:
        KeyReleaseEvent(KeyType keyType, KeyCode keyCode): _keyType(keyType), _keyCode(keyCode)  {}

        ~KeyReleaseEvent() = default;

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
            return shared::graphics::events::KEY_RELEASE;
        }

    private:
        KeyType _keyType;
        KeyCode _keyCode;
};
