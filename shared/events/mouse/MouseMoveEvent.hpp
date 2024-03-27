/*
** EPITECH PROJECT, 2024
** arcade-shared
** File description:
** IMouseEvent
*/

#pragma once

#include "../../../common/graphics/events/IMouseEvent.hpp"

namespace shared::graphics::events
{
  class MouseMoveEvent;
}

class shared::graphics::events::MouseMoveEvent :
public shared::graphics::events::IMouseEvent
{
   public:
    explicit MouseMoveEvent(types::Vector2i position) : _pos(position) {}

    ~MouseMoveEvent() = default;

    EventType getType() const noexcept override
    {
        return shared::graphics::events::MOUSE_MOVE;
    }

    const shared::types::Vector2i getPosition(void) const noexcept override
    {
        return _pos;
    }

    private:
        shared::types::Vector2i _pos;
};
