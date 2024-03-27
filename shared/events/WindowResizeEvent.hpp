/*
** EPITECH PROJECT, 2024
** shared
** File description:
** IWindowResizeEvent
*/

#pragma once

#include "../../common/types/Vector.hpp"
#include "../../common/graphics/events/IEvent.hpp"

namespace shared::graphics::events {
  class WindowResizeEvent;
}

class shared::graphics::events::WindowResizeEvent: public IEvent {
  public:
    explicit WindowResizeEvent(types::Vector2u newSize) : _newSize(newSize) {}
    ~WindowResizeEvent() = default;

    /**
     * @brief Event type
     *
     */
    EventType getType() const noexcept override
    {
      return WINDOW_RESIZE;
    }

    /**
     * @brief Get the new window size
     *
     * @return New window size
     */
    const shared::types::Vector2u &getNewSize() const noexcept
    {
      return this->_newSize;
    }

    protected:
        shared::types::Vector2u _newSize;
};
