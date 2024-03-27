/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SnakeHeadKeyboard
*/

#pragma once

#include "games/components/IKeyboardComponent.hpp"
#include "games/components/IDisplayableComponent.hpp"
#include "SnakeHeadDisplayable.hpp"

using namespace shared::games;

class SnakeHeadKeyboard : public components::IKeyboardComponent {
    public:
        explicit SnakeHeadKeyboard(std::shared_ptr<SnakeHeadDisplayable> displayable);
        ~SnakeHeadKeyboard();

        // IComponent
        const components::ComponentType getType() const noexcept override;
        const entity::IEntity &getEntity() noexcept override;

        // Keyboard
        void onKeyPress(std::shared_ptr<IGame> &ctx, shared::graphics::events::IKeyEvent::KeyData key) override;
        void onKeyRelease(std::shared_ptr<IGame> &ctx, shared::graphics::events::IKeyEvent::KeyData key) override;
    private:
        std::shared_ptr<SnakeHeadDisplayable> _displayable;
};
