/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** ACollidableComponent
*/

#include "ACollidableComponent.hpp"

ACollidableComponent::ACollidableComponent(
    shared::types::Vector2f position,
    shared::types::Vector2u size,
    entity::IEntity &entity)
    : PositionableComponent(position, size, entity, components::ComponentType::COLLIDABLE
    )
{
}

ACollidableComponent::~ACollidableComponent()
{
}
