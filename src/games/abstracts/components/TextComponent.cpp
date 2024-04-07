/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** TextComponent
*/

#include "TextComponent.hpp"

TextComponent::TextComponent(
    shared::types::Vector2f position,
    shared::types::Vector2u size,
    entity::IEntity &entity,
    unsigned int zIndex,
    components::ITextComponent::TextProps &textProps)
    : ADisplayableComponent(position, size, entity, zIndex, components::ComponentType::TEXT),
      _textProps(textProps)
{
}

TextComponent::~TextComponent()
{
}

components::ITextComponent::TextProps TextComponent::getTextProps() noexcept
{
    return _textProps;
}


void TextComponent::onMousePress(std::shared_ptr<IGame> ctx)
{
    (void)ctx;
}

void TextComponent::onMouseRelease(std::shared_ptr<IGame> ctx)
{
    (void)ctx;
}

void TextComponent::onMouseHover(std::shared_ptr<IGame> ctx)
{
    (void)ctx;
}

