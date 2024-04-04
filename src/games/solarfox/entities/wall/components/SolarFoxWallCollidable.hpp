/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SolarFoxWallCollidable
*/

#pragma once

#include "abstracts/components/ACollidableComponent.hpp"

class SolarFoxWallCollidable : public ACollidableComponent {
    public:
        SolarFoxWallCollidable(shared::types::Vector2i position,
            shared::types::Vector2u size, entity::IEntity &entity);
        ~SolarFoxWallCollidable();

        void onCollide(std::shared_ptr<IGame> ctx,
            std::shared_ptr<ICollidableComponent> target) override;
};
