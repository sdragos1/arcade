/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu]
** File description:
** SnakeHeadCollidable
*/

#ifndef SRC_GAMES_SNAKE_ENTITIES_SNAKE_HEAD_COMPONENTS_SNAKEHEADCOLLIDABLE_HPP_
#define SRC_GAMES_SNAKE_ENTITIES_SNAKE_HEAD_COMPONENTS_SNAKEHEADCOLLIDABLE_HPP_

#include <iostream>
#include "games/components/ICollidableComponent.hpp"
#include "games/components/IDisplayableComponent.hpp"
#include "../../snake_body/components/SnakeBodyCollidable.hpp"
#include "../../snake_tail/components/SnakeTailCollidable.hpp"

class SnakeHeadCollidable : public shared::games::components::ICollidableComponent {
    public:
        /**
         * @brief Construct a new SnakeHead Collidable object
         * @param entity
         */
        explicit SnakeHeadCollidable(const shared::games::entity::IEntity &entity);

        /**
         * @brief Destroy the SnakeHead Collidable object
         */
        ~SnakeHeadCollidable();

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

        void setPosition(Vector2f pos) noexcept;

        Vector2f &getPosition(void) noexcept override;

        Vector2u &getSize(void) noexcept override;

        bool getLose(void) noexcept;

        /**
         * @brief On collide event handler for the component
         * @param ctx Context of the game
         * @param target Target entity
         */
        void onCollide(std::shared_ptr<shared::games::IGame> ctx,
            std::shared_ptr<shared::games::components::ICollidableComponent> target) override;

    private:
        const shared::games::entity::IEntity &_entity;
        Vector2f _position;
        Vector2u _size;
        bool _lose;
};

#endif  // SRC_GAMES_SNAKE_ENTITIES_SNAKE_HEAD_COMPONENTS_SNAKEHEADCOLLIDABLE_HPP_
