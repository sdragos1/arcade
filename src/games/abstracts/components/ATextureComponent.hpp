/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** ATextureComponent
*/

#pragma once

#include "games/components/ITextureComponent.hpp"
#include "abstracts/components/ADisplayableComponent.hpp"

using namespace shared::games;

class ATextureComponent : public components::ITextureComponent,
                          public ADisplayableComponent {
    public:
        ATextureComponent(shared::types::Vector2i position,
            shared::types::Vector2u size, entity::IEntity &entity, unsigned int zIndex,
            components::TextureProps &textureProps);
        ~ATextureComponent();

        components::TextureProps &getTextureProps() noexcept override;

    protected:
        components::TextureProps &_textureProps;
};
