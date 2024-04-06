/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SnakeHeadSound
*/

#include "SnakeHeadSound.hpp"

SnakeHeadSound::SnakeHeadSound(const entity::IEntity &_entity, const std::string &path)
    : ASoundComponent(_entity, path)
{
}

SnakeHeadSound::~SnakeHeadSound()
{
}

void SnakeHeadSound::onStateChange(std::shared_ptr<IGame> ctx, components::SoundState state)
{
}
