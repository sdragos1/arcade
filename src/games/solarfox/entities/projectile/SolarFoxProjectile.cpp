/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SolarFoxProjectile
*/

#include "SolarFoxProjectile.hpp"

SolarFoxProjectile::SolarFoxProjectile(ProjectileType type,
    shared::types::Vector2f position,
    shared::types::Vector2f direction)
    : _type(type), _direction(direction), _position(position),
     _startingPosition(position),
      _textureProps(
          type == PLAYER ? SolarFoxPlayerProjectileTextureProps
                         : SolarFoxEnemyProjectileTextureProps)
{
    std::shared_ptr<TextureComponent> texture = std::make_shared<TextureComponent>(
        _position,
        shared::types::Vector2u(1, 1),
        *this,
        0,
        _textureProps);
    texture->getTextureProps().origin = _getOriginFromDirection();

    _components.push_back(texture);
}

SolarFoxProjectile::~SolarFoxProjectile()
{
}

shared::types::Vector2f &SolarFoxProjectile::getDirection()
{
    return _direction;
}

shared::types::Vector2f &SolarFoxProjectile::getPosition()
{
    return _position;
}

shared::types::Vector2f &SolarFoxProjectile::getStartingPosition()
{
    return _startingPosition;
}

void SolarFoxProjectile::moveProjectile()
{
    for (auto &component : _components) {
        if (component->getType() == components::TEXTURE) {
            auto texture = std::dynamic_pointer_cast<TextureComponent>(component);
            if (_direction.x != 0) {
                std::cout << _direction.x << std::endl;
                texture->getPosition().x += _direction.x / 2;
            }
            if (_direction.y != 0) {
                std::cout << _direction.y / 2 << std::endl;
                texture->getPosition().y += _direction.y / 2;
            }
        }
    }
}

const SolarFoxProjectile::ProjectileType &SolarFoxProjectile::getType() const
{
    return _type;
}

shared::types::Vector2u SolarFoxProjectile::_getOriginFromDirection()
{
    shared::types::Vector2u origin = {0, 0};

    if (_direction.x == 1)
        origin.x = 3;
    else if (_direction.x == -1)
        origin.x = 1;
    else if (_direction.y == 1)
        origin.x = 2;
    else if (_direction.y == -1)
        origin.x = 0;
    return origin;
}

unsigned int SolarFoxProjectile::getProjectileTravelDistance()
{
    unsigned int distance = 0;

    for (auto &component : _components) {
        if (component->getType() == components::TEXTURE) {
            auto texture = std::dynamic_pointer_cast<TextureComponent>(component);
            if (_direction.x != 0)
                distance = std::abs(texture->getPosition().x - _startingPosition.x);
            else
                distance = std::abs(texture->getPosition().y - _startingPosition.y);
        }
    }
    return distance;
}
