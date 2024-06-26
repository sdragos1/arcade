/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SolarFoxPowerupCollidable
*/

#include <iostream>
#include "SolarFoxPowerupCollidable.hpp"

SolarFoxPowerupCollidable::SolarFoxPowerupCollidable(shared::types::Vector2f position,
    entity::IEntity &entity, PowerupType type)
    : ACollidableComponent(position, shared::types::Vector2u(1, 1), entity)
    , _destroyed(false)
    , _type(type)
{
}

SolarFoxPowerupCollidable::~SolarFoxPowerupCollidable()
{
}

void SolarFoxPowerupCollidable::onCollide(std::shared_ptr<IGame> ctx,
    std::shared_ptr<ICollidableComponent> target)
{
    auto targetProjectile = dynamic_cast<SolarFoxProjectileCollidable *>(target.get());

    if (targetProjectile) {
        if (targetProjectile->getProjectileType() == PLAYER) {
            _destroyed = true;
        }
    }
}

bool SolarFoxPowerupCollidable::isDestroyed() const
{
    return _destroyed;
}

PowerupType SolarFoxPowerupCollidable::getPowerupType() const
{
    return _type;
}
