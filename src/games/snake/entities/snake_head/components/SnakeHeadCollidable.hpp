/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu]
** File description:
** SnakeHeadCollidable
*/

#ifndef SNAKEHEADCOLLIDABLE_HPP_
#define SNAKEHEADCOLLIDABLE_HPP_

#include "games/components/ICollidableComponent.hpp"

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

        /**
         * @brief On collide event handler for the component
         * @param ctx Context of the game
         * @param target Target entity
         */
        void onCollide(std::shared_ptr<shared::games::IGame> ctx, std::shared_ptr<shared::games::components::ICollidableComponent> target) override;

    private:
        const shared::games::entity::IEntity &_entity;
};

#endif /* !SnakeHeadCOLLIDABLE_HPP_ */