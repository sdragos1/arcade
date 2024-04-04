/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SolarFoxPlayer
*/

#include "SolarFoxPlayer.hpp"

SolarFoxPlayer::SolarFoxPlayer()
{
    std::shared_ptr<components::IComponent> texture =
        std::make_shared<TextureComponent>(
            shared::types::Vector2i(5, 5),
            shared::types::Vector2u(5, 5),
            *this,
            0,
            SolarPlayerTextureProps);

    _components.push_back(texture);
}

SolarFoxPlayer::~SolarFoxPlayer()
{
}
