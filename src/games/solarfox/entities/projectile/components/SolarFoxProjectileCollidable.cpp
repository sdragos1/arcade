/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SolarFoxProjectileCollidable
*/

#include "SolarFoxProjectileCollidable.hpp"

SolarFoxProjectileCollidable::SolarFoxProjectileCollidable(
    shared::types::Vector2f &position, entity::IEntity &entity, ProjectileType type)
    : ACollidableComponent(position, shared::types::Vector2u(1, 1), entity)
    , _destroyed(false)
    , _type(type)
{
}

SolarFoxProjectileCollidable::~SolarFoxProjectileCollidable()
{
}

void SolarFoxProjectileCollidable::onCollide(std::shared_ptr<IGame> ctx,
    std::shared_ptr<ICollidableComponent> target)
{
    auto targetProjectile = std::dynamic_pointer_cast<SolarFoxProjectileCollidable>(target);

    if (targetProjectile == nullptr)
        return;
    if (targetProjectile->getProjectileType() == ENEMY && _type == PLAYER) {
        _destroyed = true;
    } else if (targetProjectile->getProjectileType() == PLAYER && _type == ENEMY) {
        _destroyed = true;
    }
}

bool SolarFoxProjectileCollidable::isDestroyed() const
{
    return _destroyed;
}

ProjectileType SolarFoxProjectileCollidable::getProjectileType() const
{
    return _type;
}
