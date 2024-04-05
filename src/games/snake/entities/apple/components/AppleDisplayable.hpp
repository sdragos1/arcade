/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu]
** File description:
** AppleDisplayable
*/

#ifndef APPLEDISPLAYABLE_HPP_
#define APPLEDISPLAYABLE_HPP_

#include "games/components/ITextureComponent.hpp"

class AppleDisplayable : public shared::games::components::ITextureComponent {
    public:

        /**
         * @brief Construct a new Apple Displayable object
         * @param entity
         */
        explicit AppleDisplayable(const shared::games::entity::IEntity &entity);

        /**
         * @brief Destroy the Apple Displayable object
         */
        ~AppleDisplayable();

        /**
         * @brief Get the Type object
         * @return const shared::games::components::ComponentType
         */
        const shared::games::components::ComponentType getType() const noexcept override;

        /**
         * @brief Get the entity object
         * @return const shared::games::entity::IEntity&
         */
        const shared::games::entity::IEntity &getEntity() noexcept override;

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
         * @return shared::games::components::TextureProps&
         */
        shared::games::components::TextureProps &getTextureProps(void) noexcept override;

        /**
         * @brief Handle the mouse press event
         * @param ctx
         */
        void onMousePress(std::shared_ptr<shared::games::IGame> ctx) override;

        /**
         * @brief Handle the mouse hover event
         * @param ctx
         */
        void onMouseHover(std::shared_ptr<shared::games::IGame> ctx) override;

        /**
         * @brief Handle the mouse release event
         * @param ctx
         */
        void onMouseRelease(std::shared_ptr<shared::games::IGame> ctx) override;

        /**
         * @brief Get the Position object
         * @return Vector2f&
         */
        Vector2f &getPosition(void) noexcept override;

        Vector2f _position;

    private:
        const shared::games::entity::IEntity &_entity;
        Vector2u _size;
        unsigned int _zIndex;
        shared::games::components::TextureProps _textureProps;
};

#endif /* !APPLEDISPLAYABLE_HPP_ */
