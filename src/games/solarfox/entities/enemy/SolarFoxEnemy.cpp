/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SolarFoxEnemy
*/

#include "SolarFoxEnemy.hpp"

SolarFoxEnemy::SolarFoxEnemy(shared::types::Vector2f position, shared::types::Vector2u size,
    shared::types::Vector2u origin)
{
    std::shared_ptr<TextureComponent> texture = std::make_shared<TextureComponent>(
        position, size, *this, 0, SolarEnemyTextureProps);
    texture->getTextureProps().origin = origin;

    _components.push_back(texture);
}

SolarFoxEnemy::~SolarFoxEnemy()
{
}
