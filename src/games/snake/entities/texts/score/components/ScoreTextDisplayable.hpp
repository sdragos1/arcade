/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** ScoreTextDisplayable
*/

#pragma once

#include "games/components/ITextComponent.hpp"

class ScoreTextDisplayable : public shared::games::components::ITextComponent {
    public:
        /**
         * @brief Construct a new Score Text Displayable object
         * @param content
         * @param entity
         */
        explicit ScoreTextDisplayable(const std::string &content,
             const shared::games::entity::IEntity &entity);

        /**
         * @brief Destroy the Score Text Displayable object
         */
        ~ScoreTextDisplayable();

        /**
         * @brief Get the Text Props object
         * @return shared::games::components::ITextComponent::TextProps
         */
        shared::games::components::ITextComponent::TextProps getTextProps() noexcept override;

        /**
         * @brief Get the Size object
         * @return const Vector2u&
         */
        Vector2u &getSize() noexcept override;

        /**
         * @brief Get the ZIndex object
         * @return unsigned int&
         */
        unsigned int &getZIndex() noexcept override;

        /**
         * @brief Get the Text object
         * @return const std::string&
         */
        void onMousePress(std::shared_ptr <shared::games::IGame> &ctx) override;

        /**
         * @brief Get the Text object
         * @return const std::string&
         */
        void onMouseRelease(std::shared_ptr <shared::games::IGame> &ctx) override;

        /**
         * @brief Get the Text object
         * @return const std::string&
         */
        void onMouseHover(std::shared_ptr <shared::games::IGame> &ctx) override;

        /**
         * @brief Get the Position object
         * @return const Vector2i&
         */
        Vector2i &getPosition(void) noexcept override;

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

    private:
        const std::string &_text;
        shared::games::components::ITextComponent::TextProps _props;
        Vector2u _size;
        unsigned int _zIndex;
        Vector2i _position;
        const shared::games::entity::IEntity &_entity;
};