/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SolarFoxPowerup
*/

#include "SolarFoxPowerup.hpp"

SolarFoxPowerup::SolarFoxPowerup(Vector2f pos, PowerupType type)
    :_type(type)
{
    std::shared_ptr<TextureComponent> texture =
    std::make_shared<TextureComponent>(
        pos,
        shared::types::Vector2u(1, 1),
        *this,
        0,
        _type == GOOD ? SolarFoxPowerupTextureProps : SolarFoxPowerupBadTextureProps);
    std::shared_ptr<SolarFoxPowerupCollidable> collidable =
        std::make_shared<SolarFoxPowerupCollidable>(pos, *this, _type);

    _components.push_back(texture);
    _components.push_back(collidable);
}

SolarFoxPowerup::~SolarFoxPowerup()
{
    _components.clear();
}

PowerupType SolarFoxPowerup::getPowerupType() const
{
    return _type;
}
