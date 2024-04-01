/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu]
** File description:
** SnakeBodyDisplayable
*/

#ifndef SNAKEBODYDISPLAYABLE_HPP_
#define SNAKEBODYDISPLAYABLE_HPP_

#include "games/components/ITextureComponent.hpp"

using namespace shared::games;

class SnakeBodyDisplayable : public components::ITextureComponent {
    public:
        explicit SnakeBodyDisplayable(const entity::IEntity &entity);
        ~SnakeBodyDisplayable();

        const components::ComponentType getType() const noexcept override;
        const entity::IEntity &getEntity() noexcept override;

        Vector2u &getSize(void) noexcept override;
        unsigned int &getZIndex(void) noexcept override;
        components::TextureProps &getTextureProps(void) noexcept override;
        void onMousePress(std::shared_ptr<IGame> &ctx) override;
        void onMouseHover(std::shared_ptr<IGame> &ctx) override;
        void onMouseRelease(std::shared_ptr<IGame> &ctx) override;

        void setPosition(Vector2i pos) noexcept;
        void setOldPosition(Vector2i pos) noexcept;

        Vector2i &getPosition(void) noexcept override;
        Vector2i &getOldPosition(void) noexcept;
        Vector2i _position;
        Vector2i _oldPosition;

    private:
        const entity::IEntity &_entity;
        Vector2u _size;
        unsigned int _zIndex;
        components::TextureProps _textureProps;
};
#endif /* !SNAKEBODYDISPLAYABLE_HPP_ */
