/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** ASoundComponent
*/

#include "ASoundComponent.hpp"

ASoundComponent::ASoundComponent(const entity::IEntity &_entity, const std::string &path)
    : _path(path)
    , _state(components::SoundState::STOP)
    , _volume(100)
    , _loop(false)
    , _entity(_entity)
{
}

ASoundComponent::~ASoundComponent()
{
}

const std::string &ASoundComponent::getPath(void) const noexcept
{
    return _path;
}

components::SoundState &ASoundComponent::getState(void) noexcept
{
    return _state;
}

components::SoundVolume &ASoundComponent::getVolume(void) noexcept
{
    return _volume;
}

bool &ASoundComponent::getLoop(void) noexcept
{
    return _loop;
}

const components::ComponentType ASoundComponent::getType(void) const noexcept
{
    return components::ComponentType::SOUND;
}

const entity::IEntity &ASoundComponent::getEntity(void) noexcept
{
    return _entity;
}
