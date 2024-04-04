/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu-22.04]
** File description:
** SnakeHeadKeyboard
*/

#pragma once

#include "games/components/IKeyboardComponent.hpp"
#include "games/components/IDisplayableComponent.hpp"
#include "SnakeHeadDisplayable.hpp"

using namespace shared::games;

class SnakeHeadKeyboard : public components::IKeyboardComponent {
    public:

        /**
         * @brief Enum for the direction of the snake
         */
        enum Direction {
            UP,
            DOWN,
            LEFT,
            RIGHT
        };

        /**
         * @brief Construct a new Snake Head Keyboard object
         * @param entity
         */
        explicit SnakeHeadKeyboard(const entity::IEntity &entity);

        /**
         * @brief Destroy a new Snake Head Keyboard object
         */
        ~SnakeHeadKeyboard();

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
         * @brief handle the key press event
         * @param ctx
         * @param keyData
         * @return void
         */
        void onKeyPress(std::shared_ptr<IGame> ctx, KeyData keyData) override;

        /**
         * @brief handle the key release event
         * @param ctx
         * @param key
         * @return void
         */
        void onKeyRelease(std::shared_ptr<IGame> ctx, KeyData key) override;

        Direction _direction;
    private:
        const entity::IEntity &_entity;
};