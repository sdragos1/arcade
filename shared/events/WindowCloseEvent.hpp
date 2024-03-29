/*
** EPITECH PROJECT, 2024
** shared
** File description:
** IWindowCloseEvent
*/

#pragma once

#include "../../common/graphics/events/IEvent.hpp"

namespace shared::graphics::events {
  class WindowCloseEvent;
}

class shared::graphics::events::WindowCloseEvent: public IEvent {
  public:
    WindowCloseEvent() = default;
    ~WindowCloseEvent() = default;

    /**
     * @brief Event type
     *
     */
    EventType getType() const noexcept override
    {
      return WINDOW_CLOSE;
    }
};
