/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** ATextComponent
*/

#pragma once

#include "games/components/ITextComponent.hpp"
#include "abstracts/components/ADisplayableComponent.hpp"

using namespace shared::games;

class ATextComponent : public virtual components::ITextComponent,
                       public ADisplayableComponent {
    public:
        ATextComponent(
            shared::types::Vector2i position,
            shared::types::Vector2u size,
            entity::IEntity &entity,
            unsigned int zIndex,
            components::ITextComponent::TextProps &textProps);
        ~ATextComponent();

        components::ITextComponent::TextProps getTextProps() noexcept override;

    protected:
        components::ITextComponent::TextProps _textProps;
};
