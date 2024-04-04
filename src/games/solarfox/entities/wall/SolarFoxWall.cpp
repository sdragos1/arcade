/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SolarFoxWall
*/

#include "SolarFoxWall.hpp"

SolarFoxWall::SolarFoxWall(shared::types::Vector2i position, shared::types::Vector2u size,
    std::vector<solarfox::CollisionLayer> collisionLayers)
    : _collisionLayers(collisionLayers)
{
    std::shared_ptr<components::IComponent> collidable =
        std::make_shared<SolarFoxWallCollidable>(position, size, *this);

    _components.push_back(collidable);
}

SolarFoxWall::~SolarFoxWall()
{
}

std::vector<solarfox::CollisionLayer> SolarFoxWall::getCollisionLayers() const
{
    return _collisionLayers;
}
