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

class TextureComponent : public virtual components::ITextureComponent,
                          public ADisplayableComponent {
    public:
        TextureComponent(shared::types::Vector2i position,
            shared::types::Vector2u size, entity::IEntity &entity, unsigned int zIndex,
            components::TextureProps &textureProps);
        ~TextureComponent();

        components::TextureProps &getTextureProps() noexcept override;

        void onMousePress(std::shared_ptr<IGame> ctx) override;
        void onMouseRelease(std::shared_ptr<IGame> ctx) override;
        void onMouseHover(std::shared_ptr<IGame> ctx) override;

    protected:
        components::TextureProps &_textureProps;
};
