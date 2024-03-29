/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SnakeTailKeyboard
*/

#pragma once

#include "games/components/IKeyboardComponent.hpp"
#include "games/components/IDisplayableComponent.hpp"
#include "SnakeTailDisplayable.hpp"

using namespace shared::games;

class SnakeTailKeyboard : public components::IKeyboardComponent {
    public:
        explicit SnakeTailKeyboard(const entity::IEntity &entity);
        ~SnakeTailKeyboard();

        const shared::games::components::ComponentType getType() const noexcept override;
        const shared::games::entity::IEntity &getEntity() noexcept override;

        void onKeyPress(std::shared_ptr<IGame> &ctx, shared::games::components::IKeyboardComponent::KeyData key) override;
        void onKeyRelease(std::shared_ptr<IGame> &ctx, shared::games::components::IKeyboardComponent::KeyData key) override;

    private:
        const entity::IEntity &_entity;
};