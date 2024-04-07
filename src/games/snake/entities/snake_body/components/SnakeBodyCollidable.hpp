/*
** EPITECH PROJECT, 2024
** arcade [WSL: Ubuntu]
** File description:
** SnakeBodyCollidable
*/

#ifndef SRC_GAMES_SNAKE_ENTITIES_SNAKE_BODY_COMPONENTS_SNAKEBODYCOLLIDABLE_HPP_
#define SRC_GAMES_SNAKE_ENTITIES_SNAKE_BODY_COMPONENTS_SNAKEBODYCOLLIDABLE_HPP_

#include "games/components/ICollidableComponent.hpp"
#include "games/components/IDisplayableComponent.hpp"

class SnakeBodyCollidable : public shared::games::components::ICollidableComponent {
    public:
        /**
         * @brief Construct a new SnakeBody Collidable object
         * @param entity
         */
        explicit SnakeBodyCollidable(const shared::games::entity::IEntity &entity,
            unsigned int id);

        /**
         * @brief Destroy the SnakeBody Collidable object
         */
        ~SnakeBodyCollidable();

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

        Vector2f &getPosition(void) noexcept override;

        Vector2u &getSize(void) noexcept override;

        unsigned int getId(void) noexcept;

        void setPosition(Vector2f pos) noexcept;

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
        unsigned int _id;
};

#endif  // SRC_GAMES_SNAKE_ENTITIES_SNAKE_BODY_COMPONENTS_SNAKEBODYCOLLIDABLE_HPP_
