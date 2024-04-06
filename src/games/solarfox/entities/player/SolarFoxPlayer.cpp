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
            shared::types::Vector2f(5, 5),
            shared::types::Vector2u(1, 1),
            *this,
            0,
            SolarPlayerTextureProps);
    std::shared_ptr<components::IComponent> keyboard =
        std::make_shared<SolarFoxPlayerKeyboard>(*this);

    _components.push_back(texture);
    _components.push_back(keyboard);
}

SolarFoxPlayer::~SolarFoxPlayer()
{
}

bool SolarFoxPlayer::isShooting() const
{
    for (auto &component : _components) {
        if (component->getType() == components::ComponentType::KEYBOARD) {
            auto keyboard = std::dynamic_pointer_cast<SolarFoxPlayerKeyboard>(component);
            return keyboard->isShooting();
        }
    }
    return false;
}
