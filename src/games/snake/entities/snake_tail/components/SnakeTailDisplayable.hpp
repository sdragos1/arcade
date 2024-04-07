/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SnakeTailDisplayable
*/

#pragma once

#include "games/components/ITextureComponent.hpp"

using namespace shared::games;

class SnakeTailDisplayable : public components::ITextureComponent {
    public:
<<<<<<< HEAD
        /**
         * @brief Construct a new Snake Tail Displayable object
         * @param entity
         */
        explicit SnakeTailDisplayable(const entity::IEntity &entity);

        /**
         * @brief Destroy a new Snake Tail Keyboard object
         */
        ~SnakeTailDisplayable();

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
        void onMousePress(std::shared_ptr<IGame> ctx) override;

        /**
         * @brief handle the mouse hover event
         * @param ctx
         * @return void
         */
        void onMouseHover(std::shared_ptr<IGame> ctx) override;

        /**
         * @brief handle the mouse release event
         * @param ctx
         * @return void
         */
        void onMouseRelease(std::shared_ptr<IGame> ctx) override;

        /**
         * @brief Set the Position object
         * @param pos
         * @return void
         */
        void setPosition(Vector2f pos) noexcept;

        /**
         * @brief Set the Old Position object
         * @param pos
         * @return void
         */
        void setOldPosition(Vector2f pos) noexcept;

        /**
         * @brief Get the Position object
         * @return Vector2f&
         */
        Vector2f &getPosition(void) noexcept override;

        /**
         * @brief Get the Old Position object
         * @return Vector2f&
         */
        Vector2f &getOldPosition(void) noexcept;

        Vector2f _position;
        Vector2f _oldPosition;
        components::TextureProps _textureProps;
=======
        explicit SnakeTailDisplayable(const entity::IEntity &entity);
        ~SnakeTailDisplayable();

        const components::ComponentType getType() const noexcept override;
        const entity::IEntity &getEntity() noexcept override;

        Vector2u &getSize(void) noexcept override;
        unsigned int &getZIndex(void) noexcept override;
        components::TextureProps &getTextureProps(void) noexcept override;
        void onMousePress(std::shared_ptr<IGame> &ctx) override;
        void onMouseHover(std::shared_ptr<IGame> &ctx) override;
        void onMouseRelease(std::shared_ptr<IGame> &ctx) override;

        Vector2i &getPosition(void) noexcept override;
        Vector2i _position;
>>>>>>> 0c77c95 (#15 feat: advancement on the snake tail implementation)

    private:
        const entity::IEntity &_entity;
        Vector2u _size;
        unsigned int _zIndex;
<<<<<<< HEAD
};
=======
        components::TextureProps _textureProps;
};
>>>>>>> 0c77c95 (#15 feat: advancement on the snake tail implementation)
