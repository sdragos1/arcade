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
        /**
         * @brief Construct a new Snake Body Displayable object
         * @param entity
         * @param position
         */
        explicit SnakeBodyDisplayable(const entity::IEntity &entity, Vector2i position);

        /**
         * @brief Destroy a new Snake Body Displayable object
         */
        ~SnakeBodyDisplayable();

        /**
         * @brief Get the Type object
         * @return const components::ComponentType
         */
        const components::ComponentType getType() const noexcept override;

        /**
         * @brief Get the entity object
         * @return const entity::IEntity&
         */
        const entity::IEntity &getEntity() noexcept override;

        /**
         * @brief Get the Size object
         * @return const Vector2u&
         */
        Vector2u &getSize(void) noexcept override;

        /**
         * @brief Get the ZIndex object
         * @return unsigned int&
         */
        unsigned int &getZIndex(void) noexcept override;

        /**
         * @brief Get the TextureProps object
         * @return components::TextureProps&
         */
        components::TextureProps &getTextureProps(void) noexcept override;

        /**
         * @brief handle the mouse press event
         * @param ctx
         * @return void
         */
        void onMousePress(std::shared_ptr<IGame> &ctx) override;

        /**
         * @brief handle the mouse hover event
         * @param ctx
         * @return void
         */
        void onMouseHover(std::shared_ptr<IGame> &ctx) override;

        /**
         * @brief handle the mouse release event
         * @param ctx
         * @return void
         */
        void onMouseRelease(std::shared_ptr<IGame> &ctx) override;

        /**
         * @brief Set the Position object
         * @param pos
         * @return void
         */
        void setPosition(Vector2i pos) noexcept;

        /**
         * @brief Set the Old Position object
         * @param pos
         * @return void
         */
        void setOldPosition(Vector2i pos) noexcept;

        /**
         * @brief Get the Position object
         * @return Vector2i&
         */
        Vector2i &getPosition(void) noexcept override;

        /**
         * @brief Get the Old Position object
         * @return Vector2i&
         */
        Vector2i &getOldPosition(void) noexcept;
        Vector2i _position;
        Vector2i _oldPosition;
        components::TextureProps _textureProps;

    private:
        const entity::IEntity &_entity;
        Vector2u _size;
        unsigned int _zIndex;
};
#endif /* !SNAKEBODYDISPLAYABLE_HPP_ */
