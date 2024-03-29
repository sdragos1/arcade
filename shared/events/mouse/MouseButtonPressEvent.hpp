/*
** EPITECH PROJECT, 2024
** shared
** File description:
** IMouseEvent
*/

#pragma once

#include "../../../common/graphics/events/IMouseButtonEvent.hpp"

namespace shared::graphics::events
{
  class MouseButtonPressEvent;
}

class shared::graphics::events::MouseButtonPressEvent :
  public shared::graphics::events::IMouseButtonEvent
{
    public:
        MouseButtonPressEvent(MouseButton button, types::Vector2i position)
        : _button(button), _pos(position) {}
        ~MouseButtonPressEvent() = default;

        const MouseButton getButton(void) const noexcept override
        {
            return _button;
        }

        const shared::types::Vector2i getPosition(void) const noexcept override
        {
            return _pos;
        }

        EventType getType() const noexcept
        {
            return shared::graphics::events::EventType::MOUSE_BTN_PRESS;
        }

    private:
        MouseButton             _button;
        shared::types::Vector2i _pos;
};
