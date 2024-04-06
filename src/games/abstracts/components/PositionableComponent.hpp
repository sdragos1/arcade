/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** PositionableComponent
*/

#pragma once

#include "types/Vector.hpp"
#include "games/components/IPositionableComponent.hpp"
#include "abstracts/components/AComponent.hpp"

using namespace shared::games;

class PositionableComponent : public virtual components::IPositionableComponent,
                              public AComponent {
    public:
        PositionableComponent(shared::types::Vector2f position,
            shared::types::Vector2u size, entity::IEntity &entity,
            components::ComponentType type);
        ~PositionableComponent();

        shared::types::Vector2f &getPosition() noexcept override;
        shared::types::Vector2u &getSize() noexcept override;

    protected:
        shared::types::Vector2f _position;
        shared::types::Vector2u _size;
};

