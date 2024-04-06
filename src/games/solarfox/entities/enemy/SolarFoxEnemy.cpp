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
    : _direction(direction),
    _textureProps(
        components::TextureProps{
            .sources = {
                .ascii = "assets/games/solarfox/enemies/bonbon_sheet.ascii",
                .bin = "assets/games/solarfox/enemies/bonbon_sheet.png",
                .binTileSize = {16, 16},
            },
            .origin = origin,
        }),
    _shootingStage(0),
    _texture(nullptr)
{
    _texture = std::make_shared<TextureComponent>(
        position, size, *this, 0, _textureProps);

    _components.push_back(_texture);
}

SolarFoxEnemy::~SolarFoxEnemy()
{
    _components.clear();
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

void SolarFoxEnemy::incrementShootingStage()
{
    _shootingStage++;
    if (_shootingStage > 3)
        _shootingStage = 0;
    _texture->getTextureProps().origin.y = _shootingStage;
}

bool SolarFoxEnemy::isReadyToShoot()
{
    return _shootingStage == 3;
}
