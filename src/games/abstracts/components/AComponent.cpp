/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** AComponent
*/

#include "AComponent.hpp"

AComponent::AComponent(entity::IEntity &entity, components::ComponentType type)
    : _entity(entity), _type(type)
{
}

AComponent::~AComponent()
{
}

const components::ComponentType AComponent::getType() const noexcept
{
    return _type;
}

const entity::IEntity &AComponent::getEntity() noexcept
{
    return _entity;
}
