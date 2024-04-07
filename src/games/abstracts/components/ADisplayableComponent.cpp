/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** ADisplayableComponent
*/

#include "ADisplayableComponent.hpp"

ADisplayableComponent::ADisplayableComponent(
    shared::types::Vector2f position,
            shared::types::Vector2u size, entity::IEntity &entity, unsigned int zIndex,
            components::ComponentType type = components::ComponentType::DISPLAYABLE)
    : PositionableComponent(position, size, entity, type),
        _zIndex(zIndex)
{
}

ADisplayableComponent::~ADisplayableComponent()
{
}

unsigned int &ADisplayableComponent::getZIndex() noexcept
{
    return _zIndex;
}
