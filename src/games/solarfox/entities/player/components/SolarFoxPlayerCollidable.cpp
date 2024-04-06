/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SolarFoxPlayerCollidable
*/

#include "SolarFoxPlayerCollidable.hpp"

SolarFoxPlayerCollidable::SolarFoxPlayerCollidable(shared::types::Vector2f &position,
    entity::IEntity &entity)
    : ACollidableComponent(position, shared::types::Vector2u(1, 1), entity)
    , _destroyed(false)
{
}

SolarFoxPlayerCollidable::~SolarFoxPlayerCollidable()
{
}

void SolarFoxPlayerCollidable::onCollide(std::shared_ptr<IGame> ctx,
    std::shared_ptr<ICollidableComponent> target)
{
    auto targetProjectile = std::dynamic_pointer_cast<SolarFoxProjectileCollidable>(target);

    if (targetProjectile == nullptr)
        return;
    if (targetProjectile->getProjectileType() == ENEMY) {
        _destroyed = true;
    }
}

bool SolarFoxPlayerCollidable::isDestroyed() const
{
    return _destroyed;
}

