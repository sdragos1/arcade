/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SolarFoxEnemy
*/

#include "SolarFoxEnemy.hpp"
#include <iostream>

SolarFoxEnemy::SolarFoxEnemy(shared::types::Vector2f position, shared::types::Vector2u size,
    shared::types::Vector2u origin, shared::types::Vector2i direction)
    : _direction(direction)
{
    std::shared_ptr<TextureComponent> texture = std::make_shared<TextureComponent>(
        position, size, *this, 0, SolarEnemyTextureProps);
    texture->getTextureProps().origin = origin;

    _components.push_back(texture);
}

SolarFoxEnemy::~SolarFoxEnemy()
{
}

void SolarFoxEnemy::inverseDirection()
{
    _direction.x *= -1;
    _direction.y *= -1;
}

shared::types::Vector2i SolarFoxEnemy::getDirection() const
{
    return _direction;
}

void SolarFoxEnemy::move()
{
    std::shared_ptr<TextureComponent> displayable = nullptr;

    for (auto &component : _components) {
        if (component->getType() == components::TEXTURE) {
            displayable = std::dynamic_pointer_cast<TextureComponent>(component);
        }
    }
    if (displayable == nullptr)
        return;
    if (_direction.x != 0) {
        displayable->getPosition().y += static_cast<float>(_direction.x) / 4;
    }
    if (_direction.y != 0) {
        displayable->getPosition().x += static_cast<float>(_direction.y) / 4;
    }
}
