/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** ATextureComponent
*/

#include "ATextureComponent.hpp"

ATextureComponent::ATextureComponent(
    shared::types::Vector2i position,
    shared::types::Vector2u size,
    entity::IEntity &entity,
    unsigned int zIndex,
    components::TextureProps &textureProps)
    : ADisplayableComponent(position, size, entity, zIndex, components::ComponentType::TEXTURE),
      _textureProps(textureProps)
{
}

ATextureComponent::~ATextureComponent()
{
}

components::TextureProps &ATextureComponent::getTextureProps() noexcept
{
    return _textureProps;
}
