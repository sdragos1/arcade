/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** ACollidableComponent
*/

#pragma once

#include "games/components/ICollidableComponent.hpp"
#include "PositionableComponent.hpp"

using namespace shared::games;

class ACollidableComponent : public virtual components::ICollidableComponent,
                             public PositionableComponent{
    public:
        ACollidableComponent(shared::types::Vector2f position,
            shared::types::Vector2u size, entity::IEntity &entity);
        ~ACollidableComponent();
};
