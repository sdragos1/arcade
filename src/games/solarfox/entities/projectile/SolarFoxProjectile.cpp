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
    std::shared_ptr<SolarFoxProjectileCollidable> collidable =
        std::make_shared<SolarFoxProjectileCollidable>(_position, *this, _type);

    _components.push_back(texture);
    _components.push_back(collidable);
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
    Vector2f moveOffset = {_direction.x, _direction.y};

    if (_type == PLAYER) {
        moveOffset.x /= 2;
        moveOffset.y /= 2;
    }
    if (_type == ENEMY) {
        moveOffset.x /= 7;
        moveOffset.y /= 7;
    }
    for (auto &component : _components) {
        if (component->getType() == components::TEXTURE) {
            auto texture = std::dynamic_pointer_cast<TextureComponent>(component);
            if (_direction.x != 0) {
                texture->getPosition().x += moveOffset.x;
            }
            if (_direction.y != 0) {
                texture->getPosition().y += moveOffset.y;
            }
            _position = texture->getPosition();
        }
        if (component->getType() == components::COLLIDABLE) {
            auto collidable = std::dynamic_pointer_cast<SolarFoxProjectileCollidable>(component);
            collidable->getPosition() = _position;
        }
    }
}

const ProjectileType SolarFoxProjectile::getType() const
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

bool SolarFoxProjectile::isDestroyed() const
{
    for (auto &component : _components) {
        if (component->getType() == components::COLLIDABLE) {
            auto collidable = std::dynamic_pointer_cast<SolarFoxProjectileCollidable>(component);
            return collidable->isDestroyed();
        }
    }
    return false;
}
