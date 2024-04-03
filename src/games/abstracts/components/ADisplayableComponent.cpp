/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** ADisplayableComponent
*/

#include "ADisplayableComponent.hpp"

ADisplayableComponent::ADisplayableComponent(
    shared::types::Vector2i position,
            shared::types::Vector2u size, entity::IEntity &entity, unsigned int zIndex)
    : PositionableComponent(position, size, entity), _zIndex(zIndex)
{
}

ADisplayableComponent::~ADisplayableComponent()
{
}

unsigned int &ADisplayableComponent::getZIndex() noexcept
{
    return _zIndex;
}
