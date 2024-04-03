/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** ATextComponent
*/

#include "ATextComponent.hpp"

ATextComponent::ATextComponent(
    shared::types::Vector2i position,
    shared::types::Vector2u size,
    entity::IEntity &entity,
    unsigned int zIndex,
    components::ITextComponent::TextProps &textProps)
    : ADisplayableComponent(position, size, entity, zIndex, components::ComponentType::TEXT),
      _textProps(textProps)
{
}

ATextComponent::~ATextComponent()
{
}

components::ITextComponent::TextProps ATextComponent::getTextProps() noexcept
{
    return _textProps;
}
