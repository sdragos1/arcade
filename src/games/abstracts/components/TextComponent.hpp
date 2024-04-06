/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** TextComponent
*/

#pragma once

#include <iostream>
#include "games/components/ITextComponent.hpp"
#include "abstracts/components/ADisplayableComponent.hpp"

using namespace shared::games;

class TextComponent : public virtual components::ITextComponent,
                       public ADisplayableComponent {
    public:
        TextComponent(
            shared::types::Vector2f position,
            shared::types::Vector2u size,
            entity::IEntity &entity,
            unsigned int zIndex,
            components::ITextComponent::TextProps &textProps);
        ~TextComponent();

        components::ITextComponent::TextProps getTextProps() noexcept override;

        void onMousePress(std::shared_ptr<IGame> ctx) override;
        void onMouseRelease(std::shared_ptr<IGame> ctx) override;
        void onMouseHover(std::shared_ptr<IGame> ctx) override;
    protected:
        components::ITextComponent::TextProps &_textProps;
};
