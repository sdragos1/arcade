/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SolarFoxWallCollidable
*/

#include "SolarFoxWallCollidable.hpp"

SolarFoxWallCollidable::SolarFoxWallCollidable(shared::types::Vector2i position,
            shared::types::Vector2u size, entity::IEntity &entity)
            : ACollidableComponent(position, size, entity)
{
}

SolarFoxWallCollidable::~SolarFoxWallCollidable()
{
}

void SolarFoxWallCollidable::onCollide(std::shared_ptr<IGame> ctx,
    std::shared_ptr<ICollidableComponent> target)
{
    (void)ctx;
    (void)target;
}
