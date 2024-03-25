/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SnakeHeadDisplayable
*/

#pragma once

#include "games/components/IDisplayableComponent.hpp"

using namespace shared::games;

class SnakeHeadDisplayable : public components::IDisplayableComponent {
    public:
        SnakeHeadDisplayable(entity::IEntity &entity);
        ~SnakeHeadDisplayable();

        // IComponent
        const components::ComponentType getType() const noexcept override;
        const UUId &getId() const noexcept override;
        const entity::IEntity &getEntity() noexcept override;

        // DisplayableComponent
        Vector2u &getSize(void) noexcept override;
        unsigned int &getZIndex(void) noexcept override;
        components::TextureProps &getTextureProps(void) noexcept override;
        void onMousePress(std::shared_ptr<IGame> &ctx) override;
        void onMouseHover(std::shared_ptr<IGame> &ctx) override;
        void onMouseRelease(std::shared_ptr<IGame> &ctx) override;

        // Position
        Vector2i &getPosition(void) noexcept override;

        Vector2i _position;
    protected:
    private:
        UUId _id;
        entity::IEntity &_entity;
        Vector2u _size;
        unsigned int _zIndex;
        components::TextureProps _textureProps;
};
