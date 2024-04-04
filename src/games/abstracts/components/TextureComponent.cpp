/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** TextureComponent
*/

#include "TextureComponent.hpp"

TextureComponent::TextureComponent(
    shared::types::Vector2i position,
    shared::types::Vector2u size,
    entity::IEntity &entity,
    unsigned int zIndex,
    components::TextureProps &textureProps)
    : ADisplayableComponent(position, size, entity, zIndex, components::ComponentType::TEXTURE),
      _textureProps(textureProps)
{
}

TextureComponent::~TextureComponent()
{
}

components::TextureProps &TextureComponent::getTextureProps() noexcept
{
    return _textureProps;
}

void TextureComponent::onMousePress(std::shared_ptr<IGame> ctx)
{
    (void)ctx;
}

void TextureComponent::onMouseRelease(std::shared_ptr<IGame> ctx)
{
    (void)ctx;
}

void TextureComponent::onMouseHover(std::shared_ptr<IGame> ctx)
{
    (void)ctx;
}
