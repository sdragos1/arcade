/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** PositionableComponent
*/

#include "PositionableComponent.hpp"

PositionableComponent::PositionableComponent(shared::types::Vector2i position,
    shared::types::Vector2u size, entity::IEntity &entity,
        components::ComponentType type = components::ComponentType::POSITIONABLE)
    : AComponent(entity, type),
    _position(position), _size(size)
{
}

PositionableComponent::~PositionableComponent()
{
}

shared::types::Vector2i &PositionableComponent::getPosition() noexcept
{
    return _position;
}

shared::types::Vector2u &PositionableComponent::getSize() noexcept
{
    return _size;
}
