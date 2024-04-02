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
        enum Direction {
            UP,
            DOWN,
            LEFT,
            RIGHT
        };
        explicit SnakeHeadKeyboard(const entity::IEntity &entity);
        ~SnakeHeadKeyboard();

        const components::ComponentType getType() const noexcept override;
        const entity::IEntity &getEntity() noexcept override;

        void onKeyPress(std::shared_ptr<IGame> &ctx, KeyData keyData) override;
        void onKeyRelease(std::shared_ptr<IGame> &ctx, KeyData key) override;

        Direction _direction;
    private:
        const entity::IEntity &_entity;
};